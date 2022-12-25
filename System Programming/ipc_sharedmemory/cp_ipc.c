#include<sys/shm.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<string.h>
#include<stdio.h>
#include<wait.h>


int main(){


	pid_t pid;

	int shmid = shmget((key_t)1122,1000,0666|IPC_CREAT);//create segment

	printf("Segment with id [%d] created\n",shmid);

	char send[30],rcv[30];

	void *p_shared_memory;
	void *c_shared_memory;

	//create a child process
	pid=fork();

	if(pid == 0){//child
		sleep(10);

		printf("Child Process Id [%d]\n",getpid());

		c_shared_memory = shmat(shmid,NULL,0);

		printf("Attached to adress [%p] Segment  Id : [%d]\n",c_shared_memory,shmid);

		strcpy(rcv,c_shared_memory);

		printf("Retrieval successful : \n");

		write(1,rcv,30);


	}
	else{//parent

		printf("Parent Process Id[%d]\n",getpid());

		if(shmid<=0)write(2,"Error creating segment\n",23);

		printf("Attaching to segment...\t");

		p_shared_memory=shmat(shmid,NULL,0);

		printf("[successful]\n");

		printf("Attached to adress [%p] segment id [%d]\n",p_shared_memory,shmid);

		read(0,send,30);

		strcpy(p_shared_memory,send);

		printf("Written successfully..\n");

		wait(NULL);

	}

return 0;

}
