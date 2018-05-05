#include<stdio.h>
#include<string.h>
#define WORDS_NUM 10005
#define WORD_MAX_LEN 17

//char dict[WORDS_NUM][WORD_MAX_LEN];

typedef char Word[WORD_MAX_LEN];

Word dict[WORDS_NUM];
Word check_list[52];

int print_list[WORDS_NUM];


static int get_input_word(Word store[])
{
    int i = 0;

    for (i = 0; ; ++i) {
        scanf("%s", store[i]);
        if(store[i][0] == '#')
        {
            break;
        }
   }

    return i;
}


int poj_1035(int argc, char **argv) {

    int dict_word_num = get_input_word(dict);
    int check_list_len = get_input_word(check_list);
//    printf("%d %d\n", dict_word_num, check_list_len);

    for (int i = 0; i < check_list_len; ++i) {

        printf("%s", check_list[i]);

        char * cc = check_list[i];

        int check_list_word_len = strlen(cc);

        int is_correct = 0, print_list_idx = 0;

        for (int j = 0; j < dict_word_num; ++j) {
//            print_list_idx = 0
            char * dc = dict[j];

            int dict_word_len = strlen(dc);

            int len_minus = dict_word_len - check_list_word_len;

            if(len_minus < 0)
                len_minus = -1 * len_minus;

            if( len_minus >=   2 )
            {
                continue;
            }

           int k = 0, l = 0;

           while(k < check_list_word_len && l < dict_word_len && cc[k] == dc[l])
           {
               ++k;
               ++l;
           }

           --k;
           --l;

           int m = check_list_word_len - 1, n = dict_word_len - 1;

           while(m > k && n  > l && cc[m] == dc[n])
           {
               --m;
               --n;
           }

//           printf("%s(k:%d,l:%d)(m:%d,n:%d) m - k = %d;",dc,k,l,m,n, m - k);

           if(m == k && n == l)
           {
               is_correct = 1;
//               printf("is correct");
           }
           else if(m - k < 2 && n - l < 2)
           {
//               printf("--");
               print_list[print_list_idx ++] = j;
           }
        }

        if(is_correct)
        {
            printf(" is correct");
        }else{
            printf(":");
            for (int o = 0; o < print_list_idx; ++o) {
                printf(" %s", dict[print_list[o]]);
            }
        }



        printf("\n");
    }

    return 0;
}
