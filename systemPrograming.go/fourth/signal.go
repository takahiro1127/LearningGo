package main
import (
	"fmt"
	"os"
	"os/signal"
	"syscall"
)

func main() {
	signals := make(chan os.Signal, 1)
	signal.Notify(signals, syscall.SIGINT)
	fmt.Println("Waiting SIGINT (CTR + C")
	<- signals
	fmt.Println("SIGINT arrived")
}
