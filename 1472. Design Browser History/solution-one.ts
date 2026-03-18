class DListNode {
    data: string
    prev: DListNode | null
    next: DListNode | null

    constructor(data: string, prev: DListNode | null = null, next: DListNode | null = null) {
        this.data = data
        this.prev = prev
        this.next = next
    }

}


class BrowserHistory {
    private tail: DListNode
    private curr: DListNode

    constructor(homepage: string) {
        this.tail = new DListNode(homepage)
        this.curr = this.tail
    }

    visit(url: string): void {
        this.tail = this.curr
        this.tail.next = new DListNode(url, this.tail)
        this.tail = this.tail.next
        this.curr = this.tail
    }

    back(steps: number): string {
        while (steps-- && this.curr.prev != null)
            this.curr = this.curr.prev

        return this.curr.data
    }

    forward(steps: number): string {
        while (steps-- && this.curr.next != null)
            this.curr = this.curr.next

        return this.curr.data
    }
}

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * var obj = new BrowserHistory(homepage)
 * obj.visit(url)
 * var param_2 = obj.back(steps)
 * var param_3 = obj.forward(steps)
 */
