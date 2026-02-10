package main

func convertTemperature(celsius float64) []float64 {
	return []float64{celsius + 273.15, (celsius*9)/5 + 32.00}
}
