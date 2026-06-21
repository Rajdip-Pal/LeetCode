function camelMatch(queries: string[], pattern: string): boolean[] {
    const match = (q: string, pattern: string): boolean => {
        let idx: number = 0;

        for (let i = 0; i < q.length; i++) {
            if (idx < pattern.length && q[i] === pattern[idx])
                idx++;
            else if (q[i] >= 'A' && q[i] <= 'Z')
                return false;
        }

        return idx === pattern.length;
    }

    return queries.map(q => match(q, pattern));
};