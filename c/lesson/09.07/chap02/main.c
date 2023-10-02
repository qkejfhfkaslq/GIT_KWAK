#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int static compare (const void* first, const void* second)
{
    if (*(int*)first > *(int*)second)
        return 1;
    else if (*(int*)first < *(int*)second)
        return -1;
    else
        return 0;
}

int main(void){
    int rand01, count, my_random;
    my_random = rand();
    srand(time(NULL)+my_random);
    int limit_count = 0;
    int flag =0;
    int list_number[6];
    int list_size =0;
    for(count =0; count<=5; count++){
        rand01 = ((rand())%45)+1;
        while(1){
            flag =0;
            for(limit_count =0; limit_count<count; limit_count++){
                if(rand01 == list_number[limit_count]){
                    flag =1;
                    rand01 = ((rand())%45)+1;
                }
            }
            if(flag ==0)
                break;
        }
        list_number[count] = rand01;
    }
    list_size = sizeof(list_number) / sizeof(int);

    qsort(list_number,list_size,sizeof(int),compare);
    for(int count = 0; count<=5; count++){
        printf("%d\n",list_number[count]);
    }

    return 0;
}


    
