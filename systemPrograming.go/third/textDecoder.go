package main
import (
	"bufio"
	"io"
	"fmt"
	"strings"
)

var source = `一行目
二行目
さん行目`

func main() {
	reader := bufio.NewReader(strings.NewReader(source))
	for {
		line, err := reader.ReadString('\n')
		fmt.Println("%#v\n", line)
		if err == io.EOF {
			break
		}
	}
}
