#include "ballingHeader.h"

List * makelist(){
    List * list = malloc(sizeof(List));
    if(!list)
        return NULL;
    list->head = NULL;
    list->Tail = NULL;
    return list;
}

Node *CreateNode(int firstPoint, int secondPoint, int sumPoint,int totalBallPin,char *result){
    Node * NewNode = malloc(sizeof(Node));
    NewNode->firstBallPin = firstPoint;
    NewNode->secondBallPin = secondPoint;
    NewNode->sumBallPin = sumPoint;
    NewNode->totalSumBallPin = totalBallPin;
    NewNode->outcomeResult = result;
    NewNode->nextNode = NULL;
    NewNode->prevNode = NULL;
    return NewNode;
}

void AppendNode(List *list, int firstPoint, int secondPoint, int sumPoint, char  *result){
    Node *current = NULL;
    if(list->head == NULL){
        list->head = CreateNode(firstPoint, secondPoint,sumPoint,sumPoint,result);
        list->Tail = list->head;
    }
    else{
        current = list->head;
        while(current->nextNode !=NULL){
            current = current->nextNode;
        }
        current->nextNode = CreateNode(firstPoint, secondPoint,sumPoint,(current->totalSumBallPin)+sumPoint,result);
        current->nextNode->prevNode = current;
        list->Tail = current->nextNode;
    }

}

void showNode(List *list){
    Node * current = list->head;
    if(list->head ==NULL)
        return;
    while(current !=NULL){
        printf("1st: %d , 2nd: %d sum : %d,totalsum: %d, result: %s \n",current->firstBallPin, current->secondBallPin,current->sumBallPin,current->totalSumBallPin,current->outcomeResult);
        current = current->nextNode;
    }
}

int Middle_Func(){
    List *list = makelist();
    int round =0;
    int strikeFlag = 0;
    srand(time(NULL));
    for(int i=1; i<11; i++){
        printf("%d set\n",i);
        round = ChoiceNum(list,round);
        strikeFlag = PointSum(list,strikeFlag);
        showNode(list);
        printf("Press Enter to continue...");
        while (getchar() != '\n') {
        }
    }
    return 0;
}

int randomNumberSelect(int NumberRange){
    int selectNumber =0;
    selectNumber = rand() % NumberRange;
    return selectNumber;

}


int ChoiceNum(List *list,int round){
    int firstBallPin =0;
    int secondBallPin =0;
    int limitPoint = 0;
    int sumballPinPoint =0;
    limitPoint = 11;
    firstBallPin = randomNumberSelect(limitPoint);
    //firstBallPin = 10;

    if(firstBallPin == 10){
        StrikeFunc(list, firstBallPin);
    }
    else{
        limitPoint-=firstBallPin;
        secondBallPin = randomNumberSelect(limitPoint);
        sumballPinPoint = firstBallPin + secondBallPin;
        if(sumballPinPoint == 10){
            SpareFunc(list, firstBallPin,secondBallPin);
        }
        else{
            ExFunc(list,firstBallPin,secondBallPin);
        }
    }
    return ++round;
}

int StrikeFunc(List *list,int firstPoint){
    AppendNode(list,firstPoint,0,10,"Strike");
    return 0;
}

int SpareFunc(List *list,int firstPoint,int secondPoint){
    AppendNode(list,firstPoint,secondPoint,0,"Spare");
    return 0;
}

int ExFunc(List *list, int firstPoint, int secondPoint){
    AppendNode(list,firstPoint,secondPoint,firstPoint + secondPoint,"Split");
    return 0;
}

int PointSum(List *list, int strikeFlag){
    Node *tailList = NULL;
    int flagStrikeFind =0;
    tailList = list->Tail;
    while(tailList != NULL){
        flagStrikeFind ++;
        if(strikeFlag == 2){
            tailList->prevNode->sumBallPin=10 +(tailList->firstBallPin);
            tailList->totalSumBallPin+=tailList->prevNode->sumBallPin;
            strikeFlag = 0;
        }
        else if(strikeFlag == 3){
            tailList->prevNode->sumBallPin=10 +(tailList->firstBallPin)+(tailList->secondBallPin);
            tailList->totalSumBallPin+=tailList->prevNode->sumBallPin;
            if(strcmp(tailList->prevNode->outcomeResult,"Strike")){
                

            }
            strikeFlag = 0;
        }
        if(flagStrikeFind >2)
            break;
        tailList= tailList->prevNode;
    }
    if(!strcmp(list->Tail->outcomeResult,"Spare")){
        strikeFlag = 2;
    }
    else if(!strcmp(list->Tail->outcomeResult,"Strike")){
            strikeFlag = 3;
        }
    printf("flag : %d\n",strikeFlag);
    return strikeFlag;

}

