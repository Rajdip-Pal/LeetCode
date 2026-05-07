class ListNode {
    val: number
    next: ListNode | null
    constructor(val?: number, next?: ListNode | null) {
        this.val = (val === undefined ? 0 : val)
        this.next = (next === undefined ? null : next)
    }
}


function rotateRight(head: ListNode | null, k: number): ListNode | null {
    if (!head) return head;

    let tmp: ListNode | null = head;
    let len: number = 0;
    while (tmp) { len++; tmp = tmp.next; };

    const n = len;
    k %= n;

    if (k === 0) return head;

    const queue = new Array<ListNode>(k + 1);

    tmp = head;
    while (tmp) {
        queue.push(tmp);
        queue.shift();
        tmp = tmp.next;
    }

    queue[0].next = null;
    for (let i = 1; i < k; i++)
        queue[i].next = queue[i + 1];

    queue[k].next = head;

    return queue[1];
};