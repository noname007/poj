#include <stdio.h>
#include <string.h>

char dataset[11][65];

int poj_3080(int argc, char **argv) {

    // n:  m:2-10 ,60char

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int m;
        scanf("%d", &m);

        for (int j = 0; j < m; ++j) {
            scanf("%s", dataset[j]);
//            printf("%s\n", dataset[j]);
        }

//        printf("%s\n", dataset[0]);

        char * s = dataset[0];
        int s_len = strlen(s);
        char commonalities[65];
        int commonalities_len;
        commonalities[0] = 0;
        commonalities_len = 0;

        for (int k = 0; k < s_len; ++k) {
            for (int l = k + 1; l < s_len + 1; ++l) {
                char str[65];
                int size = l - k;
                strncpy(str, s + k, size);
//                strcpy(str, s);
                str[size] = 0;

//                printf("[k:%d,l:%d][base:%s][now:%s]\n", k,l,commonalities, str);


                for (int a = 1; a < m; ++a) {
//                    printf("[m:%d:%s][base:%s][now:%s]\n",a, dataset[a], commonalities, str);
                    char * aaa = strstr(dataset[a],str);
//                    printf("%s\n",aaa);
                    if(aaa == NULL){
                        break;
                    }else{

                        if(commonalities_len  < size || (commonalities_len == size  && strcmp(commonalities, str) > 0)){
                            strcpy(commonalities, str);
                            commonalities_len = size;
                        }
                    }
                }
            }
        }

        if(commonalities_len < 3)
        {
            printf("no significant commonalities\n");
        }else{
            printf("%s\n", commonalities);
        }


    }
    return 0;
}
