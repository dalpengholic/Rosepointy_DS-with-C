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
char g_szPopData[64];

void InitList(void){
    g_pHead = (NODE*)malloc(sizeof(NODE));
    g_pTail = (NODE*)malloc(sizeof(NODE));
    
    g_nSize = 0;
    memset(g_szPopData, 0, sizeof(char)*64);
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
        printf("free(%p)\n",pDelete);
        free(pDelete);
    }
    g_nSize = 0;
    memset(g_szPopData, 0, sizeof(char)*64);
    g_pHead = NULL;
    g_pTail = NULL;
}

void PrintList(void){
    NODE* pCurrent = g_pHead;
    while(pCurrent!=NULL){
        printf("[%p], %s, [%p]\n",pCurrent, pCurrent->szData, pCurrent->next);
        pCurrent = pCurrent->next;
    }

}


NODE* FindNode(const char* pszData){
    NODE* pCurrent = g_pHead->next;
    NODE* pPrevious = g_pHead;
    while(pCurrent->next != NULL){
        // hard to remember strcmp
        if (strcmp(pCurrent->szData, pszData)==0)
            return pPrevious;
        pCurrent = pCurrent->next;
        pPrevious = pPrevious->next;
    }
    // The `previous node` should be returned because this is a single linked list 
    return NULL;
}

int DeletNode(const char* pszData){
    NODE* pPrevious = FindNode(pszData);
    if (pPrevious != NULL){
        NODE* pDetete = pPrevious->next;
        pPrevious->next = pPrevious->next->next;
        free(pDetete);
    }
    else{
        printf("There is no node having %s\n", pszData);
    }
    g_nSize--;
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
    NODE* pNewNode = (NODE*)malloc(sizeof(NODE));
    memset(pNewNode, 0, sizeof(NODE));
    strcpy(pNewNode->szData, pszData);

    NODE* pCurrent = g_pHead;
    // having a difficulty
    // Wrong:while(pCurrent != g_pTail)
    while(pCurrent->next->next != NULL){
        pCurrent = pCurrent->next;
    }

    pCurrent->next = pNewNode;
    pNewNode->next = g_pTail;

    g_nSize++;
    return g_nSize;

}

int GetSize(void){
    return g_nSize;
}

int GetLength(){
    return GetSize();
}

int StackPut(const char *pszData){
    InsertAtHead(pszData);
    return 0;
}

//Pop Location is always the next of head node
//Time spent for return type
int StackPop(){
    NODE* pPopTarget = g_pHead->next;
    strcpy(g_szPopData, pPopTarget->szData);
    DeletNode(g_pHead->next->szData);
    // g_pHead->next = pPopTarget->next;
    // free(pPopTarget);
    return 0;
}

int main(){
    InitList();
    InsertAtHead("Test01");
    InsertAtHead("Test02");
    InsertAtHead("Test03");
    PrintList();
    // ReleaseList();
    puts("***************");
    // InitList();
    InsertAtTail("BACKWARD-01");
    InsertAtTail("BACKWARD-02");
    InsertAtTail("BACKWARD-03");
    printf("size of list: %d\n", GetSize());
    puts("***************");
    printf("found: %p\n",FindNode("BACKWARD-02"));
    PrintList();
    DeletNode("BACKWARD-02");
    puts("***************");
    PrintList();
    DeletNode("Test01");
    puts("***************");
    PrintList();

    StackPut("FromStack-1");
    StackPut("FromStack-2");
    StackPut("FromStack-3");
    PrintList();
    StackPop();
    printf("%s\n",g_szPopData);
    PrintList();
    StackPop();
    printf("%s\n",g_szPopData);
    ReleaseList();

   
    return 0;
}
