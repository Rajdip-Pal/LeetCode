class MyCalendar {

    private sessions: Array<[number, number]>;

    constructor() {
        this.sessions = new Array();
    }

    book(startTime: number, endTime: number): boolean {
        endTime = endTime - 1;

        if (this.sessions.length <= 0) {
            this.sessions.push([startTime, endTime]);
            return true;
        }

        let is_booked: boolean = false;
        let booking_position = -1;

        for (let i = 0; i < this.sessions.length; i++) {
            if (i === 0 && endTime < this.sessions[i][0]) {
                booking_position = 0;
                is_booked = true;
            }

            if (startTime > this.sessions[i][1]) {
                booking_position = i + 1;

                if (i < this.sessions.length - 1) {
                    if (endTime < this.sessions[i + 1][0]) {
                        is_booked = true;
                    }
                } else is_booked = true;
            }
        }

        if (is_booked) {
            this.sessions.splice(booking_position, 0, [startTime, endTime]);
        }

        return is_booked;
    }
}