/**
	How to replace current process image using execl()

	Replacing child process code with execl();

	# Arguments
	execl(PATH,COMMAND,ANY_OPTIONS|NULL);
**/
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/wait.h>

int main(){

	printf("Before execl() and fork()\n");

	pid_t pid;

	pid=fork();

	if(pid == 0){//child process
		printf("Child process PID : <%d>\tParent PID : <%d>\n",getpid(),getppid());
		//to confirm that no new process is created but rather the running process is replaced
		//the pid of the ps command will be same as of the current process
		execl("/bin/ps","ps",NULL);//runs the ps command
	}else{
		//parent process
		wait(NULL);//waits for child to finish first
		printf("Parent process PID : <%d>\tCHILD PID : <%d>\n",getpid(),pid);
	}
return 0;
}
