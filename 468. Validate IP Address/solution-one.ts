function validIPAddress(queryIP: string): string {
    const octets = queryIP.split('.');
    const hextets = queryIP.split(':');

    function is_decimal(num: string) {
        const set = new Set("0123456789");
        for (const digit of num) {
            if (!set.has(digit))
                return false;
        }
        return true;
    }

    function is_valid_octet(octet: string): boolean {
        if ((octet.length > 3) || (octet.length < 1)) return false;
        if (octet.length > 1 && octet[0] === '0') return false;
        if (!is_decimal(octet)) return false;


        const value = Number(octet);
        if (Number.isNaN(value) || value < 0 || value > 255) return false;

        return true;
    }

    if (octets.length === 4) {
        for (const octet of octets)
            if (!is_valid_octet(octet))
                return "Neither";
        return "IPv4"
    }

    function is_hex(num: string) {
        const set = new Set("0123456789abcdefABCDEF");
        for (const digit of num) {
            if (!set.has(digit))
                return false;
        }
        return true;
    }

    function is_valid_hextet(hextet: string): boolean {
        if (hextet.length > 4 || hextet.length < 1) return false;
        if (!is_hex(hextet)) return false;

        const value = parseInt(hextet, 16);
        if (Number.isNaN(value) || value < 0 || value > ((1 << 16) - 1)) return false;

        return true;
    }

    if (hextets.length === 8) {
        for (const hextet of hextets)
            if (!is_valid_hextet(hextet))
                return "Neither";
        return "IPv6"
    }

    return "Neither";
};

console.log(Number(""))
console.log(parseInt("85hextet", 16))

console.log("1.0.1.".split('.'))

console.log("".length)