#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct NODE {
    char szData[64];
    struct NODE* left;
    struct NODE* right;
} NODE;

NODE* g_Root = NULL;
int g_nSize = 0;

void ReleaseTree(NODE* parentNode){
    if (parentNode == NULL)
        return;
    ReleaseTree(parentNode->left);
    ReleaseTree(parentNode->right);
    printf("ReleaseTree(): [%p] %s\n",parentNode, parentNode->szData);
    free(parentNode);
    g_nSize = 0;
    return;
}
//50min

// 부모 널케이스
void PrintTree(NODE* parentNode){
    if (parentNode == NULL)
        return;
    PrintTree(parentNode->left);
    printf("[%p](%p), %s (%p)\n",parentNode, parentNode->left, parentNode->szData, parentNode->right);
    PrintTree(parentNode->right);
    return;
}

// 재귀호출없이 while, break로 진행 
void InsertNode(const char* pszData){
    NODE* pNewNode = (NODE*)malloc(sizeof(NODE));
    memset(pNewNode, 0, sizeof(NODE));
    strcpy(pNewNode->szData, pszData);
    if (g_Root == NULL){
        g_Root = pNewNode;
    }
    else {
        NODE* pCurrent = g_Root;
        while(pCurrent != NULL){
            if(strcmp(pCurrent->szData, pszData) < 0)
                if (pCurrent->right != NULL)
                    pCurrent = pCurrent->right;
                else{
                    pCurrent->right = pNewNode;
                    break;
                }
            else{
                if (pCurrent->left != NULL)
                    pCurrent = pCurrent->left;
                else{
                    pCurrent->left = pNewNode;
                    break;
                    }   
            }         
        }
    }
    g_nSize++;
}
// 45min
void FindNode(){

}

void DeleteNode(){

}

void GetSize(){

}


int main(){
    InsertNode("5-TEST");
    PrintTree(g_Root);
    puts("***********");
    InsertNode("4-TEST");
    InsertNode("7-TEST");
    PrintTree(g_Root);
    puts("***********");
    InsertNode("6-TEST");
    InsertNode("8-TEST");
    PrintTree(g_Root);
    puts("***********");
    ReleaseTree(g_Root);
    return 0;
}

