#include <stdio.h>

// quick-sort 구현
void quicksort(int* arr, int left, int right){
    int pL_index = left;
    int pR_index = right;
    int pivot_value = arr[(pL_index+pR_index)/2];
    int temp;

    do{
        // 밑에 while을 놓침
        while (pivot_value > arr[pL_index]) pL_index++;
        while (pivot_value < arr[pR_index]) pR_index--;

        // 밑에 if조건을 놓침
        if (pL_index <= pR_index){
            temp = arr[pR_index];
            arr[pR_index] = arr[pL_index];
            arr[pL_index] = temp;
            pL_index++;
            pR_index--;
        }
        // while 조건 반대로
    } while(pL_index <= pR_index);

    if (left < pR_index) {
        quicksort(arr, left, pR_index);
    }
    //아래 if 문 순서 잘못적음

    if (pL_index < right) {
        quicksort(arr, pL_index, right);
    }

    // do
    //피벗값과 arr[pL_index]비교
    //피벗보다 작으면 ++
    //피벗값과 arr[pR_index]비교
    //피벗보다 크면 --
    // 멈추면 SWAP
    // SWAP후 ++ --
    // while (pL>=pR);

    // left < pR_index면 왼쪽 퀵소트콜 
    // right > pL_index면 오른쪽 퀵소트콜

}

void print_arr(int* arr, int length){
    for (int i=0; i<length; i++)
    {
        printf("%d,", arr[i]);
    }

}



int main(){
    int array[10] = {10,34,6,7,56,345,12,3,4,9};
    //10,34,6,7,9,4,12,3,345,56
    //
    print_arr(array, 10);
    quicksort(array, 0,9);
    puts("");

    print_arr(array, 10);

    return 0;
}