function checkString(s: string): boolean {
    let is_b_started: boolean = false;

    for (let i = 0; i < s.length; i++) {
        if (s.charAt(i) === 'a' && is_b_started) return false;
        if (s.charAt(i) === 'b') is_b_started = true;
    }

    return true;
};