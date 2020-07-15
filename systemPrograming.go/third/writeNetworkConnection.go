package main
import (
	"bufio"
	"net/http"
	"io"
	"os"
	"net"
	"fmt"
)

func main() {
	conn, err := net.Dial("tcp", "ascii.jp:80")
	if err != nil {
		panic(err)
	}
	conn.Write([]byte("GET / HTTP/1.0\r\nHost: ascii.jp\r\n\r\n"))
	res, err := http.ReadResponse(bufio.NewReader(conn), nil)

	fmt.Println(res.Header)
	defer res.Body.Close()
	io.Copy(os.Stdout, res.Body)
	// io.Copy(os.Stdout, conn)
}
