function maximumTime(time: string): string {
    let [hour, minute] = time.split(":");

    if (minute === "??") minute = "59";
    else {
        if (minute.charAt(0) === '?'.charAt(0)) minute = '5' + minute.slice(1);
        if (minute.charAt(1) === '?'.charAt(0)) minute = minute.slice(0, -1) + '9';
    }

    if (hour === "??") hour = "23"
    else {
        if (hour.charAt(0) === '?'.charAt(0)) hour = (Number(hour.charAt(1)) <= 3 ? '2' : "1") + hour.slice(1);
        if (hour.charAt(1) === '?'.charAt(0)) hour = hour.slice(0, -1) + (hour.charAt(0) === '2'.charAt(0) ? '3' : '9');
    }

    return hour + ":" + minute;
};