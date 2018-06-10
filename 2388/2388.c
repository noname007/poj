/*
 * 2388.c
 *
 *  Created on: 2018年6月10日
 *      Author: yangzhen
 */



#include <stdio.h>
#include <stdlib.h>

int milk_output[10005];

int compar(const void * a, const void * b) {
     int * a1 = ( int * ) a;
     int * a2 = ( int * ) b;
     return *a1 - *a2;
}

#ifdef __MAIN__
int poj_2388(int argc, char **argv){
#else
int main(int argc, char **argv) {
#endif

    int n;
    scanf("%d", & n);
    int * p = milk_output;

    for (int i = 0; i < n; ++i) {
        scanf("%d",p++);
    }

    qsort(milk_output, n, sizeof(int),compar);

//    p = milk_output;
//    for (int i = 0; i < n; ++i) {
//        printf("%d\n", *p++);
//    }

    printf("%d\n", milk_output[n/2]);

}

