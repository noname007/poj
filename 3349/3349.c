/*
 * 3349.c
 * ref http://poj.org/showmessage?message_id=115742
 *  Created on: 2018年6月10日
 *      Author: yangzhen
 */


#include <stdio.h>
//#include <stdlib.h>

typedef int SIX_ARMS[6];
typedef int * SIX_ARMS_P;

int is_same_snow(SIX_ARMS_P a, SIX_ARMS_P b) {

}

typedef struct Node Node;
struct Node{
    SIX_ARMS data;
    Node * next;
}Node;

Node Link[100005];
int map[100005];

#define SAME_SNOW 0
#define SUCCESSLY_ADD 1

int add_ele(Node * n, int hash_key) {
//    Node * t1 = &&Link[hash_key]; wrong usage
    Node * t = &Link[hash_key], ** t1 = &t;

    while(*t1){
        if(is_same_snow((*t1)->data, n->data)) {
            return SAME_SNOW;
        }
       t1 = &((*t1)->next);
    }
    *t1 = n;
    return SUCCESSLY_ADD;
}

#ifdef __MAIN__
#define log(fmt, args...) printf(fmt,##args);
#else
#define log(fmt, args...)
#endif

#ifdef __MAIN__
#define log(fmt, args...) printf(fmt,##args);
int poj_2299(int argc, char **argv){
#else
#define log(fmt, args...)
int main(int argc, char **argv) {
#endif

    int n;

    int * t;

    scanf("%d", &n);

    Node * t1;
    memset(map, -1, sizeof(map));

    for (int i = 0; i < n; ++i) {
        t = Link[i].data;
        scanf("%d %d %d %d %d %d",t, t+1, t+2, t+3, t+4, t+5);
        Link[i].next = NULL;

        int key = map((t[0] + t[2] + t[4]) ^ (t[1] + t[3] + t[5])) % 99991;


        int l_key = map[key];

        if(~l_key) {
            //!-1
            int res = add_ele(Link + i, l_key);

        }else{
            // -1
            map[key] = i;
        }
    }


}
