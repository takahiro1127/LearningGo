package main

import (
	"bufio"
	"fmt"
	"io/ioutil"
	"net"
	"net/http"
	"net/http/httputil"
	"os"
	"path/filepath"
	"strings"
)

func main() {
	path := filepath.Join(os.TempDir(), "unixdomainsocket-sample")
	os.Remove(path)
	listener, err := net.Listen("unix", path)
	if err != nil {
		panic(err)
	}

	defer listener.Close()
	fmt.Println("Server is runnning at " + path)
	for {
		conn,err := listener.Accept()
		if err != nil {
			panic(err)
		}
		go func () {
			fmt.Printf("Accept %v\n", conn.RemoteAddr())
			request
		}
	}
}


listener, err := net.Listen("unix", "socketfile")
if err != nil {
	panic (err)
}
defer listener.Close()
conn, err := listener.Accept()
if err != nil {

}
