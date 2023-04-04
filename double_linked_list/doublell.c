#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct NODE {
    char szData[64];
    struct NODE* prev;
    struct NODE* next;
} NODE;

NODE* g_pHead;
NODE* g_pTail;
int g_nSize;

void InitList(void){
    g_pHead = (NODE*)malloc(sizeof(NODE));
    g_pTail = (NODE*)malloc(sizeof(NODE));

    memset(g_pHead,0,sizeof(NODE));
    memset(g_pTail,0,sizeof(NODE));
    g_nSize = 0;

    strcpy(g_pHead->szData, "Dummy Head");
    strcpy(g_pTail->szData, "Dummy Tail");
    
    g_pHead->prev = NULL;
    g_pHead->next = g_pTail;

    g_pTail->prev = g_pHead;
    g_pTail->next = NULL;
}

void ReleaseList(void){
    printf("ReleaseList():\n");
    NODE* pCurrent = g_pHead;
    while(pCurrent != NULL){
        NODE* pDelete = pCurrent;
        pCurrent = pCurrent->next;
        printf("Deleted(%p)\n",pDelete);
        free(pDelete);
    }

    g_pHead = NULL;
    g_pTail = NULL;
    g_nSize = 0;

}

void PrintList(void){
    NODE* pCurrent = g_pHead;
    while(pCurrent != NULL){
        printf("[%p]: %p ,%s, %p \n",pCurrent, 
        pCurrent->prev, pCurrent->szData, pCurrent->next);
        pCurrent = pCurrent->next;
    }

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
    InitList();
    PrintList();
    ReleaseList();
    return 0;
}