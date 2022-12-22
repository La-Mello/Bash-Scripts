/**
		HOW TO PREVENT RACE CONDITION

	Using mutex locks


	pthread_mutex_t -> type of mutex/declaration
	pthread_mutex_t m;

	pthread_mutex_init() -> initializes the mutex variables
		   -> Takes three params
			#1. &m adress of mutex variable
			#2. attributes for the mutex lock(default NULL)

	pthread_mutex_init(&m,NULL);

	pthread_mutex_lock(&m);//locks the process entering the critical section
	pthread_mutex_unlock(&m);//unlocks the process in its critical section and releases the mutex variable


	#
*/

#include<pthread.h>
#include<stdio.h>
#include<unistd.h>

void *func1();
void *func2();

int shared =1;//shared resource

pthread_mutex_t mut;//mutex declaration

int main(){

	pthread_mutex_init(&mut,NULL);//mutex initialization

	pthread_t thr1,thr2;

	pthread_create(&thr1,NULL,func1,NULL);
	pthread_create(&thr2,NULL,func2,NULL);


	pthread_join(thr1,NULL);
	pthread_join(thr2,NULL);

	printf("Final value is %d\n",shared);

return 0;

}


void *func1(){
	int x;

	printf("Thr1 : Trying to acquire lock\n");

	pthread_mutex_lock(&mut);

	printf("Thr1 : Lock acquired\n");

	//!critical section x=shared;
	printf("Thr1: reads shared as %d\n",x);
	x++;
	printf("Thr1: after local update %d\n",x);
	sleep(1);
	shared=x;
	printf("Thr1 : Updated shared value as %d\n",shared);
        //!exit critical section

	pthread_mutex_unlock(&mut);
	printf("Thr1 : released lock\n");
}

void *func2(){
	int x;

	printf("Thr2 : Trying to acquire lock\n");

        pthread_mutex_lock(&mut);

        printf("Thr2 : Lock acquired\n");

        //!critical section
        x=shared;
        printf("Thr2: reads shared as %d\n",x);
        x--;
        printf("Thr2: after local update %d\n",x);
        sleep(1);
        shared=x;
        printf("Thr2 : Updated shared value as %d\n",shared);
        //!exit critical section

        pthread_mutex_unlock(&mut);
        printf("Thr2 : released lock\n");
}
