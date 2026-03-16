function decodeMessage(key: string, message: string): string {

    const mp: Map<string, string> = new Map()
    let letter: number = 0
    const res: string[] = []

    mp.set(' ', ' ')
    for (let i = 0; i < key.length && letter < 26; i++) {
        if (!mp.has(key[i])) mp.set(key[i], String.fromCharCode('a'.charCodeAt(0) + letter++))
    }

    for (let i = 0; i < message.length; i++) {
        res.push(mp.get(message[i]) ?? '')
    }

    return res.join('')
};
