#include <stdlib.h>
#include <stdio.h>
#include <string.h>


struct Array{
    int *A;
    int size;
    int length; 
};

// Display a list of elements in Array
int display(struct Array * arr){
    printf("Length of the array is %d\n",arr->length);
    for(int i = 0; i < arr->length; i++){
        printf("%d ",arr->A[i]);
    }
}
// Append an element x.
void append(struct Array * arr,int x){
    if(arr->length < arr->size){
        arr->A[arr->length] = x;
        arr->length++;
    }else{
        exit(EXIT_FAILURE);
    }
}
// Insert element x in a position index 
void insert(struct Array *arr, int index, int x){
    if (arr->length < arr->size){
        arr->length++;
        int i;
        for(i = arr->length; i > index; i--){
            arr->A[i] = arr->A[i-1];
        }
        arr->A[index] = x;
    }else{
       exit(EXIT_FAILURE);
    }
}

// delete an element with an index  from array
int delete(struct Array * arr,int index){
    int el = arr->A[index];
    int i;
    if(index >=0 && index < arr->length){
        for(i = index; i < arr->length-1; i++) {
            if(i+1 < arr->length){
                arr->A[i] = arr->A[i+1];
            }
        }

        arr->length--;
        return el;
    }
    return 0;
}
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
// Search can be optimized by using transposition or move-to-front
int search(struct Array * arr,int x){
    int i;
    for(i = 0; i < arr->length; i++){
        if (arr->A[i] == x){
            swap(&arr->A[0],&arr->A[i]);
            printf("Element is found!\n");
            return i;
        }
    }
    printf("Element is not present\n");
    return -1;
}
int Bsearch(struct Array * arr,int x){
    int i = 0;
    int k = arr->length-1;
    int mid;
    while(i <= k){
        mid = i +  (k - i) / 2;
        if(arr->A[mid] == x){
            printf("Found!\n");
            return mid;
        }else if(x < arr->A[mid]){
            k = mid -1;
        }else{
            i = mid + 1;
        }
    }
    printf("Not found!\n");
    return -1;
}

int main(){
    struct Array * arr;
    arr = (struct Array *)malloc(sizeof(struct Array));
    int n, i,q;
    
    printf("Enter a size: \n");
    scanf("%d",&arr->size);
    printf("The size of arr is %d\n",arr->size);
    arr->A = (int *)malloc(arr->size * sizeof(int));
    arr->length = 0;
    printf("Enter the number of elements you want\n");
    scanf("%d",&n);
    
    for(i=0; i < n; i++){
        printf("Enter element number %d\n",i);
        scanf("%d",&arr->A[i]);
        arr->length++;
    }
    
    display(arr);
    append(arr,10);
    display(arr);
    printf("Element is found at %d\n",Bsearch(arr,10));
    printf("Searching element\n");
    search(arr,30);
    printf("The number of element in A is %d\n",arr->length);
    insert(arr,3,30);
    display(arr);
    printf("delete an element.\n");
    q = delete(arr,2);
    printf("Element deleted %d\n",q);
    display(arr);
    printf("Searching element\n");
    printf("Element is found at %d\n",search(arr,30));
    printf("Element is found at %d\n",search(arr,30));
    display(arr);
    free(arr->A);
    free(arr);
    return 0;
}
