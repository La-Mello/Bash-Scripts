/**
		HOW TO PREVENT RACE CONDITION

	Using semaphores


	sem_t -> type of semaphore/declaration
	sem_t s;

	sem_init() -> initializes the semaphore variables
		   -> Takes three args
			#1. &s adress of semaphore variable
			#2. Takes: 0(semaphore shared b2n threads) Nonzero(semaphore shared b2n processes)
			#3. initial value of semaphore variable(1 semaphore is free, 0 semaphore is being used)
	sem_init(&s,0,1);

	sem_wait() <=> almost similar to the wait() function
		   -> checks if the requested resource is free
		   -> decrements the value of the semaphore variable allowing the program to enter the critical section

	sem_post -> works like signal method
		 -> increments the value of the semaphore variable


	# Concept is using wait before the critical section and post after the critical section
*/

#include<pthread.h>
#include<stdio.h>
#include<semaphore.h>
#include<unistd.h>

void *func1();
void *func2();

int shared =1;//shared resource

sem_t sem;//semaphore declaration

int main(){

	sem_init(&sem,0,1);//semaphore initialization

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
	sem_wait(&sem);

	//!critical section
	x=shared;
	printf("Thr1: reads shared as %d\n",x);
	x++;
	printf("Thr1: after local update %d\n",x);
	sleep(1);
	shared=x;
	printf("Thr1 : Updated shared value as %d\n",shared);
	//!exit critical section

	sem_post(&sem);
}

void *func2(){
	int x;
        sem_wait(&sem);

        //!critical section
        x=shared;
        printf("Thr2: reads shared as %d\n",x);
        x--;
        printf("Thr2: after local update %d\n",x);
        sleep(1);
        shared=x;
        printf("Thr2 : Updated shared value as %d\n",shared);
        //!exit critical section

        sem_post(&sem);

}
