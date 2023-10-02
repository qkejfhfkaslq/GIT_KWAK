#include "ArrayStack.h"

void AS_CreateStack(ArrayStack **Stack, int Capacity){
    (*Stack) = malloc(sizeof(ArrayStack));

    (*Stack)->Nodes = malloc(sizeof(Node)*Capacity);

    (*Stack)->Capacity = Capacity;
    (*Stack)->Top = -1;
}

void AS_DestroyStack(ArrayStack *Stack){
    free(Stack->Nodes);

    free(Stack);
}

void AS_Push(ArrayStack *Stack, int Data){
    Stack->Top++;
    Stack->Nodes[Stack->Top].Data = Data;
    printf("%d\n",Stack->Nodes[Stack->Top].Data);
}

int AS_Pop(ArrayStack *Stack){
    int Position = Stack->Top--;
    return Stack->Nodes[Position].Data;
}

int AS_Top(ArrayStack *Stack){
    return Stack->Nodes[Stack->Top].Data;
}

int AS_GetSize(ArrayStack *Stack){
    return Stack->Top+1;
}

int AS_IsEmpty(ArrayStack *Stack){
    return (Stack->Top == -1);
}

