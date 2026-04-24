function judgeCircle(moves: string): boolean {
    let point: { x: number, y: number } = { x: 0, y: 0 };

    for (const move of moves) {
        switch (move) {
            case 'U':
                point.y++; break;
            case 'D':
                point.y--; break;
            case 'R':
                point.x++; break;
            case 'L':
                point.x--; break;
        }
    }

    return point.x === 0 && point.y === 0;
};