#include <stdio.h>
#include <stdlib.h>

int add(int * a, int * b){
    return *a + *b;
}
void func(int * array,int x ){
    for(int i = 0; i < x; i++){
        printf("The value of x is:%d\n",array[i]);
    }
}

int * func2(int n){
    int * p;
    p = (int *) malloc(n * sizeof(int));
}

struct Rect{
    int L;
    int W;
};
int main(){
    // int * myarray = (int *)malloc(sizeof(int) * 10);
    // int myarray[5] = {2,3,54,54,0};
    // int n = *(&myarray + 1) - myarray;
    // func(myarray,n);
    int * A;
    A = func2(5);
    int n = *(&A + 1) - A;
    printf("The size of A is:%d\n",n);
    return 0;
}
