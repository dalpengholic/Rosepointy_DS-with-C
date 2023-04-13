#include <stdio.h>
#include <malloc.h>

// 만일 공간이 다 차면 새로운 메모리 생성 및 기존파일내용 복사 및 기존내용 삭제를 한다면
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
    if (p->count < p->capacity){
        p->pArr[p->rear] = ndata;
        p->rear++;
        p->count++;
        if (p->rear >= p->capacity){
            p->rear = 0;
        }
    }
    else
        printf("The circular queue is full (count/capacity:%d/%d).You need to dequeue first.\n", 
        p->count, p->capacity);
}

int Dequeue(Cqueue *p){
    if (p->count >0){
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
    else{
        printf("The circular queue is empty (count/capacity:%d/%d).\n", 
        p->count, p->capacity);
    }
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
    Enqueue(&queue, 200);
    puts("****************");
    Dequeue(&queue);
    Dequeue(&queue);
    Enqueue(&queue, 300);
    Enqueue(&queue, 400);

    puts("****************");
    PrintCqueue(&queue);
    Enqueue(&queue, 500);
    Dequeue(&queue);
    Dequeue(&queue);
    Dequeue(&queue);
    Dequeue(&queue);
    Dequeue(&queue);
    Dequeue(&queue);




    return 0;
}


