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
// void InsertNode(const char* pszData){
//     NODE* pNewNode = (NODE*)malloc(sizeof(NODE));
//     memset(pNewNode, 0, sizeof(NODE));
//     strcpy(pNewNode->szData, pszData);
//     if (g_Root == NULL){
//         g_Root = pNewNode;
//     }
//     else {
//         NODE* pCurrent = g_Root;
//         while(pCurrent != NULL){
//             if(strcmp(pCurrent->szData, pszData) < 0)
//                 if (pCurrent->right != NULL)
//                     pCurrent = pCurrent->right;
//                 else{
//                     pCurrent->right = pNewNode;
//                     break;
//                 }
//             else{
//                 if (pCurrent->left != NULL)
//                     pCurrent = pCurrent->left;
//                 else{
//                     pCurrent->left = pNewNode;
//                     break;
//                     }   
//             }         
//         }
//     }
//     g_nSize++;
// }
// 45min

//재귀호출 사용. 
NODE* AddNode(NODE* pStartNode, const char* pszData){
    //재귀호출 멈추는 조건. 새노드 추가 및 초기화
    if (pStartNode == NULL){
        // 아래에서 NODE* pStartNode선언하여 에러발생!!
        pStartNode = (NODE*)malloc(sizeof(NODE));
        memset(pStartNode, 0, sizeof(NODE));
        strcpy(pStartNode->szData, pszData);
        g_nSize++;
    }
    else{
        if(strcmp(pStartNode->szData, pszData) < 0)
            pStartNode->right = AddNode(pStartNode->right, pszData);
        else
            pStartNode->left = AddNode(pStartNode->left, pszData);
    }

    return pStartNode;
}



NODE* FindNode(const char* pszData){
    if (g_Root == NULL){
        printf("No Tree\n");
        return NULL;
    }
    else{
        NODE* pCurrent = g_Root;
        while (pCurrent != 0){
            if(strcmp(pCurrent->szData, pszData) == 0){
                printf("Found %p, %s\n",pCurrent, pCurrent->szData);
                return pCurrent;
            }
            else{
                if(strcmp(pCurrent->szData, pszData) < 0)
                    pCurrent = pCurrent->right;
                else
                    pCurrent = pCurrent->left;
            }
        }

    }
}
//63min

NODE* FindMax(NODE* pStartNode){
    NODE* pCurrent = pStartNode;
    // pCurrent != null --> pCurrent->right != null
    while (pCurrent->right != NULL)
        pCurrent = pCurrent->right;
    if (pCurrent != NULL)    
        printf("FindMax():%p, %s\n", pCurrent, pCurrent->szData);
    return pCurrent;
}

NODE* DeleteNode(NODE* pStartNode, const char* pszData){
    //Max or min first!
    //No child
    //One child
    //Two children
    //g_nSize --
    //재귀호출이니까 멈추는 조건부터 시작
    
    //
    //재귀함수가 멈추는 조건은 노드가 존재할때?
    NODE* temp;
    // 밑에 조건이 있어야 leaf노드에서 멈춤
    if (pStartNode){
        //찾으면 삭제
        if (strcmp(pStartNode->szData, pszData)==0){
            //no child
            if(pStartNode->left == NULL && pStartNode->right == NULL){
                free(pStartNode);
                g_nSize--;
                return NULL;
            }
            //left child
            if(pStartNode->left != NULL && pStartNode->right == NULL){
                temp = pStartNode->left;
                free(pStartNode);
                g_nSize--;
                return temp; 
            }
            //right child
            if(pStartNode->right != NULL && pStartNode->left == NULL){
                temp = pStartNode->right;
                free(pStartNode);
                g_nSize--;
                return temp; 
            }
            //two children
            //copy left tree max value to target
            //delete the left tree max node 
            else{
                NODE* temp = FindMax(pStartNode->left); 
                strcpy(pStartNode->szData, temp->szData);
                pStartNode->left = DeleteNode(pStartNode->left, temp->szData);
            }
        }
        else{
            if(strcmp(pStartNode->szData, pszData) < 0)
                pStartNode->right = DeleteNode(pStartNode->right, pszData);
            else
                pStartNode->left = DeleteNode(pStartNode->left, pszData);
        }
    }
    return pStartNode;


}

void GetSize(){

}


int main(){

    // InsertNode("5-TEST");
    // PrintTree(g_Root);
    // puts("***********");
    // InsertNode("4-TEST");
    // InsertNode("7-TEST");
    // PrintTree(g_Root);
    // puts("***********");
    // InsertNode("6-TEST");
    // InsertNode("8-TEST");
    // PrintTree(g_Root);
    // puts("***********");

    // FindNode("8-TEST");
    // FindNode("8-TE");
    // FindNode("6-TEST");
    // ReleaseTree(g_Root);
    //일종의 init임
    // g_Root = AddNode(g_Root, "15-Test");
    // printf("%p\n",g_Root);
    // AddNode(g_Root, "18-Test");
    // printf("%p\n",g_Root);
    // AddNode(g_Root, "13-Test");
    // PrintTree(g_Root);
    // puts("***********");
    // g_Root = AddNode(g_Root, "12-Test");
    // g_Root = AddNode(g_Root, "16-Test");
    // g_Root = AddNode(g_Root, "17-Test");
    // AddNode(g_Root, "13-Test");
    // PrintTree(g_Root);
    // FindMax(g_Root);

    g_Root = AddNode(g_Root, "50-Test");
    AddNode(g_Root, "80-Test");
    AddNode(g_Root, "30-Test");
    AddNode(g_Root, "70-Test");
    AddNode(g_Root, "40-Test");
    AddNode(g_Root, "20-Test");
    AddNode(g_Root, "90-Test");
    // PrintTree(g_Root);
    puts("***********");
    FindMax(g_Root);
    DeleteNode(g_Root,"40-Test");
    DeleteNode(g_Root,"3-Test");
    PrintTree(g_Root);
    puts("***********");
    DeleteNode(g_Root,"30-Test");
    PrintTree(g_Root);
    puts("***********");



    ReleaseTree(g_Root);    
    return 0;
}

