class ListNode {
    val: number
    next: ListNode | null
    constructor(val?: number, next?: ListNode | null) {
        this.val = (val===undefined ? 0 : val)
        this.next = (next===undefined ? null : next)
    }
}
class Counter {
    private left: number;
    private right: number;
    private array: number[];
    constructor(left: number, right: number) {
        this.left = left;
        this.right = right;
        this.array = new Array(right - left + 1).fill(0);
    }
    put(n: number) { this.array[n - this.left]++; }
    get(n: number) { return this.array[n - this.left]; }
    print() {        console.log(this.array);}
}

function deleteDuplicates(head: ListNode | null): ListNode | null {
    if (!head) return null;

    const cnt = new Counter(-100, 100);

    let tmp: ListNode = head;
    while (tmp)        cnt.put(tmp.val); tmp = tmp.next;

    let res: ListNode = new ListNode();
    const res_head = res;
    tmp = head;

    while (tmp) {
        if (cnt.get(tmp.val) < 2) {
            res.next = new ListNode(tmp.val);
            res = res.next;
        }
        tmp = tmp.next;
    }

    return res_head.next;
};