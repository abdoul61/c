#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>


struct Matrix{
    int * A;
    int n;
};

// formula is A[i(i-1)/2 + j-1]
void Set(struct Matrix *m,int p,int q,int x){
    if(p >= q) {
        m->A[p*(p-1)/2 + q-1]=x;
    }
}

int Get(struct Matrix *m, int p, int q) {
    if(p >= q){
        return m->A[p*(p-1)/2 + q-1];
    }else{
        return 0;
    }
}

void Display(struct Matrix *m){
    int i,j;
    for(i = 1; i <= m->n; i++){
        for(j=1; j <= m->n; j++){
            if(i >= j){
                printf("%d ",m->A[i*(i-1)/2 + j-1]);
            }else{
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int main(){
    struct Matrix m;
    int i,j,x;
    printf("Enter the size\n");
    scanf("%d",&m.n);
    printf("The size if %d\n",m.n);
    m.A = (int *)malloc((m.n *(m.n)/2) * sizeof(int));
    printf("Print all the elements\n");
    for(i = 1; i <= m.n; i++){
        for(j=1;j <= m.n; j++){
            scanf("%d",&x);
            Set(&m,i,j,x);
        }
    }
    printf("\n\n");
    Display(&m);

    free(m.A);
    return 0;
}
