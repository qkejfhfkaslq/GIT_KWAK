#ifndef LCRS_TREE_H
#define LCRS_TREE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct tagLCRSNode{
    struct tagLCRSNode* LeftChild;
    struct tagLCRSNode* RightSibling;
    
    char Data;
}LCRSNode;

LCRSNode* LCRS_CreateNode (char NewData);

void LCRS_DestroyNode(LCRSNode *Node);

void LCRS_DestroyTree(LCRSNode *Root);

void LCRS_AddChildNode(LCRSNode *Parent, LCRSNode *Child);

void LCRS_PrintTree(LCRSNode *Node, int Depth);

#endif

