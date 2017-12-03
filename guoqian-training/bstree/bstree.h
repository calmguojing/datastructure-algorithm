#ifndef _BSTREE_H_
#define _BSTREE_H_


typedef struct  _tag_BSTreeNode BSTreeNode;
struct _tag_BSTreeNode{
    int key;
    BSTreeNode *left;
    BSTreeNode *right;
    BSTreeNode *parent;
};

typedef BSTreeNode *BSTree;

BSTree BSTree_Insert(BSTree tree, int key);

void BSTree_PreTraverse(BSTree tree);

void BSTree_MidTraverse(BSTree tree);

void BSTree_PostTraverse(BSTree tree);




#endif
