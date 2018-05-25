/*
 * 1936.c
 *
 *  Created on: 2018年5月25日
 *      Author: yangzhen
 */
#include <stdio.h>
#include <string.h>

char flag[100004];
char s[100004];
char t[100004];

const char IN = 0;
const char NOT_IN = 1;

void diplay_byte(const char * c, int len){
    for(int i = 0; i < len; ++i) {
        printf("%d, %d\n",i, *c++);
    }
}

//#ifndef __MAIN__
//int main(int argc, char **argv) {
//#else

int poj_1936(int argc, char **argv){

//#endif

    while(~scanf("%s %s",s,t)){
//        printf("%s, %s\n",s,t);

        int s_len = strlen(s);
        int t_len = strlen(t);

        if (s_len > t_len) {
            printf("No\n");
            continue;
        }

        memset(flag, IN , t_len * sizeof(flag[0]));

//        diplay_byte(flag, t_len);

        // s[i - 1] in t[j - 1] && s[i] == t[j]
        char FIRST_COND = IN;

        for (int i =  0; i < s_len; ++i) {
            for (int j = i; j < t_len; ++j) {

                if(FIRST_COND  ==  IN &&  s[i] == t[j])
                {
                    break;

                }else{
                    FIRST_COND = flag[j];
                    flag[j] = NOT_IN;
                }

            }

            if(flag[t_len -1 ] == NOT_IN){
                break;
            }
            FIRST_COND = flag[i];
        }

//        diplay_byte(flag, t_len);

        if(flag[t_len - 1 ] == NOT_IN) {
            printf("No\n");
        } else {
            printf("Yes\n");
        }

    }

    return 0;
}
