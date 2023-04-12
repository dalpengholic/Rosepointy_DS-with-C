#include <stdio.h>
#include <malloc.h>

typedef struct Cqueue{
    int *pArr;
    int front;
    int rear;
    int count;
    int capacity;
} Cqueue;

void InitCqueue(Cqueue *p , int size){
    // 동적할당. sizeof 계산
    p->pArr = (int*)malloc(sizeof(int)*5);
    p->front = 0;
    p->rear = 0;
    p->count = 0;
    p->capacity = size;
}

void Enqueue(Cqueue *p, int ndata){
    p->pArr[p->rear] = ndata;
    p->rear++;
    if (p->count < p->capacity){
        p->count++;
    }

    if (p->rear >= p->capacity){
        p->rear = 0;
    }
}

int Dequeue(Cqueue *p){
    int temp = p->pArr[p->front];
    p->front++;
    if (p->count > 0){
        p->count--;
    }


    if (p->front >= p->capacity){
        p->front = 0;
    }
    printf("Dequeue(): %d\n", temp);

    return temp;
}

void PrintCqueue(Cqueue *p){
    int index;
    for (int i=0; i< p->count; i++){
        index = (p->front + i) % p->capacity;
        printf("Index: %d, Value: %d'\n", 
        index, p->pArr[index]);
    }
}

//33min
int main(){
    Cqueue queue;
    InitCqueue(&queue, 5);
    Enqueue(&queue, 55);
    Enqueue(&queue, 33);
    Enqueue(&queue, 23);
    PrintCqueue(&queue);
    puts("****************");
    Enqueue(&queue, 77);
    Enqueue(&queue, 100);
    PrintCqueue(&queue);
    puts("****************");
    Dequeue(&queue);
    Dequeue(&queue);
    Enqueue(&queue, 300);
    Enqueue(&queue, 400);
    Enqueue(&queue, 500);
    puts("****************");
    PrintCqueue(&queue);




    return 0;
}

