#ifndef BALLINGHEADER_H
#define BALLINGHEADER_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>


typedef struct tagNode{
    int firstBallPin;
    int secondBallPin;
    int sumBallPin;
    int totalSumBallPin;
    int round;
    struct tagNode *nextNode;
    struct tagNode *prevNode;
    char *outcomeResult;
} Node;

typedef struct list{
    Node * head;
    Node *Tail;
}List;

List * makelist();
Node *CreateNode(int firstPoint, int secondPoint,int sumPoint,int totalBallPin,char *result);

void AppendNode(List *list, int firstPoint, int secondPoint,int sumPoint, char* result);
void showNode(List *list);
int ChoiceNum(List *list,int round);
int Middle_Func();
int StrikeFunc(List *list,int firstPoint);
int SpareFunc(List *list,int firstPoint,int secondPoint);
int ExFunc(List *list, int firstPoint, int secondPoint);
int PointSum(List *list,int strikeFlag);
#endif
