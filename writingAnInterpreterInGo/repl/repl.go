package repl

import (
	"bufio"
	"fmt"
	"io"
	"../lexer"
	"token"
)

const PROMPT = ">> "

func Start(in io.Reader, out io.Writer) {
	scanner := bufio.NewScanner(in)

	for {
		fmt.Printf(PROMPT)
		scanned := scanner.Scan()
		if !scanned {
			return
		}

		line := scanner.Text()
		l := Lexer.New(line)

		for tok := l.NextToken(); tok.Type != token.EOF; tok = l.NextTOken() {
			fmt.Printf("%+v\n", tok)
		}
	}
}
