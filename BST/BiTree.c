#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _BitNode
{
    int data;
    struct _BitNode *leftChild, *rightChild;
}BitNode, *BiTree;


bool searchBiTree(BiTree T, int key, BiTree pre, BitNode *B)
{
    if(!T)
    {
        B = pre;
        return false;
    }
    else if(key == T->data)
    {
        B = T;
        return true;
    }
    if(key < T->data)
    {
        searchBiTree(T->leftChild, key, T, B);
    }
    else if(key > T->data)
    {
        searchBiTree(T->rightChild, key, T, B);
    }
}

bool insertBitNode(BiTree T, int key)
{
    BitNode *Bn = NULL, *tmp = NULL;
    if(!searchBiTree(T, key, NULL, Bn))
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
            T = tmp;
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

int main(){
    BitNode *B;
    BiTree T = NULL;
    bool result = searchBiTree(T, 1, NULL, B);
    printf("Test...%d\n", result);
    bool isExecuteInsert = insertBitNode(T, 20);
    printf("----...%d, %d", isExecuteInsert, T);
    return 0;
}
