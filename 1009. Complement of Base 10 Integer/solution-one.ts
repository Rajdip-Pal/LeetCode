function bitwiseComplement(n: number): number {
    let binary = n.toString(2);
    let complement = Array(binary.length);
    for (let i = 0; i < binary.length; i++) complement[i] = binary[i] === '0' ? '1' : '0';
    return parseInt(complement.join(''), 2);
};
