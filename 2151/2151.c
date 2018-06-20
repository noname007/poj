/*
 * 2151.c
 *
 *  Created on: 2018年6月19日
 *      Author: yangzhen
 */

#include <stdio.h>
#include <string.h>
#define MAXN 1005
double dp[MAXN][35][35], s[MAXN][35], p[MAXN][35];


#ifdef __MAIN__
#define log(fmt, args...) printf(fmt,##args);
int poj_2151(int argc, char **argv){
#else
#define log(fmt, args...)
int main(int argc, char **argv) {
#endif

    int M,N,T;
//    M (0 < M <= 30), T (1 < T <= 1000) and N (0 < N <= M)
//    the number of contest problems M, the number of teams T,
//    and the number of problems N that the organizer expect
//    the champion solve at least

    while(~scanf("%d%d%d",&M,&N,&T)){

        if(M==0 && T==0 && N==0)
            break;

        for(int i=1; i<=T; i++) {
            for(int j=1; j<=M; j++) {
                scanf("%lf",&p[i][j]);

            }
        }

       //初始化
       memset(dp, 0, sizeof(dp));

       for(int i=1; i<=T; i++){
           dp[i][0][0] = 1;
           for(int j=1; j<=M; j++)
               dp[i][j][0] = (1-p[i][j])*dp[i][j-1][0];
       }

       for(int i=1; i<=T; i++)
           for(int j=1; j<=M; j++)
               for(int k=1; k<=j; k++)
                   dp[i][j][k] = p[i][j] * dp[i][j-1][k-1] + (1-p[i][j]) * dp[i][j-1][k];

       for(int i=1; i<=T; i++){
           for(int j=0; j<=M; j++){
               s[i][j] = 0;
               for(int k = 0; k<=j; k++)
                   s[i][j] += dp[i][M][k];
           }
       }

       double p1 = 1, p2 = 1;
       for(int i=1; i<=T; i++){
           p1 *= (s[i][M] - s[i][0]);
           p2 *= (s[i][N-1] - s[i][0]);
       }
       printf("%.3f\n",p1-p2);
    }
    return 0;
}
