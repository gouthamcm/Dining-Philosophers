/* Created by Goutham C M
   on Dec 2 2021 */

#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <vector>
#include <semaphore.h>

#define PHILOSOPHERS_COUNT 5

using namespace std;


sem_t number_of_rooms;
sem_t chopsticks[PHILOSOPHERS_COUNT];

void thinking(int philosopher){
    printf("Philosopher %d is thinking\n", philosopher+1);
    return ;
}

void eating_init(int philosopher){
    printf("Philosopher %d is going to eat\n", philosopher+1);
    return ;
}

void eating_done(int philosopher){
    printf("Philosopher %d is done eating\n", philosopher+1);
    return ;
}

void pull_out(int philosopher){
    printf("Philosopher %d is pulling out\n", philosopher+1);
    return ;
}

void enter_room(int philosopher){
    printf("Philosopher %d is entering the room\n", philosopher+1);
}

void * dining_philosophers(void *arg){
    int phil = *(int *)arg;

    thinking(phil);

    sem_wait(&number_of_rooms);
    enter_room(phil);
    
    sem_wait(&chopsticks[phil]);
    sem_wait(&chopsticks[(phil+1)%PHILOSOPHERS_COUNT]);

    eating_init(phil);
    sleep(4);
    eating_done(phil);

    sem_post(&chopsticks[(phil+1)%PHILOSOPHERS_COUNT]);
    sem_post(&chopsticks[phil]);

    sem_post(&number_of_rooms);
    pull_out(phil);

}

int main(int argc, char* argv[]){
    
    cout<<"Hi! Welcome to the puzzle\nEnjoy the conference\n\n";

    vector<int> phil(PHILOSOPHERS_COUNT);
    for(int i=0; i<PHILOSOPHERS_COUNT; i++){
        phil[i]=i;
    }

    sem_init(&number_of_rooms, 0, PHILOSOPHERS_COUNT-1);
    for(int i=0; i<PHILOSOPHERS_COUNT; i++){
        sem_init(&chopsticks[i], 0, 1);
    }

    pthread_t thread[PHILOSOPHERS_COUNT];

    for(int i=0; i<PHILOSOPHERS_COUNT; i++){
        
        pthread_create(&thread[i], NULL, dining_philosophers, (void *)&phil[i]);
    }
    for(int i=0; i<PHILOSOPHERS_COUNT; i++){
        pthread_join(thread[i], NULL);
    }
    printf("\nConference is adjouned.. Bye!\n\n");
    return 0;
}