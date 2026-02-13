#include <stdlib.h>
#include <stdio.h>



struct stack {
    int size;
    int top;
    int * buffer;
};

void create(struct stack *st){
    printf("Enter the size of the buffer\n");
    scanf("%d",&st->size);
    st->top = -1;
    st->buffer= (int *)malloc(st->size * sizeof(int));
}

void display(struct stack *st){
    int i ;
    for(i=st->top; i > 0; i--){
        printf("%d->\n",st->buffer[st->top-i + 1]);
    }
}

void addElement(struct stack *st, int x){
   if(st->top == st->size - 1) {
        printf("NO more space");
        exit;
    }
    st->top++;
    st->buffer[st->top] = x;
}
int main(){
    struct stack *st;
    st = (struct stack *)malloc(sizeof(struct stack));
    create(st);
    addElement(st,10);
    display(st);
    free(st);
    return 0;
}
