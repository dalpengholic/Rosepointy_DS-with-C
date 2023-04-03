#include <stdio.h>
#include <malloc.h>

typedef struct NODE {
    // data
    int nData;
    // pointer to manage data
    struct NODE* next;
} NODE;

int g_nSize;
NODE* g_pHead;
NODE* g_pTail;




void InitList(){
    g_pHead = (NODE*)malloc(sizeof(NODE));
    g_pTail = (NODE*)malloc(sizeof(NODE));
    g_nSize = 0;
}

void ReleaseList(){
     free(g_pHead);
     free(g_pTail);
     g_nSize = 0;
}

void PrintList(){


}

NODE* FindNode(const char* pszData){
    return NULL;
}

int DeletNode(const char* pszData){
    NODE* pNode = FindNode(pszData);
    return 0;
}

int InsertAtHead(const char *pszData){
    return 0;

}

int InsertAtTail(const char *pszData){
    return 0;

}

int GetSize(void){

    return g_nSize;
}

int GetLength(){
    return GetSize();

}

int main(){
    InitList();
    ReleaseList();
    return 0;
}
