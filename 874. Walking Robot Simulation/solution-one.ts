function robotSim(commands: number[], obstacles: number[][]): number {
    const obstacle_set: Set<string> = new Set(obstacles.map(o => `${o[0]} ${o[1]}`));
    const dirs: number[][] = [[0, 1], [1, 0], [0, -1], [-1, 0]];

    let maxDistanceSquare: number = 0;
    let curr: [number, number] = [0, 0];
    let angle = 0;

    for (const command of commands) {
        if (command === -2) angle = (angle + 3) % 4;
        else if (command === -1) angle = (angle + 1) % 4;
        else {
            for (let i = 0; i < command; i++) {
                const next: [number, number] = [curr[0] + dirs[angle][0], curr[1] + dirs[angle][1]];
                if (obstacle_set.has(`${next[0]} ${next[1]}`))
                    break;
                curr = next;
                maxDistanceSquare = Math.max(maxDistanceSquare, curr[0] * curr[0] + curr[1] * curr[1]);
            }
        }
    }

    return maxDistanceSquare;
}