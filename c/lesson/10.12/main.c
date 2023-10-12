#include <stdio.h>
#include <stdlib.h>

int sort(int num,int num2){
    if(num > num2)
        return num;
    else
        return num2;

}


int main(void){
    //int c[10]= {22,67,12,55,8,3,72,34,66,7};

    int *a;
    int count;
    int b,j;
    int count_list;
    printf("몇개의 문자를 넣으실건가요?\n");
    scanf("%d",&count_list);
    if(count_list >1000){
        printf("숫자가 너무 커요\n");
        exit(1);
    }

    a=malloc(sizeof(int)*count_list);
    a[0] =22;
    a[1] =67;
    a[2] =12;
    a[3] =55;
    a[4] =89;
    a[5] =3;
    a[6] =72;
    a[7] =34;
    a[8] =66;
    a[9] =7;


    for(count =0; count<count_list-1; count++){
        for(j=0; j<(count_list-count)-1; j++){
            if(a[j] >a[j+1]){
                b = a[j];
                a[j] = a[j+1];
                a[j+1] = b;
            }
        }

    }
    for(count =0; count<count_list; count++){
        printf("%d\n",a[count]);
    }


    free(a);
    return 0;
}

