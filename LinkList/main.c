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
struct LinkResult{
    int count;
    int data; 
    struct Node * head;
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
    temp = NULL;
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

// Search in a LinkList
struct Node * searchElement(struct Node * head, int b){
    if(head == NULL) return NULL;
    struct Node * curr = head->next;
    struct Node * previous = head;
    if(head->data == b){
        printf("Element found at first Position \n");
        return head;
    }
    while(curr != NULL){
        if(curr->data == b){
            printf("Element Found! \n");
            previous->next = curr->next;
            curr->next = head;
            return curr;
        }
        previous = curr;
        curr = curr->next;
    }

    printf("NotFound!\n");
    return head;
}


struct Node * insertNode(struct Node * head,int key,int idx){
    struct Node * h = (struct Node *)malloc(sizeof(struct Node));
    h->data = key;
    h->next = NULL;
    if(head == NULL) return h;

    if(head->next == NULL){
        head->next = h;
        return head;
    }
    if(idx == 0){
        h->next = head;
        head = h;
        return head;
    }

    struct Node * p = head->next;
    struct Node * previous = head;
    int count = 0;
    while(p != NULL && count < idx){
        previous = p;
        p = p->next;
        count++;
    }
    
    previous->next = h;
    h->next = p;
    return head;
}

struct Node * insertSortedList(struct Node * head, int key){
    struct Node * p = (struct Node *)malloc(sizeof(struct Node));
    p->data = key;
    p->next = NULL;
    if(head == NULL) return p;
    if(head->next == NULL){
        if(head->data < key){
            head->next = p;
        }else{
            p->next = head;
            head = p;
        }
        return head;
    }
    struct Node *temp = head->next;
    struct Node * pre = head;
    while( temp != NULL && temp->data < key){
        pre = temp;
        temp = temp->next;
    }
    pre->next = p;
    p->next = temp;
    return head;
}

int searchRec(struct Node * p, int b){
    if(p == NULL){
        return -1;
    }
    if(p->data == b){
        return 0;
    }
    return searchRec(p->next,b);
}
// reverse LinkList
struct Node * reverseLinkList(struct Node * head){
    if(head == NULL || head->next == NULL) return head;
    struct Node * p, * prev, * curr;
    p = head;
    prev = curr = NULL;
    while(p != NULL){
        curr = prev;
        prev = p;
        p = p->next;
        prev->next = curr;
    }
    head = prev;
    return head;
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
    printf("Find element\n");
    
    Display(p);
    printf("\n");
    p = insertSortedList(p,6);

    Display(p);
    p = reverseLinkList(p);
    Display(p);


    freeList(p);
    free(r->A);
    free(r);
    printf("Working..\n");
    return 0;
}
