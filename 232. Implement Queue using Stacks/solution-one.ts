class MyQueue<T extends any> {
    stack_a: T[];
    stack_b: T[];
    peek_elem: T | null;

    constructor() {
        this.stack_a = new Array();
        this.stack_b = new Array();
        this.peek_elem = null;
    }

    push(x: T): void {
        if (!this.peek_elem) this.peek_elem = x;
        this.stack_a.push(x);
    }

    pop(): T {
        while (this.stack_a.length - 1 > 0) {
            this.stack_b.push(this.stack_a.pop()!);
        }

        const res = this.stack_a.pop()!;

        if (this.stack_b.length) {
            this.peek_elem = this.stack_b.pop()!;
            this.stack_a.push(this.peek_elem);
            while (this.stack_b.length > 0) {
                this.stack_a.push(this.stack_b.pop()!);
            }
        } else {
            this.peek_elem = null;
        }

        return res;
    }

    peek(): T {
        return this.peek_elem!;
    }

    empty(): boolean {
        return this.stack_a.length === 0;
    }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * var obj = new MyQueue()
 * obj.push(x)
 * var param_2 = obj.pop()
 * var param_3 = obj.peek()
 * var param_4 = obj.empty()
 */

const s = new Number();