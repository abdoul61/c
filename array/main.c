#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Card{
    int face;
    int num ;
    char x;
};

int main(){
    int A[] = {2,3,4,5,59};
    struct Card c = {1,2,'c'};
    int *p = A;
    printf("size of %lu\n",sizeof(A));
    printf("size of %lu\n",sizeof(c));
    printf("Value of p %p\n",p);
    printf("Value of p %p\n",A);

    return 0;
}
