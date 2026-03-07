function minFlips(s: string): number {
    if (s.length < 2) return 0

    const check = (bin: string, pattern: string): number => {
        let count: number = 0;

        let i: number = 0
        while (i < bin.length) {
            if (bin[i] !== pattern[i]) count++
            i++
        }

        return count
    }

    const get_min_diff = (bin: string, pattern: string, current_diff: number) => {
        let shift_idx: number = 0
        let min_diff: number = current_diff;

        while (shift_idx < s.length) {
            if (bin[shift_idx] !== pattern[shift_idx]) current_diff--
            if (bin[shift_idx] !== pattern[s.length + shift_idx]) current_diff++

            min_diff = Math.min(min_diff, current_diff)
            shift_idx++
        }

        return min_diff
    }

    const res = (pattern_template: string) => {
        const pattern = pattern_template.repeat(s.length)
        return get_min_diff(s, pattern, check(s, pattern))
    }


    return Math.min(res('01'), res('10'))
};
