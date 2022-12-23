/**

				A PROGRAM ILLUSTRATING THE CONCEPT OF NAMED PIPES

				uses a single file but containing two inter communicating processes


				the child writes data to pipe and parent recieves data



*/



#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<sys/wait.h>

int main(){



	//create named pipe
	int res=mkfifo("fifo1",0777);
	int fd,n;
	char buf[50];

//	if(res == 0)
	printf("[%d] : Pipe created \n",res);//on first run res will be 0 but after creation it will be -1

	int pid;

	//create child process 
	pid=fork();

	if(pid == 0){//child

		printf("Process [%d]: Writting data .... \n",getpid());

		fd = open("fifo1",O_WRONLY);//opening pipe

		write(fd,"Hello world\n",12);//writting to pipe

	}else if(pid > 0){//parent

		sleep(3);

		printf("Process [%d]: Recieving data ..... \n",getpid());

		fd=open("fifo1",O_RDONLY);//opening pipe

		n= read(fd,buf,40);//reading from pipe

		write(1,buf,n);//writting to stdout
	}

	printf("[::] Done\n");

return 0;
}
