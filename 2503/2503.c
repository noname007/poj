/*
 * 2503.c
 *
 *  Created on: 2018年6月23日
 *      Author: yangzhen
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#ifdef __MAIN__
#define info_log(fmt, args...) //printf("%s:%d:%s "fmt,__FILE__,__LINE__,__FUNCTION__,##args);
#else
#define info_log(fmt, args...)
#define info_log_point_p(p,msg) info_log(msg"Poinx{x:%d,y:%d}\n",(p)->x, (p)->y)
#endif

typedef struct Dicts Dicts;

struct Dicts {
        char eng[15];
        char foreign[15];
};


#define BIG_PRIME 100019
#define HASH_MOD()
Dicts dicts[BIG_PRIME];

int hashtable[BIG_PRIME + 20];
int next[BIG_PRIME + 20];

static int hash_str(const char * v) {
    int str_len = strlen(v);
    int vv = 0;
    for (int i = 0; i < str_len; ++i) {
        vv = ((vv * 10 + v[i] ) % BIG_PRIME + BIG_PRIME) % BIG_PRIME;
    }
    info_log("--->hash['%s'] = %d\n",v,vv);
    return vv;
}

static int hash(const Dicts * d) {
    char const *  v = d->foreign;

    int vv = hash_str(v);
    info_log("Dict{eng:%s,foreign:%s}:calculated hash value:%d\n", d->eng, d->foreign, vv);
    return vv;
}


static void init_hashtable() {
    memset(hashtable, -1 ,sizeof(hashtable));
    memset(next, -1 ,sizeof(next));
//    for (int i = 0; i < BIG_PRIME; ++i) {
//        hashtable[i] = -1;
//        next[i] = -1;
//    }
}


static int find_by_str(const char * key) {
    int k = hash_str(key);
    for(int e = hashtable[k]; ~e ; e = next[e] ) {

//        if(e >= BIG_PRIME || e < 0){
//            return -1;
//        }

        if(strcmp(key, dicts[e].foreign) == 0){
            return e;
        }
    }
    return -1;
}

static int find(const Dicts * key) {
    return find_by_str(key->foreign);
}



static void add_ele(const Dicts * key, int value) {
    int k = find(key);

    if(~k)
        return;

    int kk = hash(key);
    next[value] = hashtable[kk];
    hashtable[kk] = value;
}

#ifdef __MAIN__
int poj_2503(int argc, char **argv){
#else
#define info_log(fmt, args...)
int main(int argc, char **argv) {
#endif

    Dicts * d = dicts;

    char temp[64];

    int i = 0;
    init_hashtable();

    while(gets(temp) && temp[0] != 0){
        sscanf(temp, "%s%s", d->eng, d->foreign);
        if(i >= BIG_PRIME) {
            printf("eh");
            exit(0);
        }
        add_ele(d, i++);
        ++d;
    }


    info_log("\n---------look up dicts begin-----------\n")
    while(gets(temp)){
        int key = find_by_str(temp);
        if(~key) {
           //key!= -1
            if(key >= BIG_PRIME || key < 0){
                printf("er");

            }else{
                printf("%s\n", dicts[key].eng);
            }

        }else{
           //key == -1
           printf("eh\n");
        }
    }
    return 0;
}
