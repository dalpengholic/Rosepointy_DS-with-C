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

NODE* FindNode(const char* pszData){
    NODE* pCurrent = g_Head->next;
    NODE* pPrev = g_Head;
    while (pCurrent != NULL){
        if (strcmp(pCurrent->szData, pszData) == 0){
            printf("Found(): [%p], %s, %p\n", pCurrent, pCurrent->szData,
        pCurrent->next);
            return pPrev;
        }     
        else{
        pCurrent = pCurrent->next;
        pPrev = pPrev->next;
        }
    }
    return NULL;
}


void DeleteNode(const char* pszData){
    NODE* pPrevDelete = FindNode(pszData);
    NODE* pDelete = pPrevDelete->next;

    pPrevDelete->next = pDelete->next;
    printf("DeleteNode(): Delete %p, %s\n", pDelete, pDelete->szData);
    free(pDelete);

    g_nSize--;
}

void InsertAfter(const char* pszTarget, const char* pszData){
    NODE* pNewNode = (NODE*)malloc(sizeof(NODE));
    memset(pNewNode, 0, sizeof(NODE));
    strcpy(pNewNode->szData, pszData);


    NODE* pPrevTarget = FindNode(pszTarget);
    NODE* pTarget = pPrevTarget->next;

    pNewNode->next = pTarget->next;
    pTarget->next = pNewNode;

    g_nSize++;
}

void InsertBefore(const char* pszTarget, const char* pszData){
    NODE* pNewNode = (NODE*)malloc(sizeof(NODE));
    memset(pNewNode, 0, sizeof(NODE));
    strcpy(pNewNode->szData, pszData);

    NODE* pPrevTarget = FindNode(pszTarget);
    NODE* pTarget = pPrevTarget->next;
    
    pNewNode->next = pPrevTarget->next;
    pPrevTarget->next = pNewNode;
    g_nSize++;
}
// 59min

void GetSize(){
    printf("Number of Nodes: %d\n", g_nSize);
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
    FindNode("IAT-1");
    puts("***************");
    PrintList();
    GetSize();
    DeleteNode("IAT-1");
    puts("***************");
    PrintList();
    GetSize();
    InsertAfter("IAH-3", "test-1");
    InsertAfter("IAH-3", "test-2");
    InsertBefore("IAH-3", "test-3");
    InsertBefore("IAH-3", "test-4");
    puts("***************");
    PrintList();
    GetSize();
    ReleaseList();
    return 0;
}