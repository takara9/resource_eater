#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BLOCKSIZ 1048576*5  // ブロックサイズ 5MBi
#define NUMOFBLK 100      // デフォルトは100MBi

typedef struct data_chain {
  void *ptr_data;
  void *ptr_next;
} data_chain_t;


int main( int argc, char *argv[] )
{
  int i,limit,wait;

  data_chain_t *top = malloc(sizeof(data_chain_t));
  data_chain_t *cur;

  if (argc < 3) {
    limit = NUMOFBLK;
    wait = 1;
  } else {
    limit = atoi(argv[1]);
    wait = atoi(argv[2]);
  }
    
  top->ptr_next = NULL;
  top->ptr_data = NULL;
  cur = top;

  // メモリ取得ループ
  for(i=1; i < (limit+1); i++) {

    cur->ptr_next = malloc(sizeof(data_chain_t));
    if (cur->ptr_next == NULL) {
      printf("Malloc Error at ptr_next");
      exit(1);
    }

    cur->ptr_data = malloc(BLOCKSIZ);
    if (cur->ptr_data == NULL) {
      printf("Malloc Error at ptr_data");
      exit(1);
    }
    memset(cur->ptr_data, 0, BLOCKSIZ);
    cur = cur->ptr_next;

    printf("%6d  %5.1f MB\n",i, (float)i*BLOCKSIZ/BLOCKSIZ);
    sleep(wait);
  }

  for(;;) {
    sleep(60);
  }

  return(0);
}
