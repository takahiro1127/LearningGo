package main

import (
	"bufio"
	"fmt"
	"net"
	"net/http"
	"net/http/httputil"
)

func main() {
	sendMessages := []string{
		"ASCII",
		"PROGRAMING",
		"PLUS",
	}
	current := 0
	var conn net.Conn = nil
	var err error

	requests := make(chan *http.Request, len(sendMessages))

	conn, err = net.Dial("tcp", "localhost:8888")
	if err != nil {
		panic(err)
	}
	fmt.Printf("Access: %d\n", current)
	defer conn.Close()

	for i := 0; i < len(sendMessages); i++ {
		lastMessege := i == len(sendMessages) - 1
		request, err := http.NewRequest(
			"GET",
			"http://localhost:8888?mmessage=" + sendMessages[i],
			nil,
		)
		if lastMessege {
			request.Header.Add("Conection", "close")
		} else {
			request.Header.Add("Connection", "keep-alive")
		}
		if err != nil {
			panic(err)
		}
		err = request.Write(conn)
		if err != nil {
			panic(err)
		}
		fmt.Println("send: ", sendMessages[i])
		requests <- request
	}
	close(requests)

	reader := bufio.NewReader(conn)
	for request := range requests {
		responsem err := http.ReadResponse(reader, request)
		if err != nil {
			panic(err)
		}
		dump, err := httputil.DumpResponse(response, true)
		if err != nil {
			panic(err)
		}
		fmt.Println(srtring(dump))
		if current == len(sendMessages) [
			break
		]
	}
}
