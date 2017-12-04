#include "bstree.h"
#include <stdio.h>
#include <stdlib.h>

static int arr[] = {5, 8, 2, 9, 0, 3, 4, 6, 7, 1};

#define arr_size(a) ((sizeof(a)) / (sizeof(a[0])))

int main(){
    int i, len;
    BSTree tree = NULL;

    len = arr_size(arr);

    for(i=0; i<len; i++){
        tree = BSTree_Insert(tree, arr[i]);
    }

    printf("\npretraverse\n");

    BSTree_PreTraverse(tree);
    printf("\n");
    BSTree_MidTraverse(tree);
    printf("\n");
    BSTreeNode *s = BSTree_Search_Traverse(tree, 8);
    printf("%d\n", s->key);
    BSTreeNode *r = BSTree_Search_Iterate(tree, 4);
    printf("%d\n", r->key);
    BSTreeNode *min = BSTree_Minimum(tree);
    printf("min:%d\n", min->key);
    BSTreeNode *max = BSTree_Maximum(tree);
    printf("max:%d\n", max->key);
    BSTreeNode *su = BSTree_Successor(tree);
    printf("%d\n", su->key);
    BSTreeNode *pre = BSTree_Predecessor(tree);
    printf("%d\n", pre->key);

    BSTreeNode *de = BSTree_Delete(tree, 5);
    printf("\npretraverse\n");
    BSTree_PreTraverse(tree);
    printf("\n");
}
