package main
import (
	"io"
	"bytes"
	"os"
)

func main() {
	header := bytes.NewBufferString("----- HEADER -----")
	content := bytes.NewBufferString("Example of io.MultiReader\n")
	footer := bytes.NewBufferString("----- FOOTER -----")

	reader := io.MultiReader(header, content, footer)
	io.Copy(os.Stdout, reader)
}
