#include "LinkList.h"
#include <stdlib.h>
#include <stdio.h>

struct value{
    LinkListNode header;
    int val;
};

int main(){
    int i = 0;
    LinkList *list = LinkList_Create();

    struct value v1;
    struct value v2;
    struct value v3;
    struct value v4;
    struct value v5;
    struct value v6;

    v1.val = 1;
    v2.val = 2;
    v3.val = 3;
    v4.val = 4;
    v5.val = 5;
    v6.val = 6;

    LinkList_Insert(list, (LinkListNode *)&v1, LinkList_Length(list));
    LinkList_Insert(list, (LinkListNode *)&v2, LinkList_Length(list));
    LinkList_Insert(list, (LinkListNode *)&v3, LinkList_Length(list));
    LinkList_Insert(list, (LinkListNode *)&v4, LinkList_Length(list));
    LinkList_Insert(list, (LinkListNode *)&v5, LinkList_Length(list));
    LinkList_Insert(list, (LinkListNode *)&v6, LinkList_Length(list));

    for(i=0; i<LinkList_Length(list); i++){
        struct value *v = (struct value *)LinkList_Get(list, i);

        printf("%d\n", v->val);
    }

    while(LinkList_Length(list) > 0){
        struct value *v = (struct value *)LinkList_Delete(list, 0);

        printf("%d\n", v->val);
    }

    LinkList_Destroy(list);

    return 0;
}
