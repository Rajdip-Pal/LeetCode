const lower_bound = <T, K>(arr: T[], target: K, compare: (a: T, b: K) => number): number => {
    let l = 0, r = arr.length;

    while (l < r) {
        const mid = l + ((r - l) >>> 1);
        const cmp = compare(arr[mid], target);

        if (cmp < 0) l = mid + 1;
        else r = mid;
    }

    return l;
}

const upper_bound = <T, K>(arr: T[], target: K, compare: (a: T, b: K) => number): number => {
    let l = 0, r = arr.length;

    while (l < r) {
        const mid = l + ((r - l) >>> 1);
        const cmp = compare(arr[mid], target);

        if (cmp <= 0) l = mid + 1;
        else r = mid;
    }

    return l;
}

class TweetCounts {
    private tweets: Record<string, Array<number>>;

    constructor() {
        this.tweets = {};
    }

    recordTweet(tweetName: string, time: number): void {
        if (!this.tweets[tweetName]) this.tweets[tweetName] = [time];
        else {
            const index = upper_bound(this.tweets[tweetName], time, (a, b) => a - b);
            this.tweets[tweetName].splice(index, 0, time);
        }
    }

    getTweetCountsPerFrequency(freq: string, tweetName: string, startTime: number, endTime: number): number[] {
        const gap: number = freq === 'minute' ? 60 - 1 : (freq === 'hour' ? 60 * 60 - 1 : 60 * 60 * 24 - 1);
        const tweet_list = this.tweets[tweetName];

        const res: number[] = [];
        while (startTime <= endTime) {
            const start = lower_bound(tweet_list, startTime, (a, b) => a - b);
            const end = upper_bound(tweet_list, Math.min(startTime + gap, endTime), (a, b) => a - b);

            res.push(end - start);
            startTime += gap + 1;
        }

        return res;
    }
}