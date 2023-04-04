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
    printf("[size of array]: %d\n", g_nSize);

}
NODE* FindNode(const char* pszData){
    NODE* pCurrent = g_pHead;
    while(pCurrent != NULL){
        if (strcmp(pszData, pCurrent->szData) == 0){
            printf("Found[%p]: %p ,%s, %p \n",pCurrent, 
            pCurrent->prev, pCurrent->szData, pCurrent->next);  
            return pCurrent;
        }
        // I forgot adding the following line
        else
            pCurrent = pCurrent->next;
    }    
    return NULL;

}

int DeleteNode(const char* pszData){
    return 0;
}

int InsertBefore(const char* pszData){
    return 0;
}
int InsertAfter(const char* pszData, NODE* pTarget){
    // find a location with FindNode
    // create a new node
    // init the new node
    // organize pointers 

    
    NODE* pNewNode = (NODE*)malloc(sizeof(NODE));
    memset(pNewNode, 0, sizeof(NODE));
    strcpy(pNewNode->szData, pszData);

    pNewNode->next = pTarget->next;
    pNewNode->prev = pTarget;

    pTarget->next->prev = pNewNode;
    pTarget->next = pNewNode;
    g_nSize++;
    return 0;
}

int InsertAtHead(const char* pszData){
    InsertAfter(pszData, g_pHead);
    
    // NODE* pCurrent = g_pHead;

    // NODE* pNewNode = (NODE*)malloc(sizeof(NODE));
    // memset(pNewNode, 0, sizeof(NODE));
    // strcpy(pNewNode->szData, pszData);

    // pNewNode->next = g_pHead->next;
    // pNewNode->prev = g_pHead;

    // g_pHead->next->prev = pNewNode;
    // g_pHead->next = pNewNode;
    // g_nSize++;
    return 0;
}

int InsertAtTail(){
    return 0;
}

int GetSize(){
    return g_nSize;
}

int main(){
    InitList();
    InsertAtHead("TEST-H-1");
    InsertAtHead("TEST-H-2");
    InsertAtHead("TEST-H-3");
    printf("find node %p\n", FindNode("TEST-H-2"));
    printf("size of list: %d\n", GetSize());
    PrintList();

    InsertAfter("Insert-1", FindNode("TEST-H-2"));
    PrintList();
    ReleaseList();
    return 0;
}