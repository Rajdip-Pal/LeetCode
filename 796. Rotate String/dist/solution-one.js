function rotateString(s, goal) {
    return s.length === goal.length && (s + s).includes(goal);
}
;
