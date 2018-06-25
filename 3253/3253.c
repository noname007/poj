/*
 * 3253.c
 *
 * ref http://poj.org/showmessage?message_id=355271
n块小木板，只要锯n-1次，时光倒流的想法，使得每一次锯的木板最短。
所以，每次合并最短的两块小木板，那么这一次锯的就是这块合并后的木板，并且它一定是所有这一次可能会锯的木板中最小的。
采用优先队列小根堆实现，先将n块木板放入队列中，每次取出队首的两块，做合并，合并后的木板当做一块再放入队列中，直到合并了n-1次。输出ans即可。
注意：1.ans要开long long
     2.正向考虑时每次锯下n块中最长的，这种贪心是不行的。因为无法保证比先分成几组再分组锯的花费少。
       例如：4块 7 6 5 4。 采用这种方法锯出来是46，而答案是44.实际上应该先锯出13、9两块再分组锯。
附上代码：（29行，16ms，316K）

#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<queue>
using namespace std;
int n;
long long ans;
priority_queue<int,vector<int>,greater<int> >q;
int main()
{
    scanf("%d",&n);
    int t;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&t);
        q.push(t);
    }
    for(int i=1;i<=n-1;i++)
    {
        int a=q.top();q.pop();
        int b=q.top();q.pop();
        ans=ans+a+b;
        q.push(a+b);
    }
    printf("%lld",ans);
    return 0;
}
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
