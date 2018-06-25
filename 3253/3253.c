/*
 * 3253.c
 *
 *  Created on: 2018年6月25日
 *      Author: yangzhen
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#ifdef __MAIN__
#define info_log(fmt, args...) printf("%s:%d:%s "fmt,__FILE__,__LINE__,__FUNCTION__,##args);
#else
#define info_log(fmt, args...)
#define info_log_point_p(p,msg) info_log(msg"Poinx{x:%d,y:%d}\n",(p)->x, (p)->y)
#endif


#define printf_heap \
    for (int i = 1; i <= heapsize; ++i) { \
        info_log("heap[%d]= %d\n", i,L[i]) \
    }\

int L[50005];

#define swap(a,b) {\
    int temp  = a;\
    a = b; \
    b = temp;\
}

void buildheap(int size) {

}

int heapsize;

void shiftup(int pos) {

    int parent  = pos >> 1;
    while(parent) {

        if(L[parent] > L[pos]){
           swap(L[parent], L[pos])
        }else{
            break;
        }

        pos = parent;
        parent >>= 1;
    }
}

void insert(int ele) {
    ++heapsize;
    info_log("inserting %d heapsize:%d\n",ele, heapsize);
    L[heapsize] = ele;
    shiftup(heapsize);
}

//heap ---- 下标范围 [1,N]

int pop_min() {

    if(heapsize < 1){
           return -1; //need enhencement
    }
    info_log("\n-----------------------------------------\n")
    printf_heap

    int t = L[1];
    L[1] = L[heapsize -- ];



    int pos = 1;

    int left =  pos << 1;
    int right = left + 1;

    while(left <= heapsize) {

        int child = left;

        if(right < heapsize &&  L[right] < L[left]) {
            child = right;
        }

        if(L[pos] > L[child]) {
            swap(L[pos], L[child])
        }else{
            break;
        }

        pos = child;
        left =  pos << 1;
        right = left + 1;
    }

    printf_heap

    info_log("pop the min:%d\n\n",t);

    return t;
}



#ifdef __MAIN__
int poj_3253(int argc, char **argv){
#else
#define info_log(fmt, args...)
int main(int argc, char **argv) {
#endif

    int N, *p = L + 1;
    scanf("%d", &N);

    for (int i = 0; i < N; ++i, ++p) {
        scanf("%d",p);
        shiftup(i + 1);
        ++heapsize;
    }

    long long sum = 0;

    int t = 0;
    while(heapsize > 1) {
        t = pop_min() + pop_min();
        insert(t);
        sum += t;
    }

    printf("%lld", sum);
    return 0;
}
