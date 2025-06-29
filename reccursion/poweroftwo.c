#include<stdlib.h>
#include<stdio.h>


int pwo2(int m, int n){
    if (n == 0) return 1;
    return m * pwo2(m,n-1);
}
int pwo(int m,int n){
    if (n == 0){
        return 1;
    }
    if (n % 2 == 0){
        return pwo(m*m,n/2);
    }else{
        return m * pwo(m*m, (n-1)/2);
    }
}

int main(){
    int r = 0;
    r = pwo2(2,3);
    printf("%d\n",r);
    r = pwo2(2,5);
    printf("%d\n",r);
    return 0;
}
