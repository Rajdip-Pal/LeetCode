class ListNode {
    val: number
    next: ListNode | null
    constructor(val?: number, next?: ListNode | null) {
        this.val = (val === undefined ? 0 : val)
        this.next = (next === undefined ? null : next)
    }
}


class Solution {
    constructor(private head: ListNode | null) { }

    getRandom(): number {
        let result = 0;
        let i = 0;

        for (let node = this.head; node !== null; node = node.next) {
            i++;

            if (Math.floor(Math.random() * i) === 0) {
                result = node.val;
            }
        }

        return result;
    }
}
