function isItPossible(word1: string, word2: string): boolean {

    class Frequency {
        private distinct_chars: number
        private freq: number[]

        constructor(w: string = "") {
            this.distinct_chars = 0
            this.freq = Array.from({ length: 26 }, () => 0)

            for (const e of w) this.put(e)
        }

        private static charidx(x: string): number { return Frequency.ascii(x) - Frequency.ascii('a') }
        private static ascii(x: string): number { return x.charCodeAt(0) }

        put(x: string) {
            const i: number = Frequency.charidx(x)
            this.freq[i]++
            if (this.freq[i] === 1) this.distinct_chars++
        }

        distinct() {
            return this.distinct_chars
        }

        isUniqueChar(x: string) { return this.freq[Frequency.charidx(x)] === 1 }
        isMultipleChar(x: string) { return this.freq[Frequency.charidx(x)] >= 1 }

        print() {
            console.debug(this.freq)
        }
    }

    const w1: Frequency = new Frequency(word1)
    const w2: Frequency = new Frequency(word2)

    if (Math.abs(w1.distinct() - w2.distinct()) > 2) return false
    if (!Math.abs(w1.distinct() - w2.distinct())) return true





    return false
};

console.log(
    isItPossible("abc", "abc")
)
