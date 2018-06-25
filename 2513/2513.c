/*
 * 2512.c
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


#define BIG_PRIME 250043

char color[BIG_PRIME][12];
int color_kind_id = 0;

int degree[BIG_PRIME];

int hashtable[BIG_PRIME + 20];
int next[BIG_PRIME + 20];

int parent [BIG_PRIME];

static int hash_str(const char * v) {
    int str_len = strlen(v);
    int vv = 0;
    for (int i = 0; i < str_len; ++i) {
        vv = ((vv * 10 + v[i] ) % BIG_PRIME + BIG_PRIME) % BIG_PRIME;
    }
    info_log("--->hash['%s'] = %d\n",v,vv);
    return vv;
}

static void init_hashtable() {
    memset(hashtable, -1 ,sizeof(hashtable));
    memset(next, -1 ,sizeof(next));
    memset(degree, 0, sizeof(degree));
    memset(parent, -1, sizeof(parent));
}


static int find_by_str(const char * key) {
    int k = hash_str(key);
    for(int e = hashtable[k]; ~e ; e = next[e] ) {
        if(strcmp(key, color[e]) == 0){
            return e;
        }
    }
    return -1;
}

static void add_ele_by_str(const char * key, int value) {
    int k = find_by_str(key);

    if(~k)
        return ;

    int kk = hash_str(key);
    next[value] = hashtable[kk];
    hashtable[kk] = value;
}


int add_color(const char * c) {
    int color_id = find_by_str(c);
    if(~color_id){

    }else{
        color_id = ++color_kind_id;
        add_ele_by_str(c, color_id);
        strcpy(color[color_id], c);
        info_log("color[%d] = %s\n",color_id, color[color_id]);
    }

    ++ degree[color_id];

    return color_id;
}

int union_find(int i) {
    return parent[i] == -1 ? i : (parent[i] = union_find(parent[i]));
}

static void merge(int a, int b) {
    int fa = union_find(a);
    int fb = union_find(b);
    info_log("a:%d:%d  b:%d:%d", a, fa, b, fb);
    if(fa != fb)
        parent[fb] = fa;
}

#ifdef __MAIN__
int poj_2513(int argc, char **argv){
#else
#define info_log(fmt, args...)
int main(int argc, char **argv) {
#endif

    //
    //
    /*
     *
     *
     √blue red
    red violet
    cyan blue
    blue magenta
    magenta cyan
    dd aa
    */
    char one[15],two[15];

    init_hashtable();

    int one_id = -1,two_id = -1;
    while(~scanf("%s%s", one, two)){
        one_id = add_color(one);
        if(one_id > BIG_PRIME - 10 ) {
            printf("Impossible\n");
            return 0;
        }
        two_id = add_color(two);
        if(two_id > BIG_PRIME - 10 ) {
            printf("Impossible\n");
            return 0;
        }
        merge(one_id, two_id);
    }

    int oddnum = 0;
    int subgraph = 0;

    for (int i = 1; i <= color_kind_id; ++i) {
        info_log("%d:%s ---> degree:%d--->parent:%d\n", i, color[i], degree[i], parent[i]);
    }
    for (int i = 1; i <= color_kind_id; ++i) {
        if(degree[i] % 2){
            ++ oddnum;
        }

        if(union_find(i) == i) {
            ++ subgraph;
        }

        if(oddnum == 3 || subgraph == 2) {
            printf("Impossible\n");
            return 0;
        }
    }

    info_log("oddnum：%d subgraph:%d\n", oddnum, subgraph);

    printf("Possible\n");
    return 0;
}
