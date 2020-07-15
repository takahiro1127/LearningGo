#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <cuda.h>
#include <cuda_runtime.h>

#define NX 8192
#define NY 8192

float data[2][NY][NX];

/* in microseconds (us) */
double get_elapsed_time(struct timeval *begin, struct timeval *end)
{
    return (end->tv_sec - begin->tv_sec) * 1000000
            + (end->tv_usec - begin->tv_usec);
}

void init()
{
  int x, y;
  int cx = NX/2, cy = 0; /* center of ink */
  int rad = (NX+NY)/8; /* radius of ink */

  for(y = 0; y < NY; y++) {
    for(x = 0; x < NX; x++) {
      float v = 0.0;
      if (((x-cx)*(x-cx)+(y-cy)*(y-cy)) < rad*rad) {
	v = 1.0;
      }
      data[0][y][x] = v;
      data[1][y][x] = v;
    }
  }
  return;
}

__global__ void calcXY(int from, to) {
    //yのループを呼び出す
    int startx = threadIdx.x * 32 - 1;
    int y = blockIdx.y;
    int x;
    for (x = startx; x < startx + 32; x++) {
        if (x == 8191 || y == 8191 || x == 0 || y == 0) {
            continue;
        }
        data[to][y][x] = 0.2 * (data[from][y][x]
                    + data[from][y][x-1]
                    + data[from][y][x+1]
                    + data[from][y-1][x]
                    + data[from][y+1][x]);
    }
}

/* Calculate for one time step */
/* Input: data[t%2], Output: data[(t+1)%2] */
void calc(int nt)
{
  int t;
//dataのコピーをgpuに作成
  cudaMalloc(data);
  for (t = 0; t < nt; t++) {
    int from = t%2;
    int to = (t+1)%2;

#if 1
    printf("step %d\n", t);
    //fflush(0);
#endif
    //並列でcalcXYを呼ぶ
    //1スレッドに対して、y一列計算する→xがいらなくなる
    calcXY<<<8192, 32<<<(from, to);
  }

  return;
}

int  main(int argc, char *argv[])
{
  struct timeval t1, t2;
  int nt = 20; /* number of time steps */
  
  if (argc >= 2) { /* if an argument is specified */
      nt = atoi(argv[1]);
  }

  init();

  gettimeofday(&t1, NULL);

  calc(nt);

  gettimeofday(&t2, NULL);

  {
      double us;
      double gflops;
      int op_per_point = 5; // 4 add & 1 multiply per point

      us = get_elapsed_time(&t1, &t2);
      printf("Elapsed time: %.3lf sec\n", us/1000000.0);
      gflops = ((double)NX*NY*nt*op_per_point)/us/1000.0;
      printf("Speed: %.3lf GFlops\n", gflops);
  }

  return 0;
}
