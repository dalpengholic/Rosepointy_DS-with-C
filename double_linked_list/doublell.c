#include <stdio.h>
#include <malloc.h>
#include <string.h>

/*
- Function List
-- InitList() / ReleaseList()
-- PrintList()
-- FindNode()
-- DeleteNode()
-- InsertBefore()/InsertAfter()
-- GetSize()
*/
typedef struct NODE {
    char szData[64];
    struct NODE* prev;
    struct NODE* next;
} NODE;

NODE* g_pHead;
NODE* g_pTail;
int g_nSize;

void InitList(void){

}
void ReleaseList(void){

}

void PrintList(void){

}
NODE* FindNode(const char* pszData){
    return NULL;

}

int DeleteNode(const char* pszData){
    return 0;
}

int InsertBefore(const char* pszData){
    return 0;
}
int InsertAfter(const char* pszData){
    return 0;
}

int GetSize(){
    return g_nSize;
}

int main(){
    return 0;
}