
/**
	Program to simulate the race condition
	occurs when a common shared resource is accessed simultaneously

	Depending on which thread runs first the final value is either 0 or 2 always

#Note	Must include the sleep function to allow the threads to run simultaneously

*/

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<pthread.h>

//shared resource
int shared = 1;

void *fun1();
void *fun2();

int main(){

	pthread_t thr1,thr2;

	pthread_create(&thr1,NULL,fun2,NULL);
	pthread_create(&thr2,NULL,fun1,NULL);

	pthread_join(thr1,NULL);
	pthread_join(thr2,NULL);

	printf("Final shared value is : %d\n",shared);

return 0;

}

void *fun1(){

	printf("\tThread 1\n");

	int val = shared;

	printf("THR1: Shared recieved as : %d\n",val);

	//local increment
	val +=1;
	printf("THR1: Updated local Shared recieved as : %d\n",val);

	sleep(1);//allowing thread 2 to access shared

	shared = val;

	printf("THR1: updated Shared as : %d\n",shared);

	pthread_exit("Thread 1 finished");
}


void *fun2(){

	printf("\tThread 2\n");

	int val = shared;

        printf("THR2: Shared recieved as : %d\n",val);

        //local increment
        val -=1;

        printf("THR2: Updated local Shared recieved as : %d\n",val);

        sleep(1);//allowing thread 1 to access shared

        shared = val;

        printf("THR2: updated Shared as : %d\n",shared);

        pthread_exit("Thread 2 finished");

}
