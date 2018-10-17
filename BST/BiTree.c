#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
* the link is very useful:
*   https://stackoverflow.com/questions/26145978/problems-with-using-struct-in-plain-c
*/

typedef struct _BitNode
{
    int data;
    struct _BitNode *leftChild, *rightChild;
}BitNode, *BiTree;

void createBiTree(BiTree *T)
{
    int data = 0;
    scanf("%d", &data);
    if(data == -1)
    {
        (*T) = NULL;
    }
    else
    {
        *T = (BitNode *)malloc(sizeof(BitNode));
        (*T)->data = data;
        createBiTree(&(*T)->leftChild);
        createBiTree(&(*T)->rightChild);
    }
}

void printBiTree(BiTree T)
{
    if(!T)
    {
        return;
    }
    else
    {
        printBiTree(T->leftChild);
        printf("%d\t", T->data);
        printBiTree(T->rightChild);
    }
}

bool searchBiTree(BiTree T, int key, BiTree pre, BiTree *B)
{
    if(!T)
    {
        *B = pre;
        return false;
    }
    else if(key == T->data)
    {
        *B = T;
        return true;
    }
    if(key < T->data)
    {
        searchBiTree(T->leftChild, key, T, &(*B));
    }
    else if(key > T->data)
    {
        searchBiTree(T->rightChild, key, T, &(*B));
    }
}

bool insertBitNode(BiTree *T, int key)
{
    BiTree Bn = NULL, tmp = NULL;
    if(!searchBiTree(*T, key, NULL, &Bn))
    {
        tmp = (BitNode *)malloc(sizeof(BitNode));
        if(!tmp)
        {
            printf("malloc failed!");
            return false;
        }
        tmp->data = key;
        tmp->leftChild = tmp->rightChild = NULL;
        if(NULL == Bn)
        {
            *T = tmp;
        }
        else
        {
            if(key < Bn->data)
            {
                Bn->leftChild = tmp;
            }
            else if(key > Bn->data)
            {
                Bn->rightChild = tmp;
            }
        }
        return true;
    }
    else
    {
        return false;
    }
}

void freeBiTree(BiTree T)
{
    if(!T)
    {
        return;
    }
    else
    {
        freeBiTree(T->leftChild);
        freeBiTree(T->rightChild);
        freeBiTree(T);
    }
}
int main(){
    BiTree B;
    BiTree T = NULL;
    createBiTree(&T);

    printf("----------\n");
    printBiTree(T);
    printf("\n----------\n");

    bool result = searchBiTree(T, 37, NULL, &B);
    if(result)
        printf("\nCongratulations! you find it.value is : %d\n", B->data);
    else
        printf("\nWhat a pity! your data 37 is not in BiTree.\n");

    int array[] = {32, 24, 15, 24, 18, 29, 100, 1000, 54, 65, 89, 66, 37};
    bool isExecuteInsert = false;
    for(int i = 0; i < (sizeof(array)/sizeof(array[0])); i++)
    {
        isExecuteInsert = insertBitNode(&T, array[i]);
        if(isExecuteInsert)
            printf("\narray[%d]=%d Insert success.\n", i, array[i]);
        else
            printf("\narray[%d]=%d Insert failed.\n", i, array[i]);
    }
    for(int j=0; j<(sizeof(array)/sizeof(array[0])); j++)
        printf("-\t");
    printf("\n");
    printBiTree(T);
    printf("\n");
    for(int j=0; j<(sizeof(array)/sizeof(array[0])); j++)
        printf("-\t");
    printf("\n");
    
    return 0;
}
