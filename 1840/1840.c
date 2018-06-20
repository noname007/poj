/*
 * 1840.c
 *
 *  Created on: 2018年6月19日
 *      Author: yangzhen
 */



#include<stdio.h>
#include<memory.h>



#define MAX 18750000

static int hash[MAX * 2 + 100];

#ifdef __MAIN__
#define info_log(fmt, args...) printf("%s:%d:%s "fmt,__FILE__,__LINE__,__FUNCTION__,##args);
int poj_1840(int argc, char **argv){
#else
#define info_log(fmt, args...)
int main(int argc, char **argv) {
#endif
    int coeff[5];

    short i,j,k;
    int result;
    int sum = 0;
    scanf("%d%d%d%d%d", coeff, coeff + 1, coeff + 2, coeff + 3, coeff + 4);

    {
        //memset(hash, 0, sizeof(hash));
        for( i = -50 ; i <= 50; i++)
        {
            for( j = -50; j <= 50; j++)
            {
                for( k = -50; k <= 50; k++)
                {
                    if( i != 0 && j != 0 && k != 0)
                    {
                        result = i*i*i*coeff[0] + j*j*j*coeff[1] + k*k*k*coeff[2];
                        result += MAX;
                        info_log("hash(%d %d %d)-->%d : %d\n", i,j,k, result, hash[result])
                        hash[result]++; //-----
                    }

                }
            }
        }

        sum = 0;
        for( i = -50; i <= 50; i++)
        {
            for( j = -50; j <= 50; j++)
            {
                if( i != 0 && j != 0)
                {
                    result = -(i*i*i*coeff[3] + j*j*j*coeff[4]);
                    result += MAX;
                    info_log("check: %d\n", result)
                    sum += hash[result];//-----
                }

            }
        }
        printf("%d\n",sum);

    }
    return 0;
}
