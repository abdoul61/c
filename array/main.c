#include <stdlib.h>
#include <stdio.h>
#include <string.h>


struct Array{
    int *A;
    int size;
    int length; 
};

int display(struct Array * arr){
    printf("Length of the array is %d\n",arr->length);
    for(int i = 0; i < arr->length; i++){
        printf("%d ",arr->A[i]);
    }
}
void append(struct Array * arr,int x){
    if(arr->length < arr->size){
        arr->A[arr->length] = x;
        arr->length++;
    }
}
void insert(struct Array *arr, int index, int x){
    arr->length++;
    int i;
    for(i = arr->length; i > index; i--){
        arr->A[i] = arr->A[i-1];
    }
    arr->A[index] = x;
}

int main(){
    struct Array * arr;
    arr = (struct Array *)malloc(sizeof(struct Array));
    int n, i;
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
    printf("The number of element in A is %d\n",arr->length);
    insert(arr,3,30);
    display(arr);
    free(arr->A);
    free(arr);
    return 0;
}
