#include <stdio.h>
#include <stdlib.h>


#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

#define BUFF_SIZE 10
#define CUSTOMER 5
#define PRODUCER 5
//实验环境 Ubuntu20.04
int buffer[BUFF_SIZE] = { 0 } ;
int  in = 0, out = 0;                  //  生产和消费的产品位置
int pro_id = 0;                       //生产者id
int cus_id = 0;                      //消费者id
pthread_mutex_t sem_mutex;          //  生产者和消费者的互斥量
sem_t p_sem_mutex;                 //  空的时候，对消费者不可进
sem_t c_sem_mutex;                //  满的时候，对生产者不可进

void * Producer()
{
    int id = ++pro_id;
    int count=0;
    while(1)
    {   
    /////////    sleep(3);
        if(count>0)
            printf("生产者%dGOTO Producer()\n",id);
        printf("生产者%d生产了一个产品\n",id);
        printf("生产者%d执行P操作\n",id);
        sem_wait(&p_sem_mutex);     //  当缓冲池未满时
        
        pthread_mutex_lock(&sem_mutex);      //  生产消费互斥

        in= in % BUFF_SIZE;
        printf("生产者%d在产品队列中放入第%d个产品\n",id, in+1);
 
        buffer[in]= 1;
        ++in;
        pthread_mutex_unlock(&sem_mutex);
        
        printf("生产者%d执行V操作\n",id);
        sem_post(&c_sem_mutex);
        count++;
    }
}

void * Consumer()
{
    int id = ++cus_id;
    int count=0;
    while(1)
    {   
        //sleep(5);
        if(count>0)
            printf("消费者%dGOTO Consumer()\n",id);
        printf("消费者%d执行P操作\n",id);
        sem_wait(&c_sem_mutex); //  缓冲池未空时
        pthread_mutex_lock(&sem_mutex);   //  生产消费互斥

        out = out % BUFF_SIZE;
        printf("消费者者%d在产品队列中取走第%d个产品\n",id, out+1);
 
        buffer[out]= 0;
        ++out;
        pthread_mutex_unlock(&sem_mutex);
        
        printf("消费者%d执行V操作\n",id);
        sem_post(&p_sem_mutex);
        printf("消费者%d消费了一个产品\n",id);
        count++;
        
    }

    return NULL;
}



int main()
{
    pthread_t pid[PRODUCER], cid[CUSTOMER];
    int i;
    sem_init(&p_sem_mutex,0,BUFF_SIZE);
    sem_init(&c_sem_mutex,0,0);
    pthread_mutex_init(&sem_mutex,NULL);
    for(i=0;i<PRODUCER;i++)
    {
        pthread_create(&pid[i],NULL,Producer,NULL);
        pthread_create(&cid[i],NULL,Consumer,NULL);
    }
    for(i=0;i<PRODUCER;i++) 
    {
        pthread_join(pid[i], NULL);
        pthread_join(cid[i],NULL);  
    }
    exit(0);
}