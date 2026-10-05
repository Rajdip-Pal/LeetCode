package main

func scoreOfParentheses(s string) int {
	depth := 0
	result := 0

	for i := 0; i < len(s); i++ {
		if s[i] == '(' {
			depth++
		} else {
			depth--
			if s[i-1] == '(' {
				result += 1 << depth
			}
		}
	}

	return result
}

func main() {

}
