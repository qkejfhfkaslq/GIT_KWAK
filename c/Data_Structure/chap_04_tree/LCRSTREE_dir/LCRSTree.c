#include "LCRSTree.h"

LCRSNode* LCRS_CreateNode(char *NewData){
    LCRSNode *NewNode = (LCRSNode*)malloc(sizeof(LCRSNode));
    NewNode->LeftChild = NULL;
    NewNode->RightSibling = NULL;
    NewNode->Data = malloc(strlen(NewData)+1);
    strcpy(NewNode->Data,NewData);


    return NewNode;
}

void LCRS_DestroyNode(LCRSNode *Node){
    free(Node);
}

void LCRS_DestroyTree(LCRSNode *Root){
    if (Root->RightSibling !=NULL)
        LCRS_DestroyTree(Root->RightSibling);

    if(Root->LeftChild !=NULL)
        LCRS_DestroyTree(Root->LeftChild);

    Root->LeftChild = NULL;
    Root->RightSibling = NULL;
    free(Root->Data);
    LCRS_DestroyNode(Root);
}

void LCRS_AddChildNode(LCRSNode *Parent, LCRSNode *Child){
    if(Parent->LeftChild == NULL){
        Parent->LeftChild = Child;
    }
    else{
        LCRSNode *TempNode = Parent->LeftChild;
        while(TempNode->RightSibling !=NULL)
            TempNode = TempNode->RightSibling;

        TempNode->RightSibling = Child;
    }
}

void LCRS_PrintTree(LCRSNode *Node, int Depth){

    int i=0;
    for(i=0; i<Depth-1; i++)
        printf("   ");

    if(Depth >0)
        printf("+--");

    printf("%s\n", Node->Data);

    if(Node->LeftChild != NULL)
        LCRS_PrintTree(Node->LeftChild, Depth+1);

    if(Node->RightSibling !=NULL)
        LCRS_PrintTree(Node->RightSibling, Depth);
}



void Dir_List(char *current_Dir, LCRSNode *Parent){
    DIR *dir_info;
    struct dirent *dir_entry;
    char *current_Dir_file = NULL;
    current_Dir_file = malloc(1024);
    dir_info = opendir(current_Dir);
    if(NULL !=dir_info){
        while((dir_entry = readdir(dir_info)) != NULL){
            if(strcmp(dir_entry->d_name,".") && strcmp(dir_entry->d_name,"..") && strcmp(dir_entry->d_name,".git") && strcmp(dir_entry->d_name,".gitignore")  ){

                strcpy(current_Dir_file,current_Dir);
                strcat(current_Dir_file, "/");
                strcat(current_Dir_file, dir_entry->d_name);
                LCRSNode *Child = LCRS_CreateNode(dir_entry->d_name);
                LCRS_AddChildNode(Parent, Child);
                if(dir_entry->d_type == DT_DIR){
                    Dir_List(current_Dir_file,Child);
                }
            }
        }
    }
    free(current_Dir_file);
    closedir(dir_info);
}



