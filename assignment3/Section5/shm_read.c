#include<fcntl.h>
#include<sys/mman.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>

#define mx 100

int main(int argc, char *argv[]){
	int fd, fd1;
	int buff[mx];
	struct stat len;
	char *addr;

	fd = shm_open("/shm_1",O_RDONLY, 0);
	if(fd==-1){
		perror("Error while openig shared memory\n");
		exit(1);
	}

	fstat(fd, &len);

	addr = mmap(NULL, len.st_size, PROT_READ, MAP_SHARED, fd, 0);

	fd1 = open("output.txt", O_WRONLY | O_CREAT, S_IRWXU);

	if(fd1==-1){
		perror("Error while opening/creating output file\n");
		exit(1);
	}

	write(fd1,addr,mx);	

	printf("Read data from shared memory - %s\n",addr);

	return 0;
}
