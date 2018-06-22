/*
 * 2002.c
 *
 *  Created on: 2018年6月20日
 *      Author: yangzhen
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#ifdef __MAIN__1
#define info_log(fmt, args...) printf("%s:%d:%s "fmt,__FILE__,__LINE__,__FUNCTION__,##args);
#define info_log_point_p(p,msg) info_log(msg"Poinx{x:%d,y:%d}\n",(p)->x, (p)->y)
#else
#define info_log(fmt, args...)
#define info_log_point_p(p,msg) info_log(msg"Poinx{x:%d,y:%d}\n",(p)->x, (p)->y)
#endif

typedef struct Point Point;

struct Point {
        int x;
        int y;
};

Point Points[1005];

#define BIG_PRIME 9973

short hashtable[BIG_PRIME];
short next[BIG_PRIME];

static int hash(const Point * v) {
    int vv =  (((v->x * 10 + 2969 ) % BIG_PRIME + v->y ) % BIG_PRIME + BIG_PRIME) % BIG_PRIME;
    info_log("Poinx{x:%d,y:%d}:calculated hash value:%d\n",v->x,v->y,vv);
    return vv;
}

void init_hashtable() {
    memset(hashtable, -1 ,sizeof(hashtable));
    memset(next, -1 ,sizeof(next));
}

int find(const Point * key) {
    int k = hash(key);
    info_log_point_p(key,"")
    for(int e = hashtable[k]; ~e ; e = next[e] ) {

        info_log("%d------",e)
        info_log_point_p(&(Points[e]), "cmp the point")
//        if(key->x == Points[e].x && key->y == Points[e].y) {
//            return e;
//        }
       if(memcmp(key, &(Points[e]), sizeof(Point)) == 0) {
           return e;
       }
    }
    return -1;
}

static void add_ele(const Point * key, int value) {
    int k = find(key);
    info_log_point_p(key,"add ele key")
    info_log("add ele value---------%d\n", value)
    info_log("add ele key---------\n")

    if(~k)
        return;

    int kk = hash(key);
    next[value] = hashtable[kk];
    hashtable[kk] = value;
}

int cmp(const void * a, const void * b) {
    const Point * aa = a;
    const Point * bb = b;

    if(aa->x == bb->x) {
        return aa->y - bb->y;
    }

    return aa->x - bb->x;
}

#ifdef __MAIN__
int poj_2002(int argc, char **argv){
#else
#define info_log(fmt, args...)
int main(int argc, char **argv) {
#endif

    int points_num;

    while(~scanf("%d", &points_num) && points_num) {
        Point *p = Points;

        init_hashtable();

        for (int i = 0; i < points_num; ++i) {
            scanf("%d%d", &(p->x), &(p->y));
            ++p;
        }

        qsort(Points,points_num, sizeof(Point), cmp);
        p = Points;

        for (int i = 0; i < points_num; ++i) {
            add_ele(p++, i);
        }

        Point Temp;

        int ans = 0;
        for (int i = 0; i < points_num; ++i) {
            info_log_point_p(&Points[i], "----i:----")
            for (int j = i + 1; j < points_num; ++j) {

                info_log_point_p(&Points[j], "----j:----")

                Temp.x = Points[i].x + Points[i].y - Points[j].y;
                Temp.y = Points[i].y + Points[j].x - Points[i].x;

                if(!~find(&Temp)) {
                    continue;
                }

                Temp.x = Points[j].x + Points[i].y - Points[j].y;
                Temp.y = Points[j].y + Points[j].x - Points[i].x;

                if(!~find(&Temp)) {
                    continue;
                }

                ++ans;
            }
        }

        printf("%d\n", ans/2);

    }
    return 0;
}
