/*************************************************************************
	> File Name: seqtest.c
	> Author: suziteng
	> Mail: 253604653@qq.com
	> Created Time: 2019年05月04日 星期六 10时11分16秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Vector {
    int *data;
    int size, length;
} Vector;

Vector *init(int n) {
    Vector *p = (Vector *)malloc(sizeof(Vector));
    p->data = (int *)malloc(sizeof(int) * n);
    p->size = n;
    p->length = 0;
    return p;
}

int insert(Vector *v, int ind, int val) {
    if (v->length == v->size) return 0;
    if (ind < 0 || ind > v->length) return 0;
    for (int i = v->length - 1; i >= ind; i--) {
        v->data[i + 1] = v->data[i];
    }
    v->data[ind] = val;
    v->length += 1;
    return 1;
}

int erase(Vector *v, int ind) {
    if (ind < 0 || ind >= v->length) return 0;
    for (int i = ind + 1; i < v->length; i++) {
        v->data[i - 1] = v->data[i];
    }
    v->length -= 1;
    return 1;
} 

void clear(Vector *v) {
    if (v == NULL) return ;
    free(v->data);
    free(v);
    return ;
}

void output(Vector *v) {
    printf("arr = [");
    for (int i = 0; i < v->length; i++) {
        printf(" %d", v->data[i]);
    }
    printf(" ]\n");
    return ;
}

int main() {
    #define MAX_OP 20
    int op, ind, val;
    Vector *v = init(MAX_OP);
    for (int i = 0; i < MAX_OP; i++) {
        op = rand() % 2;
        ind = rand() % (v->length + 3) - 1;
        val = rand() % 100;
        switch (op) {
            case 0: {
                printf("insert %d to vector at %d = %d\n", val, ind, insert(v, ind, val));
                output(v);
            } break;
            case 1: {
                printf("erase element at %d from vector = %d\n", ind, erase(v, ind));
                output(v);
            } break;
            default: 
                fprintf(stderr , "wrong op %d\n", op);
            break;
        }
    }
    clear(v);
    return 0;
}
