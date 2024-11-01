package main

import (
	"fmt"
	"log"
)

func main() {
	var input string
	var borze string

	_, err := fmt.Scanln(&input)
	if err != nil {
		log.Fatal(err)
	}

	for i := 0; i < len(input); i++ {
		if input[i] == '.' {
			borze += "0"
		} else if input[i] == '-' {
			if i+1 < len(input) && input[i+1] == '.' {
				borze += "1"
			} else if i+1 < len(input) && input[i+1] == '-' {
				borze += "2"
			}
			i++ // Skip the next character to avoid re-reading.
		}
	}
	fmt.Println(borze)
}
