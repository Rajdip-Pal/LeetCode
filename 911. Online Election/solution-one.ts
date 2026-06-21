function lowerBound(nums: number[], target: number): number {
    let left = 0, right = nums.length - 1;
    while (left < right) {
        const mid = left + ((right - left) >>> 1);
        if (nums[mid] <= target)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

class TopVotedCandidate {
    private persons: number[];
    private times: number[];
    private leading: number[];

    constructor(persons: readonly number[], times: readonly number[]) {
        this.persons = Array.from(persons);
        this.times = Array.from(times);
        this.leading = new Array(this.times.length);

        const votes: number[] = new Array(this.persons.length).fill(0);
        let leader: number = -1, maxVotes: number = 0;

        for (let i = 0; i < this.times.length; i++) {
            votes[this.persons[i]]++;
            if (votes[this.persons[i]] >= maxVotes) {
                maxVotes = votes[this.persons[i]];
                leader = this.persons[i];
            }
            this.leading[i] = leader;
        }
    }

    q(t: number): number {
        const idx = lowerBound(this.times, t);
        if (this.times[idx] > t)
            return this.leading[idx - 1];
        return this.leading[idx];
    }
}