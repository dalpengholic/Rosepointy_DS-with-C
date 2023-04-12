#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct NODE {
    char szData[64];
    struct NODE* next;
    struct NODE* prev;
} NODE;

NODE* g_pHead = NULL;
NODE* g_pTail = NULL;
int g_nSize = 0;

void InitList(void){
    // Create dummy head and tail
    // Initialize
    g_pHead = (NODE*)malloc(sizeof(NODE));
    g_pTail = (NODE*)malloc(sizeof(NODE));

    memset(g_pHead, 0, sizeof(NODE));
    memset(g_pTail, 0, sizeof(NODE));

    strcpy(g_pHead->szData, "Dummy Head");
    strcpy(g_pTail->szData, "Dummy Tail");
    g_nSize = 0;

    g_pHead->next = g_pTail;
    g_pTail->prev = g_pHead;
}

void ReleaseList(void){
    // Delete them one by one
    // Print being deleted node
    NODE* pCurrent = g_pHead;
    while(pCurrent != NULL){
        NODE* pDelete = pCurrent;
        pCurrent = pCurrent->next;
        printf("ReleaseList(): [%p], %s\n",pDelete, pDelete->szData);
        free(pDelete);
    }

    g_pHead = NULL;
    g_pTail = NULL;
    g_nSize = 0;
}

void Printlist(void){
    NODE* pCurrent = g_pHead;
    while(pCurrent != NULL){
        printf("PrintList(): [%p]: %p, %s, %p\n",pCurrent, pCurrent->prev, 
        pCurrent->szData, pCurrent->next);
        pCurrent = pCurrent->next;
    }
}
// 13min

NODE* FindNode(const char* pszData){
    NODE* pCurrent = g_pHead;
    while(pCurrent != NULL){
        if (strcmp(pszData, pCurrent->szData)==0){
            printf("FindNode():[%p], %p,%s,%p\n",pCurrent, pCurrent->prev, pCurrent->szData ,pCurrent->next);
            return pCurrent;
        }
        pCurrent=pCurrent->next;
    }
    return NULL;
}

// 싱글처럼 여기서도 에러
void InsertAfter(const char* pTargetData, const char* pszData){
    // Create and init new node
    // Find Target node with FindNode
    // Organizse Relationship: NewNode, TargetNode
    // g_nSize ++
    NODE* pTargetNode = FindNode(pTargetData);
    if(pTargetNode != NULL){
        NODE* pNewNode = (NODE*)malloc(sizeof(NODE));
        memset(pNewNode, 0, sizeof(NODE));
        strcpy(pNewNode->szData, pszData);

        pNewNode->next = pTargetNode->next;
        pTargetNode->next->prev = pNewNode;

        pTargetNode->next = pNewNode;
        pNewNode->prev = pTargetNode;
        g_nSize++;
    }
    else{
        printf("No Target Word\n");
    }
}

void InsertBefore(const char* pTargetData, const char* pszData){
    // Create and init new node
    // Find Target node with FindNode
    // Organizse Relationship: NewNode, TargetNode
    // g_nSize ++
    NODE* pTargetNode = FindNode(pTargetData);
    if(pTargetNode != NULL){
        NODE* pNewNode = (NODE*)malloc(sizeof(NODE));
        memset(pNewNode, 0, sizeof(NODE));
        strcpy(pNewNode->szData, pszData);

        pNewNode->prev = pTargetNode->prev;
        pTargetNode->prev->next = pNewNode;

        pTargetNode->prev = pNewNode;
        pNewNode->next = pTargetNode;

        g_nSize++;
    }
    else{
        printf("No Target Word\n");
    }    
}
// 38min

void DeleteNode(const char* pTargetData){
    NODE* pDelete = FindNode(pTargetData);
    if(pDelete != NULL){
        NODE* pDeletePrev = pDelete->prev;
        NODE* pDeleteNext = pDelete->next;
        pDeletePrev->next = pDeleteNext;
        pDeleteNext->prev = pDeletePrev;
        printf("FindNode():[%p], %p,%s,%p\n",pDelete, pDelete->prev, pDelete->szData ,pDelete->next);
        free(pDelete);
        g_nSize--;
    }
    else{
        printf("No Target Word\n");
    }
}
// 43min

void GetSize(){
    printf("Number of nodes: %d\n",g_nSize);
}

void InsertAtHead(const char* pszData){
    InsertAfter("Dummy Head", pszData);
}

void InsertAtTail(const char* pszData){
    InsertBefore("Dummy Tail", pszData);
}
// 51min

int main(){
    InitList();
    InsertAfter("Dummy Head", "IA-1");
    InsertAfter("Dummy Head", "IA-2");
    InsertAfter("Dummy Head", "IA-3");
    InsertBefore("Dummy Tail", "IB-1");
    InsertBefore("Dummy Tail", "IB-2");
    InsertBefore("Dummy Tail", "IB-3");
    InsertAtHead("TEST-1");
    InsertAtTail("TEST-2");
    
    puts("************");
    Printlist();
    DeleteNode("IB-1");
    DeleteNode("IA-3");
    puts("************");
    Printlist();
    GetSize();
    ReleaseList();
    return 0;
}