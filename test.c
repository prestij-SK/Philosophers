// #include <unistd.h>
// #include <stdio.h>
// #include <pthread.h>

// // the initial balance is 0
// int balance = 0;
// pthread_mutex_t mutex;

// // carry out a deposit
// void* deposit(void *amount)
// {
// 	for (int i = 0; i < 1000000; ++i)
// 	{
// 		pthread_mutex_lock(&mutex);
// 		++balance;
// 		pthread_mutex_unlock(&mutex);
// 	}	
// 	return NULL;
// }

// int main()
// {

//   pthread_t thread1;
//   pthread_t thread2;

//   // initialize the mutex
//   pthread_mutex_init(&mutex, NULL);

//   // create threads to run the deposit function with these deposit amounts
//   pthread_create(&thread1, NULL, deposit, NULL);
//   pthread_create(&thread2, NULL, deposit, NULL);

//   // join the threads
//   pthread_join(thread1, NULL);
//   pthread_join(thread2, NULL);

//    // destroy the mutex
//   pthread_mutex_destroy(&mutex);
//   printf("%d\n", balance);

//   return 0;
// }

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_PHILOSOPHERS 5
#define THINKING 0
#define HUNGRY 1
#define EATING 2
#define LEFT (philosopher_id + NUM_PHILOSOPHERS - 1) % NUM_PHILOSOPHERS
#define RIGHT (philosopher_id + 1) % NUM_PHILOSOPHERS

pthread_mutex_t forks[NUM_PHILOSOPHERS];
pthread_t philosophers[NUM_PHILOSOPHERS];
int philosopher_state[NUM_PHILOSOPHERS];

void *philosopher(void *arg) {
    int philosopher_id = *(int *)arg;
    while (1) {
        // Thinking
        printf("Philosopher %d is thinking\n", philosopher_id);

        // Hungry - try to pick up forks
        pthread_mutex_lock(&forks[LEFT]);
        pthread_mutex_lock(&forks[RIGHT]);

        // Eating
        philosopher_state[philosopher_id] = EATING;
        printf("Philosopher %d is eating\n", philosopher_id);

        // Release forks
        pthread_mutex_unlock(&forks[LEFT]);
        pthread_mutex_unlock(&forks[RIGHT]);

        // Back to thinking
        philosopher_state[philosopher_id] = THINKING;
        sleep(rand() % 5); // Simulating thinking
    }
}

int main() {
    srand(time(NULL));

    // Initialize mutexes for each fork
    for (int i = 0; i < NUM_PHILOSOPHERS; ++i) {
        pthread_mutex_init(&forks[i], NULL);
    }

    // Create threads for each philosopher
    for (int i = 0; i < NUM_PHILOSOPHERS; ++i) {
        int *id = (int *)malloc(sizeof(int));
        *id = i;
        pthread_create(&philosophers[i], NULL, philosopher, (void *)id);
    }

    // Join threads (this won't actually happen in this simulation)
    for (int i = 0; i < NUM_PHILOSOPHERS; ++i) {
        pthread_join(philosophers[i], NULL);
    }

    // Destroy mutexes
    for (int i = 0; i < NUM_PHILOSOPHERS; ++i) {
        pthread_mutex_destroy(&forks[i]);
    }

    return 0;
}