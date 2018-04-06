#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BLOCKSIZ 8192
#define NUMOFBLK 1048576
#define LIMIT 100

typedef struct data_chain {
  void *ptr_data;
  void *ptr_next;
} data_chain_t;


int main( int argc, char *argv[] )
{
  int i,j,limit,wait;
  float sz;

  data_chain_t *top = malloc(sizeof(data_chain_t));
  data_chain_t *cur, *prv;

  if (argc < 3) {
    limit = LIMIT;
    wait = 1;
  } else {
    limit = atoi(argv[1]);
    wait = atoi(argv[2]);
  }
    
  top->ptr_next = NULL;
  top->ptr_data = NULL;
  cur = top;

  // メモリ取得ループ
  for(j=0,i=1; i < NUMOFBLK; i++) {

    if ((i % 1000) == 0) {
      printf("%6d  %5.1f MB\n",i, sz);
      sleep(wait);
    }

    cur->ptr_next = malloc(sizeof(data_chain_t));
    if (cur->ptr_next == NULL) {
      printf("Malloc Error at ptr_next");
      exit(1);
    }

    j++;
    cur->ptr_data = malloc(BLOCKSIZ);
    if (cur->ptr_data == NULL) {
      printf("Malloc Error at ptr_data");
      exit(1);
    }
    memset(cur->ptr_data, 0, BLOCKSIZ);
    sz = (float)j*(BLOCKSIZ+sizeof(data_chain_t))/1024/1024;

    if (limit < sz) {
      break;
    }

    cur = cur->ptr_next;
   }


  // メモリ解放ループ
  for(i=1,cur=top; cur != NULL;i++) {
    if ((i % 1000) == 0) {
      printf("%6d  %5.1f MB\n",i, (float)j*(BLOCKSIZ+sizeof(data_chain_t))/1024/1024);
      sleep(wait);
    }

    free(cur->ptr_data);
    prv = cur;
    cur = cur->ptr_next;
    free(prv);
    j--;
  }

  return(0);
}
