
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <setjmp.h>
#include <math.h>

int f;

void signal_handler (int x)
{
  f = 1;
  return;
}


int main (int argc, char ** argv)
{
  int busy = atoi(argv[1]);
  int wait = 1000 - busy;
  if (wait < 0) wait = 0;
  printf("busy = %d\n",busy);
  printf("wait = %d\n",wait);
  struct sigaction act;
  act.sa_handler = signal_handler;
  sigaction (SIGALRM, &act, 0);
  while(1) {
    ualarm (busy, 0);
    for(f = 0;f==1;) {
      int n = 0;
      for(int j = 0;j < 10000;j++) {
	n++;
      }
    }
    if (wait > 0) {
      ualarm (wait, 0);
      sleep(1);
    }
  }
  return 0;
}

