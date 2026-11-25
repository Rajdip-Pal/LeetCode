
class Bid {
    constructor(
        public userId: number,
        public amount: number,
        public version: number
    ) { }
}

class AuctionSystem {
    private data = new Map<number, Map<number, Bid>>();
    private queues = new Map<number, MinPriorityQueue<Bid>>();

    private getQueue(itemId: number): MinPriorityQueue<Bid> {
        let queue = this.queues.get(itemId);

        if (!queue) {
            queue = new MinPriorityQueue<Bid>({
                compare: (a, b) =>
                    b.amount - a.amount ||
                    b.userId - a.userId
            });

            this.queues.set(itemId, queue);
        }

        return queue;
    }

    addBid(userId: number, itemId: number, bidAmount: number): void {
        let users = this.data.get(itemId);

        if (!users) {
            users = new Map();
            this.data.set(itemId, users);
        }

        const previous = users.get(userId);
        const version = (previous?.version ?? 0) + 1;

        const bid = new Bid(userId, bidAmount, version);

        users.set(userId, bid);
        this.getQueue(itemId).enqueue(bid);
    }

    updateBid(userId: number, itemId: number, newAmount: number): void {
        this.addBid(userId, itemId, newAmount);
    }

    removeBid(userId: number, itemId: number): void {
        const users = this.data.get(itemId)!;
        users.delete(userId);

        if (users.size === 0) {
            this.data.delete(itemId);
            this.queues.delete(itemId);
        }
    }

    getHighestBidder(itemId: number): number {
        const users = this.data.get(itemId);
        const queue = this.queues.get(itemId);

        if (!users || !queue) return -1;

        while (!queue.isEmpty()) {
            const top = queue.front()!;

            const current = users.get(top.userId);

            // Discard outdated or removed bids.
            if (
                !current ||
                current.version !== top.version
            ) {
                queue.dequeue();
                continue;
            }

            return top.userId;
        }

        return -1;
    }
}
