#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>


int main(){
    int results = 0;
    int v1 = 0, v2 = 0;
    v1 = 121;
    v2 = 0;
    results = v1/v2;
    printf("Result of Divide by zero is %d\n", results);
    return 0;
}


