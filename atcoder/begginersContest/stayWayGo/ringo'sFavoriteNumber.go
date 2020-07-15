package main
import "fmt"

func main() {
	var d, n int
	fmt.Scan(&d)
	fmt.Scan(&n)
  if (n == 100) {
		n++;
	}
  if (d == 0) {
      fmt.Println(n)
  }
  if (d == 1) {
      fmt.Println(n*100)
  }
  if (d == 2) {
      fmt.Println(n*10000)
  }
}
