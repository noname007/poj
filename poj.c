/*
 * poj.c
 *
 *  Created on: 2018年5月5日
 *      Author: yangzhen
 */
#define call_poj(n)   poj_##n(argc, argv);

//int poj_2388(int argc, char **argv);
int main(int argc, char **argv) {
//    poj_3080(argc, argv);
//    poj_1035(argc, argv);
//    poj_1936(argc, argv);
//    poj_2388(argc, argv);
//    poj_2299(argc, argv);
//    poj_3349(argc, argv);
//    poj_3274(argc, argv);
    call_poj(3274)
    return 0;
}



