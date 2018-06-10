/*
 * 2299.c
 *
 *  Created on: 2018年6月10日
 *      Author: yangzhen
 */
#include <stdio.h>
//#include <stdlib.h>

int input[500005];

static long long int swap_num = 0;

int temp[500005];

void merge(int * base, int start,int mid, int end) {

    printf("merge: [%d %d) [%d %d)\n", start,  mid, mid, end );
    int temp_index = start;
    int i = start, j = mid;

    while( i < mid && j < end) {
        printf("cmp %d:%d %d:%d\n",i,base[i],j,base[j]);
        if(base[i] <=  base[j]) {
            temp[temp_index] = base[i];
            ++i;
        }else{
            temp[temp_index] = base[j];
            ++j;
        }
        ++temp_index;
    }

    while(i < mid) {
        temp[temp_index ++] = base[i ++];
    }

    for (int k = start; k < temp_index; ++k) {
       base[start] = temp[k];
       ++ start;
    }
}


void mergesort(int * base, int start, int end) {
    printf("[%d %d)\n", start, end);
    if(start + 1 >= end) {
        return ;
    }

    int mid = (start + end)/2;
    mergesort(base, start, mid);
    mergesort(base, mid, end);
    merge(base, start,  mid, end);
}



#ifdef __MAIN__
int poj_2299(int argc, char **argv){
#else
int main(int argc, char **argv) {
#endif

    int input_num;
    while(~scanf("%d", & input_num) && input_num){

        swap_num = 0;
        int * p = input;
        for (int i = 0; i < input_num; ++i) {
            scanf("%d", p++);
        }

        mergesort(input, 0, input_num);

        p = input;
        for (int i = 0; i < input_num; ++i) {
            printf("%d\n", *p++);
        }

//        printf("%lld\n", swap_num);
    }

    return 0;
}
