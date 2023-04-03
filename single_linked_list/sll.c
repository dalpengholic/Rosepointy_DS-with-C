#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct NODE {
    // data
    char szData[64];
    // pointer to manage data
    struct NODE* next;
} NODE;

int g_nSize;
NODE* g_pHead;
NODE* g_pTail;


void InitList(void){
    g_pHead = (NODE*)malloc(sizeof(NODE));
    g_pTail = (NODE*)malloc(sizeof(NODE));
    
    g_nSize = 0;
    memset(g_pHead, 0, sizeof(NODE));
    memset(g_pTail, 0, sizeof(NODE));

    g_pHead->next = g_pTail;
    g_pTail->next = NULL;

    strcpy(g_pHead->szData, "Dummy Head");
    strcpy(g_pTail->szData, "Dummy Tail");

}

void ReleaseList(void){
    NODE* pTmp = g_pHead;
    NODE* pDelete;
    while(pTmp!=NULL){
        pDelete = pTmp;
        pTmp = pTmp->next;
        free(pDelete);
    }
    g_nSize = 0;
}

void PrintList(void){
    NODE* pCurrent = g_pHead;
    while(pCurrent!=NULL){
        printf("[%p], %s, [%p]\n",pCurrent, pCurrent->szData, pCurrent->next);
        pCurrent = pCurrent->next;
    }

}

NODE* FindNode(const char* pszData){
    return NULL;
}

int DeletNode(const char* pszData){
    NODE* pNode = FindNode(pszData);
    return 0;
}

int InsertAtHead(const char *pszData){
    NODE* pNewNode = (NODE*)malloc(sizeof(NODE));
    memset(pNewNode, 0 ,sizeof(NODE));
    strcpy(pNewNode->szData, pszData);
    

    pNewNode->next = g_pHead->next;
    g_pHead->next = pNewNode;

    g_nSize++;
    return g_nSize;

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
    InsertAtHead("Test01");
    PrintList();
    ReleaseList();
    return 0;
}
