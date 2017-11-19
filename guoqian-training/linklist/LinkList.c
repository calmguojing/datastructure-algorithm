#include "LinkList.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


typedef struct _tag_LinkList{
    LinkListNode header;
    int length;
}TLinkList;


LinkList *LinkList_Create(){
    TLinkList *ret = (TLinkList *)malloc(sizeof(TLinkList));

    if(ret != NULL){
        ret->header.next = NULL;
        ret->length = 0;
    }

    return ret;
}

void LinkList_Destroy(LinkList *list){
    free(list);
}

void LinkList_Clear(LinkList *list){
    TLinkList *sList = (TLinkList *)list;

    if(sList != NULL){
        sList->header.next = NULL;
        sList->length = 0;
    }
}

int LinkList_Length(LinkList *list){
    TLinkList *sList = (TLinkList *)list;

    if(sList != NULL){
        return sList->length;
    }
}

int LinkList_Insert(LinkList *list, LinkListNode *node, int pos){
    TLinkList *sList = (TLinkList *)list;
    int ret = (sList != NULL) && (pos >= 0) && (node != NULL);
    int i = 0;

    if(ret){
        LinkListNode *current = (LinkListNode *)sList;

        for(i=0; (i<pos) && (current->next != NULL); i++){
            current = current->next;
        }

        node->next = current->next;
        current->next = node;
        
        sList->length++;
    }

    return ret;
}

LinkListNode *LinkList_Get(LinkList *list, int pos){
    TLinkList *sList = (TLinkList *)list;
    int i = 0;

    if((sList != NULL) && (pos >=0) && (pos < sList->length)){
        LinkListNode *current = (LinkListNode *)sList;

        for(i=0; i<pos; i++){
            current = current->next;
        }


        return current->next;
    }
}

LinkListNode *LinkList_Delete(LinkList *list, int pos){
    TLinkList *sList = (TLinkList *)list;
    LinkListNode *ret = NULL;
    int i = 0;

    if((sList != NULL) && (pos >= 0) && (pos < sList->length)){
        LinkListNode *current = (LinkListNode *)sList;

        for(i=0; i<pos; i++){
            current = current->next;
        }
        ret = current->next;
        current->next = ret->next;

        sList->length--;
    }

    return ret;
}
