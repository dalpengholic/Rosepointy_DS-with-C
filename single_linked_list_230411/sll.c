#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct NODE {
    char szData[64];
    struct NODE* next;
} NODE;

NODE* g_Head;
NODE* g_Tail;
int g_nSize;

void InitList(){
    g_Head = (NODE*)malloc(sizeof(NODE));
    g_Tail = (NODE*)malloc(sizeof(NODE));

    memset(g_Head, 0, sizeof(NODE));
    memset(g_Tail, 0, sizeof(NODE));
    
    strcpy(g_Head->szData, "Dummy Head");
    strcpy(g_Tail->szData, "Dummy Tail");
    
    g_Head->next = g_Tail;
    g_Tail->next = NULL;
    g_nSize = 0;
}

void ReleaseList(){
    NODE* pCurrent = g_Head;
    while(pCurrent != NULL){
        NODE* pDelete = pCurrent;
        pCurrent = pCurrent->next;
        printf("Release(): Release %p, %s\n", pDelete, pDelete->szData);
        free(pDelete);
    }
    g_Head = NULL;
    g_Tail = NULL;
    g_nSize = 0;
}

void PrintList(){
    NODE* pCurrent = g_Head;
    while(pCurrent != NULL){
        printf("PrintList(): [%p], %s, %p, %d\n", pCurrent, pCurrent->szData,
        pCurrent->next, g_nSize);
        pCurrent = pCurrent->next;
    }
}
// 16min30sec

void InsertAtHead(const char* pszData){
    NODE* pNewNode = (NODE*)malloc(sizeof(NODE));
    memset(pNewNode, 0, sizeof(NODE));
    strcpy(pNewNode->szData, pszData);

    pNewNode->next = g_Head->next;
    g_Head->next = pNewNode;

    g_nSize++;
}

void InsertAtTail(const char* pszData){
    NODE* pNewNode = (NODE*)malloc(sizeof(NODE));
    memset(pNewNode, 0, sizeof(NODE));
    strcpy(pNewNode->szData, pszData);

    NODE* pCurrent = g_Head;
    while (pCurrent->next != g_Tail){
        pCurrent = pCurrent->next;
    }

    pNewNode->next = g_Tail;
    pCurrent->next = pNewNode;

    g_nSize++;    
}
// 30min

NODE* FindNode(){
    return NULL;
}


void DeleteNode(){

}

void InsertAfter(){

}

void InsertBefore(){

}


int main(){
    InitList();
    PrintList();
    puts("***************");
    InsertAtHead("IAH-1");
    InsertAtHead("IAH-2");
    InsertAtHead("IAH-3");
    PrintList();
    puts("***************");
    InsertAtTail("IAT-1");
    InsertAtTail("IAT-2");
    InsertAtTail("IAT-3");
    PrintList();
    ReleaseList();
    return 0;
}