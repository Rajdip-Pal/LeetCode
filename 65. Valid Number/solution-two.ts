enum State {
    START,
    SIGN,
    INTEGER,
    DOT,
    FRACTION,
    EXPONENT_MARK,
    EXPONENT_SIGN,
    EXPONENT_NUMBER
}

function isNumber(s: string): boolean {
    s = s.trim();
    let state = State.START;
    let i = 0;

    while (i < s.length) {
        const ch = s[i];

        switch (state) {
            case State.START:
                if (ch === '+' || ch === '-') state = State.SIGN;
                else if (isDigit(ch)) state = State.INTEGER;
                else if (ch === '.') state = State.DOT;
                else return false;
                break;

            case State.SIGN:
                if (isDigit(ch)) state = State.INTEGER;
                else if (ch === '.') state = State.DOT;
                else return false;
                break;

            case State.INTEGER:
                if (isDigit(ch)) { }
                else if (ch === '.') state = State.FRACTION; // normaly State.DOT, but we want to allow "123." as valid number
                else if (ch === 'e' || ch === 'E') state = State.EXPONENT_MARK;
                else return false;
                break;

            case State.DOT:
                if (isDigit(ch)) state = State.FRACTION;
                else return false;
                break;

            case State.FRACTION:
                if (isDigit(ch)) { }
                else if (ch === 'e' || ch === 'E') state = State.EXPONENT_MARK;
                else return false;
                break;

            case State.EXPONENT_MARK:
                if (ch === '+' || ch === '-') state = State.EXPONENT_SIGN;
                else if (isDigit(ch)) state = State.EXPONENT_NUMBER;
                else return false;
                break;

            case State.EXPONENT_SIGN:
                if (isDigit(ch)) state = State.EXPONENT_NUMBER;
                else return false;
                break;

            case State.EXPONENT_NUMBER:
                if (isDigit(ch)) { }
                else return false;
                break;
        }

        i++;
    }

    return (
        state === State.INTEGER ||
        state === State.FRACTION ||
        state === State.EXPONENT_NUMBER
    );
}

function isDigit(ch: string): boolean {
    return ch >= '0' && ch <= '9';
}
