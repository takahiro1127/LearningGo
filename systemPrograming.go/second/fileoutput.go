package main

import (
	"os"
)

func main() {
	file, err := os.Create("test.text")
	if err != nil {
		panic(err)
	}
	file.Write([]byte("os.File example\n"))
	file.Close()
}
