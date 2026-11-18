class MyCircularQueue {
    private items: Array<number>;
    private start: number;
    private end: number;
    private size: number;
    readonly capacity: number;

    constructor(k: number) {
        this.capacity = k;
        this.items = new Array(this.capacity);
        this.start = 0;
        this.end = -1;
        this.size = 0;
    }

    enQueue(value: number): boolean {
        if (this.isFull()) return false;
        this.items[this.end = (this.end + 1) % this.capacity] = value;
        this.size++;
        return true;
    }

    deQueue(): boolean {
        if (this.isEmpty()) return false;
        this.start = (this.start + 1) % this.capacity;
        this.size--;
        return true;
    }

    Front(): number {
        if (this.isEmpty()) return -1;
        return this.items[this.start];
    }

    Rear(): number {
        if (this.isEmpty()) return -1;
        return this.items[this.end];
    }

    isEmpty(): boolean {
        return this.size === 0;
    }

    isFull(): boolean {
        return this.size === this.capacity;
    }
}

const k = 3, value = 100;;;

var obj = new MyCircularQueue(k)
var param_1 = obj.enQueue(value)
var param_2 = obj.deQueue()
var param_3 = obj.Front()
var param_4 = obj.Rear()
var param_5 = obj.isEmpty()
var param_6 = obj.isFull()

console.log(
    param_1, param_2, param_3, param_4, param_5, param_6
)
