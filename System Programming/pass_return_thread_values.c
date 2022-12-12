/***
* A program to demonstrate how to pass and ruturn values from a thread

* # A thread is a part of a process
   it exists within a process

* # Header <unistd.h> <pthread.h>

* declaration 
	pthread_t thread;

* to create use pthread_create(thread reference,NULL,thread function,null)
	# parameters :
		the memory adress of the thread
		attributes associated with the thread<NULL>
		the thread function
		input to the thread function<NULL>

* pthread_join(thread reference,NULL)//makes process to wait  for thread to finish
	# parameters :
		the thread variable
		where to store the retun value of the thread function if any exists

	#in this program the thread will print (0-9) and  main method (20-24)


	# TO COMPILE USE THE lpthread library
		i.e. gcc Thread.c -lpthread
*/


#include<stdio.h>
#include<sys/types.h>
#include<pthread.h>
#include<unistd.h>

//implicit declaration of the thread function
void *thread_function(void *arg);

//loop variables
int i,j;

int main(){


	//thread declaration
	pthread_t thread_a;

	//creation of thread
	pthread_create(&thread_a,NULL,thread_function,NULL);

	//join method to make process wait for thread to finish first
	pthread_join(thread_a,NULL);

	printf("\tInside main\n");
	for(j=20;j<25;j++){
		printf("%d\n",j);
		sleep(1);//delays output by one sec
	}
//	printf("\n");
return 0;
}

/**
*	the work to be done by the thread is done in here
*/
void *thread_function(void *arg){
	printf("\tInside Thread\n");
	for(i=0;i<10;i++){
		printf("%d\n",i);
		sleep(1);//delays output by one sec
	}
//	printf("\n");
}
