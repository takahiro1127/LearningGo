#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

/* in microseconds (us) */
double get_elapsed_time(struct timeval *begin, struct timeval *end)
{
    return (end->tv_sec - begin->tv_sec) * 1000000
            + (end->tv_usec - begin->tv_usec);
}

void init(int xsize, int ysize, float *data)
{
  int x, y;
  int cx = xsize/2, cy = 0; /* center of ink */
  int rad = (xsize+ysize)/8; /* radius of ink */

  for(y = 0; y < ysize; y++) {
    for(x = 0; x < xsize; x++) {
      float v = 0.0;
      if (((x-cx)*(x-cx)+(y-cy)*(y-cy)) < rad*rad) {
        v = 1.0;
      }
      data[y * ysize + x] = v;
      data[xsize * ysize + ysize * y + x] = v;
    }
  }
  return;
}

/* Calculate for one time step */
/* Input: data[t%2], Output: data[(t+1)%2] */
void calc(int nt, int xsize, int ysize, float *data)
{
  int t, x, y;
  for (t = 0; t < nt; t++) {
    int from = t%2;
    int to = (t+1)%2;

#if 1
    printf("step %d\n", t);
    //fflush(0);
#endif
    #pragma acc data copy(data[0:xsize * ysize * 2])
    {
        #pragma acc kernels
        {
            #pragma acc loop independent
            for (y = 1; y < ysize-1; y++) {
            #pragma acc loop independent
                for (x = 1; x < xsize-1; x++) {
                    data[to * xsize * ysize + ysize * y + x] = 0.2 * (data[from * xsize * ysize + ysize * y + x]
                                + data[from * xsize * ysize + ysize * y + x - 1]
                                + data[from * xsize * ysize + ysize * y + x + 1]
                                + data[from * xsize * ysize + ysize * (y - 1) + x]
                                + data[from * xsize * ysize + ysize * (y + 1) + x]);
                }
            }
        }
    }
  }

  return;
}

int  main(int argc, char *argv[])
{
  struct timeval t1, t2;
  int nt = 20; /* number of time steps */
  
    if (argc < 3) {
        printf("Specify X, Y.\n");
        exit(1);
    }
    int xsize = atoi(argv[1]);
    int ysize = atoi(argv[2]);
    float *data = (float *)malloc(sizeof(float) * 2 * xsize * ysize);

  init(xsize, ysize, data);

  gettimeofday(&t1, NULL);

  calc(nt, xsize, ysize, data);

  gettimeofday(&t2, NULL);

  {
      double us;
      double gflops;
      int op_per_point = 5; // 4 add & 1 multiply per point

      us = get_elapsed_time(&t1, &t2);
      printf("Elapsed time: %.3lf sec\n", us/1000000.0);
      gflops = ((double)xsize*ysize*nt*op_per_point)/us/1000.0;
      printf("Speed: %.3lf GFlops\n", gflops);
  }

  return 0;
}
