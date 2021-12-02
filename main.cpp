/* Created by Goutham C M
   on Dec 2 2021 */

#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

#define PHILOSOPHERS_COUNT 5

using namespace std;


sem_t number_of_rooms;
sem_t chopsticks[PHILOSOPHERS_COUNT];

void thinking(int philosopher){
    cout<<"Philosopher "<<philosopher<<" is thinking\n";
    return ;
}

void eating_init(int philosopher){
    cout<<"Philosopher "<<philosopher<<" is going to eating\n";
    return ;
}

void eating_done(int philosopher){
    cout<<"Philosopher "<<philosopher<<" is done eating\n";
    return ;
}

void * dining_philosophers(void *arg){

}

int main(int argc, char* argv[]){
    int number_of_philosophers;
    cout<<"Hi! Welcome to the puzzle\nEnjoy the conference\n";
    
    sem_init(&number_of_rooms, 0, 4);
    for(int i=0; i<PHILOSOPHERS_COUNT; i++){
        sem_init(&chopsticks[i], 0, 1);
    }

    pthread_t thread[PHILOSOPHERS_COUNT];

    for(int i=0; i<PHILOSOPHERS_COUNT; i++){
        pthread_create(&thread[i], NULL, dining_philosophers, (void *)&i);
    }
    for(int i=0; i<PHILOSOPHERS_COUNT; i++){
        pthread_join(thread[i], NULL);
    }
    return 0;
}