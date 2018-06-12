/*
 * 3274.c
 *
 *  Created on: 2018年6月11日
 *      Author: yangzhen
 */
#include <stdio.h>
#include <string.h>
#ifdef __MAIN__DEBUG
#define info_log(fmt, args...) printf(fmt,##args);
#else
#define info_log(fmt, args...)
#endif

#define TEST_BIT(num,j) ((num) & (1 << ((j) - 1)))
#define BIG_PRIME 99991
int Hash[100005];
int next[100005];


int hash(const int  v[], int k) {

    int sum = 0;
    for(int i =1;i <= k; ++i){
        sum = (sum + (v[i] * 10 % BIG_PRIME+ BIG_PRIME)) % BIG_PRIME;
    }

    return sum;
}

#ifdef __MAIN__
#define log(fmt, args...) printf(fmt,##args);
int poj_3274(int argc, char **argv){
#else
#define log(fmt, args...)
int main(int argc, char **argv) {
#endif

    int N, K;
    scanf("%d%d", &N, &K);

    int sum[N][32], mid_arr[N][32], t;

    memset(Hash, -1, sizeof(Hash));

    memset(sum, 0, sizeof(sum));
    memset(mid_arr, 0, sizeof(mid_arr));

    int ans = 0;

    for (int i = 1; i <= N; ++i) {

        scanf("%d", &t);
        info_log("\nsum[%d] : ", t);

        for (int j = 1; j <= K; ++j) {
            //t & 1 << (j - 1)
            sum[i][j] = sum[i - 1][j] + t % 2;
            t >>= 1;
            mid_arr[i][j] =  sum[i][j] - sum[i][1];
        }
#ifdef __MAIN__DEBUG
        for (int jk = 0; jk <= K; ++jk) {
            printf("%d ", sum[i][jk]);
        }
        printf("\n");

        printf("diff[%d]: ", i);
        for (int jk = 0; jk <= K; ++jk) {
            printf("%d ", mid_arr[i][jk]);
        }
        printf("\n");
#endif

    }

    for (int i = 0; i <= N; ++i) {
       int k = hash(mid_arr[i], K);
       int found = 0;
       info_log("hash[mid_arr[%d]]:%d\n",i,k);
       for(int e = Hash[k]; ~e ; e = next[e] ) {
           info_log("|--%d, %d\n", i, e);

           if(memcmp(mid_arr[i], mid_arr[e], sizeof(int) * (K + 1)) == 0) {
               info_log("|--- %d, %d\n", i, e);

               found = 1;
               if(ans < (i - e)) {
                   ans = i - e;
               }

             break;
           }
       }

       if(!found) {
           next[i] = Hash[k];
           Hash[k] = i;
       }
    }
    printf("%d\n",ans);
    return 0;
}




