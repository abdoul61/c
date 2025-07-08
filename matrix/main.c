#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>


struct Matrix{
    int * A;
    int n;
};

void Set(struct Matrix *m,int p,int q,int x){
    if(p == q) {
        m->A[p-1]=x;
    }
}

int Get(struct Matrix *m, int p, int q) {
    if(p == q){
        return m->A[p-1];
    }else{
        return 0;
    }
}

void Display(struct Matrix *m){
    int i,j;
    for(i = 0; i < m->n; i++){
        for(j=0; j < m->n; j++){
            if(i == j){
                printf("%d ",m->A[i]);
            }else{
                printf("0 ");
            }
        }
        printf("\n");
    }
}
int main(){
    struct Matrix *m;
    m = (struct Matrix *)malloc(sizeof(struct Matrix));
    m->n = 5;
    m->A = (int *)malloc(m->n * sizeof(int));
    Set(m,1,1,5);Set(m,2,2,8);Set(m,3,3,9); Set(m,4,4,7);Set(m,5,5,2);
    printf("%d\n",Get(m,1,1));
    Display(m);
    free(m->A);
    free(m);
    return 0;
}

