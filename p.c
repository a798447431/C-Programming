/*************************************************************************
	> File Name: p.c
	> Author: 
	> Mail: 
	> Created Time: 2019年10月25日 星期五 21时22分52秒
 ************************************************************************/

#include<stdio.h>

int main() {
    int x = 0;
    int *p = &x;
    printf("%p\n", x);
    printf("%d\n", *p);
    return 0;
}