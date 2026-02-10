package main

func uniquePaths(m int, n int) int {
	if m > n {
		m, n = n, m
	}

	var total_paths float64 = 1

	for i := 1; i < m; i++ {
		total_paths = total_paths * float64(n-1+i) / float64(i)
	}

	return int(total_paths)
}

func main() {
	println(uniquePaths(5, 5))
}
