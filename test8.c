/*************************************************************************
	> File Name: test8.c
	> Author: 
	> Mail: 
	> Created Time: 2019年09月28日 星期六 16时23分40秒
 ************************************************************************/

#include <stdio.h>
int main() {
    int a[] = {1, 2, 3, 4, 5};
    int *ptr = (int *) (&a + 1);
    printf("%d %d", *(a + 1), *(ptr - 1));
    return 0;
}

