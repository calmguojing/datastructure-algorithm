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
}
