#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc,char *argv[]){
int fd_in,fd_out;
int size;
char buf[2048];

fd_in=open(argv[1],O_RDONLY);
fd_out=open(argv[2],O_WRONLY|O_CREAT,00600);

if(fd_in ==-1){
    printf("open input failed.\n");
    return 0;
}
if(fd_out ==-1){
    printf("open output failed.\n");
    return 0;
}
while(size=read(fd_in,buf,1024)){
    write(fd_out,buf,size);
}
close(fd_in);
close(fd_out);
return 0;
}