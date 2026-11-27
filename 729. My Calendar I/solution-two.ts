/**
 * if in compare(a,b) -> a > b return +ve ; 
 */
const lower_bound = <T extends unknown, K extends unknown>(arr: T[], target: K, compare: (a: T, b: K) => number): number => {
    let l = 0, r = arr.length;

    while (l < r) {
        const mid = l + ((r - l) >>> 1);
        const cmp = compare(arr[mid], target);

        if (cmp < 0) l = mid + 1;
        else r = mid;
    }

    return l;
}

class MyCalendar {
    private sessions: Array<[number, number]>;

    constructor() {
        this.sessions = [[-Infinity, -Infinity], [Infinity, Infinity]];
    }

    book(startTime: number, endTime: number): boolean {
        endTime = endTime - 1;

        const booking_position = lower_bound(this.sessions, startTime, (a, b) => a[1] - b);
        const is_booked = endTime < this.sessions[booking_position][0];

        if (is_booked) this.sessions.splice(booking_position, 0, [startTime, endTime]);

        return is_booked;
    }
}