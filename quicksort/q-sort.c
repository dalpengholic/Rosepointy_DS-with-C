#include <stdio.h>

void quick_sort(int* arr, int left, int right){
    // 1.피벗 값설정 및 인덱스 설정
    // 2.왼쪽에서 피벗값과 비교하며 오른쪽으로 전진
    // 3.violation시 멈춤
    // 4.오른쪽에서 피벗값과 비교하며 왼쪽으로 전진
    // 5.violation시 멈춤
    // 6.양쪽 멈춘값을 바꿔줌
    // 7.pL증가, pR감소
    // 7. 2~6을 pL과 pR이 피벗을 지날때 까지 진행. 
    // 크로스 되면 멈춤 == 한번 모든데이터 검색 완료. 
    // 피벗 중심으로 정리 완료
    // 재귀호출
    
    int pL_index = left;
    int pR_index = right;
    int pivot = arr[(pL_index+pR_index)/2];
    int temp;

    do {
    while (arr[pL_index] < pivot) pL_index++;
    while (arr[pR_index] > pivot) pR_index--;

    if (pL_index <= pR_index){
    temp = arr[pL_index];
    arr[pL_index] = arr[pR_index];
    arr[pR_index] = temp;
    pL_index++;
    pR_index--;
    }

    } while (pR_index >= pL_index);
    if (left < pR_index)
        quick_sort(arr, left, pR_index);
    if (right > pL_index)
        quick_sort(arr, pL_index, right);

}

int main(){
    int arr[10] = {3,1,4,2,5,5,7,8,9,19};
    quick_sort(arr, 0, 9);
    for (int i=1; i<10; i++){
        printf("%d,", arr[i]);
    }
    return 0;
}