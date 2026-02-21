#include <stdio.h>
#include <stdlib.h>

struct Array{
    int *A; 
    int size;
    int length;

};
void display(struct Array arr){
    int i;
    for(i = 0; i < arr.length; i++ ){
        printf("The element at position %d is %d", i, arr.A[i]);
        printf("\n");
    }

}
void Append(struct Array *arr, int x){
    if (arr->size == arr->length){
        printf("Error maximum length already reach");
        exit(EXIT_FAILURE);
    }
    arr->A[arr->length++] = x;

}

void Insert(struct Array * arr, int idx, int x){
    int i;
    if ( idx < 0 || idx > arr->length){
        printf("Error maximum length already reach");
        exit(EXIT_FAILURE);
    }
    for(i = arr->length; i > idx; i--){
        arr->A[i] = arr->A[i-1];
    }
    arr->A[i] = x;
    arr->length++;
}

int main(){
    struct Array arr;
    printf("Enter the size of the array\n");
    scanf("%d",&arr.size);
    arr.A = (int * )malloc(arr.size*sizeof(int));
    arr.length = 0;
    int i ;
    for(i = 0; i < arr.size - 1; i++){
        scanf("%d",&arr.A[i]);
        arr.length++;
    }

    display(arr);
    // Append(&arr,8);
    Insert(&arr,5,10);

    display(arr);

    free(arr.A);
    return 0;
}
