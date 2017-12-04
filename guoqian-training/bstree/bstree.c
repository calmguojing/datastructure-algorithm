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


BSTreeNode *BSTree_Search_Traverse(BSTree tree, int key){
    if(tree == NULL || tree->key == key){
        return tree;
    }

    if(key < tree->key){
        return BSTree_Search_Traverse(tree->left, key);
    }else{
        return BSTree_Search_Traverse(tree->right, key);
    }
}

BSTreeNode *BSTree_Search_Iterate(BSTree tree, int key){
    if(tree == NULL || tree->key == key){
        return tree;
    }
    BSTreeNode *current = tree;
    while((current != NULL) && (current->key != key)){
        if(key < current->key){
            current = current->left;
        }else{
            current = current->right;
        }
    }
    return current;
}
BSTreeNode *BSTree_Minimum(BSTree tree){
    if(tree == NULL){
        return tree;
    }

    BSTreeNode *current = tree;
    while(current->left != NULL){
        current = current->left;
    }

    return current;
}


BSTreeNode *BSTree_Maximum(BSTree tree){
    if(tree == NULL){
        return tree;
    }

    BSTreeNode *current = tree;
    while(current->right != NULL){
        current = current->right;
    }

    return current;
}


BSTreeNode *BSTree_Successor(BSTreeNode *node){
    BSTreeNode *parent = NULL;
    BSTreeNode *current = node;
    if(node == NULL){
        return NULL;
    }

    if(node->right != NULL){
        return BSTree_Minimum(node->right);
    }

    parent = node->parent;
    while((parent != NULL) && (current == parent->right)){
        current = parent;
        parent = parent->parent;
    }

    return parent;
}

BSTreeNode *BSTree_Predecessor(BSTreeNode *node){
    BSTreeNode *parent = NULL;
    BSTreeNode *current = node;

    if(node == NULL){
        return NULL;
    }

    if(node->left != NULL){
        return BSTree_Maximum(node->left);
    }

    parent = node->parent;
    while((parent != NULL) && (current == parent->left)){
        current = parent;
        parent = parent->parent;
    }

    return parent;
}

static BSTreeNode *BSTree_Delete_Node(BSTree tree, BSTreeNode *node){
    BSTreeNode *real = NULL;
    BSTreeNode *child = NULL;
    
    if((node->left == NULL) || (node->right == NULL)){
        real = node;
    }else{
        real = BSTree_Successor(node);
    }
    
    if(real->left != NULL){
        child = real->left;
    }else{
        child = real->right;
    }

    if(child != NULL){
        child->parent = real->parent;
    }
    
    if(real->parent == NULL){
        tree = child;
    }else if(real == real->parent->left){
        real->parent->left = child;
    }else{
        real->parent->right = child;
    }

    if(real != node){
        node->key = real->key;
    }

    return real;

}
BSTreeNode *BSTree_Delete(BSTree tree, int key){
    BSTreeNode *node;
    if((node = BSTree_Search_Traverse(tree, key)) != NULL){
       return BSTree_Delete_Node(tree, node);
    }
}

