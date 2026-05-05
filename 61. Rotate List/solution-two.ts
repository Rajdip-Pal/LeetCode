class ListNode {
    val: number
    next: ListNode | null
    constructor(val?: number, next?: ListNode | null) {
        this.val = (val === undefined ? 0 : val)
        this.next = (next === undefined ? null : next)
    }
}


function rotateRight(head: ListNode | null, k: number): ListNode | null {
    if (!head || k === 0) return head;

    let tmp: ListNode = head;
    let len: number = 1;
    while (tmp.next) { len++; tmp = tmp.next; };

    const n = len;
    k %= n;

    if (k === 0) return head;

    tmp.next = head;
    const newTailAt = n - 1 - k;

    tmp = head;
    let i: number = 0;

    while (i++ < newTailAt)
        tmp = tmp.next!;

    const ans = tmp.next;
    tmp.next = null;

    return ans;
};