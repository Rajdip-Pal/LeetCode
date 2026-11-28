function maximumSaleItems(items: number[][], budget: number): number {
    const n = items.length;
    const dp = new Array(budget + 1).fill(0);

    const minPrice = Math.min(...items.map(item => item[1]));

    for (let i = 0; i < n; i++) {
        const [factor, price] = items[i];

        let gain = 1;

        for (let j = 0; j < n; j++) {
            if (i !== j && items[j][0] % factor === 0) {
                gain++;
            }
        }

        for (let j = budget; j >= price; j--) {
            dp[j] = Math.max(
                dp[j],
                dp[j - price] + gain
            );
        }
    }

    let answer = 0;

    for (let spent = 0; spent <= budget; spent++) {
        answer = Math.max(
            answer,
            dp[spent] + Math.floor((budget - spent) / minPrice)
        );
    }

    return answer;
}