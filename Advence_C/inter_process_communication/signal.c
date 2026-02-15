#include <stdlib.h>
#include <stdio.h>
#include <signal.h>


int main(){
    printf("Testing SIGSTOP\n");
    raise(SIGSTOP);
    return 0;
}

