#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

// the initial balance is 0
int balance = 0;
pthread_mutex_t mutex;

// carry out a deposit
void* deposit(void *amount)
{
	for (int i = 0; i < 1000000; ++i)
	{
		pthread_mutex_lock(&mutex);
		++balance;
		pthread_mutex_unlock(&mutex);
	}	
	return NULL;
}

int main()
{

  pthread_t thread1;
  pthread_t thread2;

  // initialize the mutex
  pthread_mutex_init(&mutex, NULL);

  // create threads to run the deposit function with these deposit amounts
  pthread_create(&thread1, NULL, deposit, NULL);
  pthread_create(&thread2, NULL, deposit, NULL);

  // join the threads
  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);

   // destroy the mutex
  pthread_mutex_destroy(&mutex);
  printf("%d\n", balance);

  return 0;
}