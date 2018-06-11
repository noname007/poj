/*
 * 3349.c
 * ref http://poj.org/showmessage?message_id=115742
 *  Created on: 2018年6月10日
 *      Author: yangzhen
 */

#ifdef __MAIN__
#define info_log(fmt, args...) printf(fmt,##args);
#else
#define info_log(fmt, args...)
#endif

#include <stdio.h>
#include <string.h>
//#include <stdlib.h>

typedef int SIX_ARMS[6];
typedef int * SIX_ARMS_P;

int is_same_snow(SIX_ARMS_P a, SIX_ARMS_P b) {

    int found = 0;
    for(int i = 0; i < 6; ++i) {
        if(b[i] == a[0]) {
           //
           found = 1;
           for (int j = 0, k = i; j < 6; ++j, ++k) {
               int mod_key = (k % 6  + 6) % 6;
               info_log("cmp %d:%d %d:%d\n", j,a[j], mod_key,b[mod_key]);

               if(a[j] != b[mod_key]){
                   found = 0;
                   break;
               }
           }

           if(found) {
               return found;
           }

           found = 1;
           for (int j = 0, k = i; j < 6; ++j, --k) {
               int mod_key = (k % 6  + 6) % 6;
               info_log("cmp %d:%d %d:%d\n", j,a[j],mod_key,b[mod_key]);
               if(a[j] != b[(k % 6  + 6) % 6]){
                   found = 0;
                   break;
               }
           }

           if(found) {
               return found;
           }
        }
    }
    return found;
}

typedef struct Node Node;
struct Node{
    SIX_ARMS data;
    Node * next;
};

Node Link[100005];
int map[100005];

#define SAME_SNOW 0
#define SUCCESSLY_ADD 1


int add_ele(Node * n, int hash_key) {
//    Node * t1 = &&Link[hash_key]; wrong usage
    Node * t = &Link[hash_key], ** t1 = &t;
//    info_log("%d\n", hash_key);
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
int poj_3349(int argc, char **argv){
#else
#define log(fmt, args...)
int main(int argc, char **argv) {
#endif

    int n;

    SIX_ARMS_P t;

    scanf("%d", &n);

    memset(map, -1, sizeof(map));

    for (int i = 0; i < n; ++i) {
        t = Link[i].data;
        scanf("%d %d %d %d %d %d",t, t+1, t+2, t+3, t+4, t+5);
        Link[i].next = NULL;

        int key = ((t[0] + t[2] + t[4]) ^ (t[1] + t[3] + t[5])) % 99991;

        int l_key = map[key];

        if(~l_key) {
            //!-1
            int res = add_ele(Link + i, l_key);

            if(res == SAME_SNOW) {
                printf("Twin snowflakes found.\n");
                return 0;
            }
        }else{
            // -1
            map[key] = i;
        }
    }
    printf("No two snowflakes are alike.\n");
    return 0;
}
