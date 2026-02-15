#include <stdio.h>
#include <stdlib.h>

void f1(int n, float * restrict a1, const float * restrict a2){
    // In this example the compiler can optimize since a1 and a2 are the
    // solo accessor. 
    int i;
    for (i = 0; i < n; i++){
        a1[i] += a2[i];
    }
}

int main(void){
    

    return 0;
}
