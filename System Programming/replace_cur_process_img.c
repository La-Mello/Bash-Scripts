/**
	How to replace current process image using execl()

	# Arguments
	execl(PATH,COMMAND,ANY_OPTIONS|NULL);
**/
#include<stdio.h>
#include<unistd.h>

int main(){

	printf("Before execl();\n");

	//when control reaches here the whole process is replaced with the ls command
//	execl("/bin/ls","ls","-l",NULL);

//	execl("/bin/pwd","pwd",NULL);

	printf("Current process PID:<%d>\n",getpid());
	//to confirm that no new process is created but rather the running process is replaced
	//the pid of the ps command will be same as of the current process
	execl("/bin/ps","ps",NULL);//runs the ps command

	//never printed because the process'image was replaced
	printf("After execl();");
return 0;
}
