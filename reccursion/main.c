#include<stdlib.h>
#include<stdio.h>

int func(int n){
    static int y = 0;
    if(n > 0){
        y++;
        return func(n-1) + y;
    }
    return 0;
}

int main(){
    int x = 5;
    int r;
    r = func(x);
    printf("%d\n",r);
    return 0;
}
