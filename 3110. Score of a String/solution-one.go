package main

func scoreOfString(s string) int {
	score := 0
	for i := 1; i < len(s); i++ {
		score += abs(int(s[i-1]) - int(s[i]))
	}
	return score
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func main() {
	str := "abc"
	println(int(str[0]))
	println(int(str[1]))
	println(int(str[2]))

	println(str[1] - str[0])
	println(str[0] - str[1])

	s := []byte(str)
	println(s[0])
	println(s[1])
	println(s[2])

	println(s[1] - s[0])
	println(s[0] - s[1])

	r := []rune(str)
	println(r[0])
	println(r[1])
	println(r[2])

	println(r[1] - r[0])
	println(r[0] - r[1])

}
