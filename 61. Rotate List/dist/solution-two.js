var ListNode = /** @class */ (function () {
    function ListNode(val, next) {
        this.val = (val === undefined ? 0 : val);
        this.next = (next === undefined ? null : next);
    }
    return ListNode;
}());
function rotateRight(head, k) {
    if (!head || k === 0)
        return head;
    var tmp = head;
    var len = 1;
    while (tmp.next) {
        len++;
        tmp = tmp.next;
    }
    ;
    var n = len;
    k %= n;
    if (k === 0)
        return head;
    tmp.next = head;
    var newTailAt = n - 1 - k;
    tmp = head;
    var i = 0;
    while (i++ < newTailAt)
        tmp = tmp.next;
    var ans = tmp.next;
    tmp.next = null;
    return ans;
}
;
