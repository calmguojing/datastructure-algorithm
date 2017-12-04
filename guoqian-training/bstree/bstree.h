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

BSTreeNode *BSTree_Search_Traverse(BSTree tree, int key);

BSTreeNode *BSTree_Search_Iterate(BSTree tree, int key);

BSTreeNode *BSTree_Minimum(BSTree tree);

BSTreeNode *BSTree_Maximum(BSTree tree);

BSTreeNode *BSTree_Successor(BSTreeNode *node);

BSTreeNode *BSTree_Predecessor(BSTreeNode *node);

BSTree BSTree_Delete(BSTree tree, int key);
#endif
