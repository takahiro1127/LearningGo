package main
import (
	"encoding/csv"
	"io"
	"fmt"
	"strings"
)
// var csvSource = `111、２２２`
func main() {
	reader := strings.NewReader(csvSource)
	csvReader := csv.NewReader(reader)
	for {
		line, err := csvReader.Read()
		if err == io.EOF {
			break
		}
		fmt.Println(line[2], line[6:9])
	}
}
