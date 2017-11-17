#include "SeqList.h"
#include <malloc.h>
#include <stdio.h>

typedef unsigned int TSeqListNode;

typedef struct _tag_SeqList{
    int capacity;
    int length;
    TSeqListNode *node;
}TSeqList;

SeqList *SeqList_Create(int capacity){
    TSeqList *ret = NULL;

    if(capacity >= 0){
        ret = (TSeqList *)malloc(sizeof(TSeqList) + sizeof(TSeqListNode) * capacity);
    }

    if(ret != NULL){
        ret->capacity = capacity;
        ret->length = 0;
        ret->node = (TSeqListNode *)(ret + 1);
    }

    return ret;
}

void SeqList_Destroy(SeqList *list){
    free(list);
}

void SeqList_Clear(SeqList *list){
    TSeqList *sList = (TSeqList *)list;

    if(sList != NULL){
        sList->length = 0;
    }
}

int SeqList_Length(SeqList *list){
    TSeqList *sList = (TSeqList *)list;

    if(sList != NULL){
        return sList->length;
    }
}

int SeqList_Capacity(SeqList *list){
    TSeqList *sList = (TSeqList *)list;

    if(sList != NULL){
        return sList->capacity;
    }
}

int SeqList_Insert(SeqList *list, SeqListNode *node, int pos){
    TSeqList *sList = (TSeqList *)list;
    int ret = (sList != NULL);
    int i =0;

    ret = ret && (sList->length + 1 <= sList->capacity) && (pos >= 0);

    if(ret){
        if(pos >= sList->length){
            pos = sList->length;
        }

        for(i=sList->length; i>pos; i--){
            sList->node[i] = sList->node[i-1];
        }

        sList->node[i] = (TSeqListNode)node;

        sList->length++;
    }

    return ret;
}

SeqListNode *SeqList_Get(SeqList *list, int pos){
    TSeqList *sList = (TSeqList *)list;

    if((sList != NULL) && (pos >= 0) && (pos < sList->length)){
        return (SeqListNode *)sList->node[pos];
    }
}

SeqListNode *SeqList_Delete(SeqList *list, int pos){
    TSeqList *sList = (TSeqList *)list;
    SeqListNode *ret = SeqList_Get(list, pos);
    int i = 0;
    if(ret != NULL){
        for(i=pos; i<sList->length; i++){
            sList->node[i] = sList->node[i+1];
        }
        sList->length--;
    }
    
    return ret;
}
