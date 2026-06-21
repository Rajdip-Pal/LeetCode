// function upperBound<T>(nums: MapIterator<T>, target: number): number {
//     let left = 0, right = ;
//     while (left < right) {
//         const mid = left + ((right - left) >>> 1);
//         if (nums[mid] <= target)
//             left = mid + 1;
//         else
//             right = mid;
//     }
//     return left;
// }

class Value {
    private timestamp: number;
    private value: string;

    constructor(timestamp: number, value: string) {
        this.timestamp = timestamp;
        this.value = value;
    }

    get Timestamp(): number {
        return this.timestamp;
    }

    get Value(): string {
        return this.value;
    }

    set Value(value: string) {
        this.value = value;
    }
}

class TimeMap {

    private m: Map<string, Value[]>;

    constructor() {
        this.m = new Map();
    }

    set(key: string, value: string, timestamp: number): void {
        if (!this.m.has(key)) { this.m.set(key, []); }
        this.m.get(key)!.push(new Value(timestamp, value));
    }

    get(key: string, timestamp: number): string {
        if (!this.m.has(key))
            return "";
        else {
            console.log(this.m.get(key)!.map((v) => [v.Timestamp, v.Value]));
            return ""
        }
    }
}

const n: TimeMap = new TimeMap();

n.set("ab", "bc1", 1);
n.set("ab", "bc2", 11);
n.set("ab", "bc3", 16);
n.set("ab", "bc4", 19);
n.set("ab", "bc5", 15);
n.set("ab", "bc6", 13);
n.set("ab", "bc7", 12);

n.get("ab", 20);

/**
 * Your TimeMap object will be instantiated and called as such:
 * var obj = new TimeMap()
 * obj.set(key,value,timestamp)
 * var param_2 = obj.get(key,timestamp)
 */