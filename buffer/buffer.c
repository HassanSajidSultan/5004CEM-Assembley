#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#define BUF_SIZE 500
#define OUTPUT_MODE 0700

int main(int argc, char *argv[])
{
  int in_fd, out_fd;
  int rd_size = 1, wr_size;
  char buf[BUF_SIZE];
  int ccount;
  int bufcount = -1;
  int wordcount;
  int loopcount = 0;

  if (argc != 3){ 
    printf("Number Of Arguments Are Invalid!");
    exit(1);
  }
  in_fd = open(argv[1], O_RDONLY);
  if (in_fd < 0) {
     printf("File Not Found!");
    exit(2);
  }
  out_fd = creat(argv[2], OUTPUT_MODE);
  if (out_fd < 0) {
    printf("Cannot Create File!");
    exit(3);
  }

  while (rd_size > 0) {
    bufcount = bufcount + 1;
    rd_size = read(in_fd, buf, BUF_SIZE);
    ccount +=rd_size;
    for(loopcount = 0; loopcount < rd_size; loopcount++){
      if(buf[loopcount] == ' '){
        wordcount = wordcount + 1;
      }

    }
    if (rd_size <0) {
       printf("Finished Reading From File!");
      exit(4);
    }
    wr_size = write(out_fd, buf, rd_size);
    if (wr_size<=0){
       printf("Character Count: %d\n",ccount);
       printf("Word Count: %d\n",wordcount);
		  close(in_fd);
      close(out_fd);
    printf("Finished Reading And Writing!");
exit(5);
}
  }
}

