#include <stdlib.h>
#include <stdio.h>


struct Node{
    int data;
    struct Node *next;
};

struct Array{
    int *A;
    int length;
    int size;
};

void Display(struct Node *p){
    while(p != NULL){
        printf("%d ->",p->data);
        p = p->next;
    }
    printf("\n");
}
void addElement(struct Array *arr,int n){
    if(arr->length > arr->size){
        exit(EXIT_FAILURE);
    }
    int i;
    for(i = 0; i < n; i++){
        int temp;
        printf("Add element nbr: %d\n",i);
        scanf("%d",&temp);
        arr->A[i] = temp;
        arr->length++;
    }
}
void DisplayArr(struct Array * arr){
    int i;
    for(i = 0; i < arr->length; i++){
        printf("%d ", arr->A[i]);
    }
    printf("\n");
}


void freeList(struct Node *head){
    struct Node * temp;
    while(head != NULL){
        temp = head;
        head = head->next;
        free(temp);
    }
}

struct Node * create(struct Array * arr){
    if( arr == NULL || arr->length <= 0){
        return NULL; // passed an empty array
    }
    struct Node *last,*head;
    int i;
    head = (struct Node *)malloc(sizeof(struct Node));

    if(head == NULL){
        return NULL ; // malloc failed
    }
    head->data = arr->A[0];
    head->next = NULL;
    last = head;
    for(i = 1; i < arr->length;i++){
        struct Node *t;
        t = (struct Node *)malloc(sizeof(struct Node));

        if (t == NULL){
            freeList(head); // malloc failed 
            return NULL;
        }
        t->data = arr->A[i];
        t->next = NULL;
        last->next = t;
        last = t;

    }
    return head;
}


int main(){
    // Structure the array
    struct Array * r;
    r = (struct Array *)malloc(sizeof(struct Array));
    int n;
    printf("How many element do you need ?\n");
    scanf("%d",&n);
    r->size = n;
    r->A = (int *)malloc(r->size * sizeof(int));
    r->length = 0;

    // Add elements in the array
    addElement(r,5);

    // Structure the linkList
    struct Node *p;
    p = create(r);
    DisplayArr(r);
    Display(p);
    printf("Array has %d elements\n",r->length);
    printf("Array can hava up to %d elements \n",r->size);


    // Free heap memory
    freeList(p);
    free(r->A);
    free(r);
    printf("Working..\n");
    return 0;
}
