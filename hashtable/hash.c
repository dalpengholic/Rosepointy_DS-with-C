#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define HASH_TABLE_SIZE 100

// NODE 구조체: 배열에 인덱스에 달릴 연결리스트
// HASHTABLE 구조체: 배열을 가리킬 포인터, 배열 사이즈.
// HASH함수()
// HASHINIT
// HASHADD()
// HASHFIND()


typedef struct NODE{
    char szName[64];
    char szPhone[64];
    struct NODE* next;
} NODE;

typedef struct Hashtable{
    NODE** head;
    int size;
} Hashtable;


void hashInit(Hashtable* p, int cnt){
    // 밑에 calloc이 잘 이해 안감
    p->head = (NODE**)calloc(cnt, sizeof(NODE*));
    p->size = cnt;
}

unsigned int hashFunction(const char* pszData, int size){
    unsigned int hash = 5381;
    int c;

    while ((c = *pszData++)) {
        hash = ((hash << 5) + hash) + c;
    }

    return (int)(hash % HASH_TABLE_SIZE);
}

void hashAdd(Hashtable* p, const char* key_name, const char* phone){
    int index = hashFunction(key_name, p->size);
    
    NODE* pNewNode = (NODE*)malloc(sizeof(NODE));
    strcpy(pNewNode->szName, key_name);
    strcpy(pNewNode->szPhone, phone);
    pNewNode->next = NULL;

    if (p->head[index]==NULL) p->head[index]= pNewNode;
    else {
        pNewNode->next = p->head[index];
        p->head[index] = pNewNode;
    }
}



int hashFind(Hashtable* p, const char* name){
    int index = hashFunction(name, p->size);
    NODE* pCurrent = p->head[index];
    while (pCurrent){
        if (strcmp(pCurrent->szName, name)==0)
            printf("[%p] %s, %s\n", pCurrent, pCurrent->szName, pCurrent->szPhone);
            return 1;
        pCurrent = pCurrent->next;
    }
    return 0;

}

int main(){
    Hashtable ht;
    hashInit(&ht, 7);
    hashAdd(&ht, "tomy", "040-1111-1111");
    hashAdd(&ht, "amy", "040-2222-3333");
    hashAdd(&ht, "kat", "041-1111-1111");
    hashAdd(&ht, "sam", "040-3333-1111");
    hashAdd(&ht, "son", "042-1111-1111");
    hashFind(&ht, "kat");
    printf("%d\n",hashFunction("kat", 7));
    printf("%d\n",hashFunction("tomy", 7));
    printf("%s, %s\n", ht.head[37]->szName, ht.head[37]->szPhone);
    printf("%s, %s\n", ht.head[94]->szName, ht.head[94]->szPhone);


    return 0;
}