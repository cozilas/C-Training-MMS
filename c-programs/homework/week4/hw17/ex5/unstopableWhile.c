#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <time.h>
#include <string.h>

void closed(int s){
	printf("i cant be closed");
}

int main(int argc, char *argv[])
{
    signal(SIGUSR1,closed);
  while(1){
         printf("mms camp\n");
     sleep(2);
  }
  return 0;
}
