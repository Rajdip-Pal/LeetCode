class AuctionSystem {
    private data: Map<number, Map<number, number>>;
    private winners: Map<number, number>;

    constructor() {
        this.data = new Map();
        this.winners = new Map();
    }

    private getItem(itemId: number): Map<number, number> {
        const item = this.data.get(itemId);

        if (item === undefined) this.data.set(itemId, new Map());
        else return item;

        return this.data.get(itemId)!;
    }

    public addBid(userId: number, itemId: number, bidAmount: number): void {
        this.getItem(itemId).set(userId, bidAmount);
    }

    public updateBid(userId: number, itemId: number, newAmount: number): void {
        this.addBid(userId, itemId, newAmount);
    }

    public removeBid(userId: number, itemId: number): void {
        this.getItem(itemId).delete(userId);
    }

    public getHighestBidder(itemId: number): number {
        const item = this.getItem(itemId);

        let winner: number = -1, maxBid: number = -Infinity;

        for (const [user, bid] of item) {
            if (bid >= maxBid) {
                winner = user;
                maxBid = bid;
            }
        }

        return winner;
    }
}