/***
*	 A program to demonstrate the shared memory system calls
*	 used to allocate a shared memory to different processes which in turn allows inter process communication


	## Headers
		<sys/ipc.h>
		<sys/shm.h>

	## Functions

	shmget()
		-> used to create the shared memory segment

	shmat()
		-> used to attach to the shared segment with the adress space of the process

	## Syntax
		int shmget(key_t key, size_t size, int shmflg)
		  #Params
			key -> unique identifier of the shared segment
			size -> size of segment in bytes
			shmflg -> permisions on the segment

		# Returns
			-> a valid identifier to be used to attach to the segment


		void *shmat(int shmid, const void * shmaddr, int shmflg);
		  #Params
			shmid -> return of the shmget()/id of the shared memory
			shmaddr -> where to attach in the shared segment/NULL system to choose suitable place to attach
			shmflg ->0


	//Sender program
		-create the shared segment
		-attach to it
		-write some content to shared segment

	//reciever
		-attach to shared segment
		-read values

*/

#include<stdio.h>
#include <unistd.h>

int main(){



return 0;
}


