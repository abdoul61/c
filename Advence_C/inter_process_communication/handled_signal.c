#include <stdlib.h>
#include <stdio.h>
#include <signal.h>


void handle_dividedByZero(int signum);
int main(){
    int results = 0;
    volatile int v1 = 121;
    volatile int v2 = 0;
    void (* sigHandlerReturn)(int);
    sigHandlerReturn  = signal(SIGFPE,handle_dividedByZero);

    if (sigHandlerReturn == SIG_ERR){
        perror("Signal Error:");
        return 1;
    }

    results = (v1 / v2);
    printf("Result of Divide by zero is %d\n", results);
    return 0;
}

void handle_dividedByZero(int signum){
    if (signum == SIGFPE) {
        printf("Received %d signal \n", signum);

    }else{
        printf("Receice %d signal\n", signum);
        return;
    }
}


