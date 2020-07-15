#include<iostream>
using namespace std;
int n;
long int m;
int a[100000];
int euclid(int , int);
int divisor(int[], int);
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int j;
        cin >> j;
        a[i] = j / 2;
    }
    int c = divisor(a, n);
    cout << m / c - 2 << endl;
}

int euclid(int a, int b){
  int aa = a, bb = b; /* 元の値を保存する */
  int r = 1; /* 適当な0でない値に初期化する */
  int temp;
  if(b > a){
    temp = b;
    b = a;
    a = temp;
  }
  
  while(r!= 0){
    r = a % b;
    a = b;
    b = r;
  }
  
  return aa / a * bb; /* 最小公倍数を計算して返す */
}

int divisor(int s[], int x){

  int i;
  int r;
  if (x <= 0) return -1; /* サイズが0以下の配列は考えられない */
  if (x == 1) return s[0]; /* サイズが1の配列に対しては、その最初の要素の値をそのまま返す */
  for(i = 0; i <= x-2; i++){
   r =  euclid(s[i], s[i+1]);
   s[i+1] = r;
  }
  return r;
}
