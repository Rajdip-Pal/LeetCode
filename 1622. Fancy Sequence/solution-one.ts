class Fancy {
    private data: bigint[]
    private a: bigint
    private invA: bigint
    private b: bigint
    private inverseCache: Map<bigint, bigint>
    private modulo: Readonly<bigint> = BigInt(1e9 + 7)

    constructor() {
        this.data = []
        this.a = 1n
        this.invA = 1n
        this.b = 0n
        this.inverseCache = new Map()
        this.inverseCache.set(1n, 1n)
    }

    append(val: number) {
        const normalized = (((BigInt(val) - this.b + this.modulo) % this.modulo) * this.invA) % this.modulo
        this.data.push(normalized)
        return this
    }

    addAll(inc: number) {
        this.b = ((this.b + BigInt(inc)) % this.modulo)
        return this
    }

    multAll(m: number) {
        const multiplier = BigInt(m)

        this.a = (this.a * multiplier) % this.modulo
        this.b = (this.b * multiplier) % this.modulo
        this.invA = (this.invA * this.modInverse(multiplier)) % this.modulo

        return this
    }

    getIndex(idx: number): number {
        return idx < this.data.length ? Number(((this.a * this.data[idx]) % this.modulo + (this.b)) % this.modulo) : -1
    }

    private modPow(base: bigint, exponent: bigint): bigint {
        let result = 1n
        let currentBase = base % this.modulo
        let currentExponent = exponent

        while (currentExponent > 0n) {
            if ((currentExponent & 1n) === 1n) {
                result = (result * currentBase) % this.modulo
            }

            currentBase = (currentBase * currentBase) % this.modulo
            currentExponent >>= 1n
        }

        return result
    }

    private modInverse(value: bigint): bigint {
        const normalizedValue = ((value % this.modulo) + this.modulo) % this.modulo

        const cachedValue = this.inverseCache.get(normalizedValue)
        if (cachedValue !== undefined) {
            return cachedValue
        }

        const inverse = this.modPow(normalizedValue, this.modulo - 2n)
        this.inverseCache.set(normalizedValue, inverse)

        return inverse
    }
}


// Your Fancy object will be instantiated and called as such:

// [ "multAll", "getIndex", "multAll", "append", "append", "append", "multAll", "getIndex", "append", "multAll", "multAll", "addAll", "multAll", "multAll", "multAll", "getIndex", "append", "append", "addAll", "getIndex", "getIndex", "multAll", "getIndex", "getIndex", "getIndex"]
// [ [8], [6], [7], [3], [6], [7], [4], [3], [3], [7], [3], [6], [10], [8], [8], [5], [7], [7], [3], [4], [0], [5], [0], [4], [7]]

const obj = new Fancy()
obj.append(3).multAll(10).append(3).multAll(2)
console.log(obj.getIndex(1))
obj.multAll(8)
console.log(obj.getIndex(6))
obj.multAll(7).append(3).append(6).append(7).multAll(4)
console.log(obj.getIndex(3))


/**
 * aL , bL = till last
 * a0 , b0 = for the element
 * aI , bI = before the append
 *
 *
 * [2,3,4,5,6,7,9] -> [aI,bI]
 *
 * append(95)
 *
 * will stack in future
 *
 * aL = aI * a0
 * bL = bI * a0 + b0
 *
 */
