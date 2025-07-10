#include <stdlib.h>
#include <stdio.h>
#include <limits.h>


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

void Rdisplay(struct Node * head){
    if (head == NULL){
        return;
    }
    printf("%d -> ", head->data);
    Rdisplay(head->next);
}

int countLinkList(struct Node *p){
    int count = 0; 
    while (p != NULL){
        count++;
        p = p->next;
    }
    
    return count;
}

int countLinkRec(struct Node * head){
    if(head == NULL){
        return 0;
    }
    return countLinkRec(head->next) + 1;
}


int LinkListSum(struct Node * p){
    unsigned int value = 0;
    while (p != NULL){
        value += p->data;
        p = p->next;
    }
    return value;
}


int LinkListSumRec(struct Node * head){
    if(head == NULL){
        return 0;
    }
    return LinkListSumRec(head->next) + head->data;
}

int findMax(struct Node * head){
    int maxi = INT_MIN;
    struct Node * p;
    p = head;
    while(p != NULL){
        if(p->data >= maxi){
            maxi = p->data;
        }
        p = p->next;
    }

    return maxi;
}

int findMaxRec(struct Node * head){
    int result ;
    struct Node * p;
    p = head;
    if(p == NULL){
        return INT_MIN;
    }
    result = findMaxRec(p->next);
    if(result > p->data){
        return result;
    }else{
        return p->data;
    }
}
    
int main(){
    // Structure the array
    struct Array * r;
    r = (struct Array *)malloc(sizeof(struct Array));
    int n,pLength,total,maxi;
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
    Rdisplay(p);
    printf("\n");
    pLength = countLinkRec(p);
    printf("The length of the linklist is %d\n",pLength);
    total = LinkListSumRec(p);
    printf("The total sum of nodes is: %d \n",total);
    maxi = findMaxRec(p);
    printf("The maximum elements in a node is: %d\n", maxi);


    // Free heap memory
    freeList(p);
    free(r->A);
    free(r);
    printf("Working..\n");
    return 0;
}
