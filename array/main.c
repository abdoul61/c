#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Card{
    int face;
    int num ;
    char x;
};

int main(){
    struct Card * p = (struct Card *)malloc(sizeof(struct Card));
    p->face = 10;
    p->num = 20;
    p->x = 'a';

    return 0;
}
