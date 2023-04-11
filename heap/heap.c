#include <stdio.h>
#define ARR_SIZE 10
// MAX HEAP

typedef struct HEAP{
    int* pArr;
    int size;
    int capacity;
} HEAP;


void Shiftdown(int*, int, int);
void Shiftup(int*, int);

void HeapAdd(HEAP* p, int value){
    // Add at last
    p->pArr[p->size] = value;
    // Call Shiftup. 싸이즈만 들어가면 됨
    Shiftup(p->pArr, p->size); 
    p->size++;
}

void Shiftup(int* arr, int index){
    // Parent index
    int parent_index = (index-1)/2;
    // 아래 재귀호출 틀림
    if (parent_index >= 0 && arr[parent_index] < arr[index]){
        int temp = arr[parent_index];
        arr[parent_index] = arr[index];
        arr[index] = temp;
        Shiftup(arr, parent_index);
    }
}
// Heapadd + Shiftup: 15분


void Heapify(HEAP* p, int* arr, int size){
    //Init
    p->pArr = arr;
    p->size = size;
    p->capacity = ARR_SIZE;
    // Heapify 
    // Starting point = size/2 - 1
    for (int i=size/2-1; i>=0; i--){
        Shiftdown(p->pArr, i, p->size);
    }
}

void Shiftdown(int* arr, int parent_index, int size){
    // Children index
    int left = 2*parent_index +1;
    int right = left +1;
    int large = -1;

    // Find large index
    if (left < size){
        large = left;
    }
    if (right < size && arr[right] > arr[left]){
        large = right;
    }

    // 그림 이해가 필요. 그림그림!
    // Exchange if child is larger than its parent
    if (large != -1 && arr[large] > arr[parent_index]){
        int temp = arr[large];
        arr[large] = arr[parent_index]; 
        arr[parent_index] = temp;
        // 아래 인덱스를 틀렸음
        Shiftdown(arr, large, size);  
    }
}
//30min


int main(){
    int array[ARR_SIZE] = {3,7,2,9,1,4,5,8,6};
    HEAP heap;
    for (int i=0; i<9; i++)
        printf("%d,",array[i]);
    puts("*************");

    Heapify(&heap, array, 9);
    for (int i=0; i<9; i++)
        printf("%d,",array[i]);
    puts("*************");


    HeapAdd(&heap, 10);
        for (int i=0; i<10; i++)
        printf("%d,",array[i]);
    puts("*************");

    
    return 0;
}