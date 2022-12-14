/***
* A program to demonstrate how to pass and return values from a thread

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

* pthread_exit("")
	used to return anything from the thread to the main
*/


#include<stdio.h>
#include<sys/types.h>
#include<pthread.h>
#include<unistd.h>

//implicit declaration of the thread function
void *thread_function(void *arg);

//integer array to find sum for
int nums[2]={1,2};

//loop variables
int i,j;

void *returnv;

int main(){


	//thread declaration
	pthread_t thread_a;

	//creation of thread-->we pass the pointer to the array but typecast it to a void pointer
	pthread_create(&thread_a,NULL,thread_function,(void *)nums);

	//join method to make process wait for thread to finish first
	//store the result of the thread function in sum by passing in the reference of it
	pthread_join(thread_a,&returnv);

	printf("\tInside main\n");
	printf("Returned value : %s\n",(char *)returnv);
return 0;
}

/**
*	the work to be done by the thread is done in here
*/
void *thread_function(void *arg){
	printf("\tInside Thread\n");
	//recieve argument and  cast it to a integer pointer
	int *x=arg;

	//CALCULATE SUM
	int val = x[0] + x[1];

	printf("Sum is %d\n",val);

	pthread_exit("sum calculated");//exits running thread with a message
//	pthread_exit((void *)val);
}
