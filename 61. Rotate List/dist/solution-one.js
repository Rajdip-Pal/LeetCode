var ListNode = /** @class */ (function () {
    function ListNode(val, next) {
        this.val = (val === undefined ? 0 : val);
        this.next = (next === undefined ? null : next);
    }
    return ListNode;
}());
function rotateRight(head, k) {
    if (!head)
        return head;
    var tmp = head;
    var len = 0;
    while (tmp) {
        len++;
        tmp = tmp.next;
    }
    ;
    var n = len;
    k %= n;
    if (k === 0)
        return head;
    var queue = new Array(k + 1);
    tmp = head;
    while (tmp) {
        queue.push(tmp);
        queue.shift();
        tmp = tmp.next;
    }
    queue[0].next = null;
    for (var i = 1; i < k; i++)
        queue[i].next = queue[i + 1];
    queue[k].next = head;
    return queue[1];
}
;
