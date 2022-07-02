#include<fcntl.h>
#include<sys/mman.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>

#define mx 100

int main(int argc, char *argv[]){
	int fd, fd1;
	int buff[mx];
	size_t len = 200;
	char *addr;
	ssize_t readbytes;

	fd = shm_open("/shm_1",O_RDWR | O_CREAT, 0660);
	if(fd==-1){
		perror("Error while openig shared memory\n");
		exit(1);
	}
	
	if(ftruncate(fd,len)==-1){
		perror("Error while resizing\n");
		exit(1);
	}

	addr = mmap(NULL, len, PROT_READ | PROT_WRITE, 	MAP_SHARED, fd, 0);

	if(close(fd)==-1){
		perror("Error while closing\n");
		exit(1);
	}

	fd1 = open("input.txt", O_RDONLY | O_CREAT, S_IRWXU);
	if(fd1==-1){
		perror("Error while opening input file");
		exit(1);
	}

	while(readbytes = read(fd1,buff,mx)){
		memcpy(addr,buff,readbytes);
	}

	//memcpy(addr, argv[1],len);

	return 0;
}
