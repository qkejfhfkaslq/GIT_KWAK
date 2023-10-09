#include "LCRSTree.h"

int main(void){
    LCRSNode *Root = LCRS_CreateNode("/root/python");
    Dir_List("/root/python",Root);
    LCRS_PrintTree(Root,0);
    LCRS_DestroyTree(Root);

    return 0;
}


