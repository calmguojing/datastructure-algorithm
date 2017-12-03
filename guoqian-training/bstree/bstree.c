#include <stdio.h>
#include "bstree.h"
#include <malloc.h>

BSTreeNode *BSTreeNode_Create(int key, BSTreeNode *left, BSTreeNode *right, BSTreeNode *parent){
    BSTreeNode *ret = (BSTreeNode *)malloc(sizeof(BSTreeNode));

    if(ret != NULL){
        ret->key = key;
        ret->left = left;
        ret->right = right;
        ret->parent = parent;
    }

    return ret;
}

static BSTree BSTreeNode_Insert(BSTree tree, BSTreeNode *node){
    if(tree != NULL){
        BSTreeNode *current = tree;
        BSTreeNode *parent = NULL;

        while(current != NULL){
            parent = current;

            if(node->key < current->key){
                current = current->left;
            }else{
                current = current->right;
            }
        }

        node->parent = parent;

        if(parent == NULL){
            tree = node;
        }else{
            if(node->key < parent->key){
                parent->left = node;
            }else{
                parent->right = node;
            }
        }
    }

    return tree;
}

BSTree BSTree_Insert(BSTree tree, int key){
    BSTreeNode *newnode = (BSTreeNode *)malloc(sizeof(BSTreeNode));
    BSTree ret = NULL;
    if(newnode != NULL){
        newnode->key = key;
        newnode->left = NULL;
        newnode->right = NULL;
        newnode->parent = NULL;
    }
    BSTreeNode *current = tree;
    BSTreeNode *parent = NULL;

    while(current != NULL){
        parent = current;

        if(newnode->key < current->key){
            current = current->left;
        }else{
            current = current->right;
        }
    }

    newnode->parent = parent;

    if(parent == NULL){
       tree = newnode;
    }else{
        if(newnode->key < parent->key){
            parent->left = newnode;
        }else{
            parent->right = newnode;
        }
    }

    return tree;
}


void BSTree_PreTraverse(BSTree tree){
    if(tree != NULL){
        printf("%d", tree->key);
        BSTree_PreTraverse(tree->left);
        BSTree_PreTraverse(tree->right);
    }
}

void BSTree_MidTraverse(BSTree tree){
    if(tree != NULL){
        BSTree_MidTraverse(tree->left);
        printf("%d", tree->key);
        BSTree_MidTraverse(tree->right);
    }
}

void BSTree_PostTraverse(BSTree tree){
    if(tree != NULL){

        BSTree_PostTraverse(tree->left);
        BSTree_PostTraverse(tree->right);
        printf("%d", tree->key);
    }
}
