package main
import (
	"strings"
	"fmt"
)

func main() {
	var builder strings.Builder
	builder.Write([]byte("strings.Builder example\n"))
	fmt.Println(builder.String())
}
