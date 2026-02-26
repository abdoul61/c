#include <stdlib.h>
#include <stdio.h>
#include <limits.h>


struct Array{
    int * A;
    int length;
    int size;
};

void display(struct Array arr){
    int i;
    for(i = 0; i  < arr.size; i++){
        printf("The current element is: %d \n", arr.A[i]);
    }
}

int Get(struct Array arr, int index){
    if (index < 0 ||  index > arr.length){
        return -1;
    }
    return arr.A[index];
}

void Set(struct Array * arr, int idx, int key){
    if (idx > 0  || idx > arr->length){
        exit(EXIT_FAILURE);
    }
    arr->A[idx] = key;
}

int Max(struct Array arr){
    int result = INT_MIN;
    int idx;
    for(idx = 0; idx < arr.length; idx++){
        if (arr.A[idx] > result){
            result = arr.A[idx];
        }
    }
    return result;
}

int Min(struct Array arr){
    int result = INT_MAX;
    int idx;
    for(idx = 0; idx < arr.length; idx++){
        if (arr.A[idx] < result){
            result = arr.A[idx];
        }
    }
    return result;
}

int main(int argc, char *argv[])
{
    struct Array  arr;
    printf("Enter the size of the buffer\n");
    scanf("%d",&arr.size);
    arr.A = (int *) malloc(arr.size * sizeof(int));
    arr.length = 0;
    

    int idx;
    for (idx = 0; idx < arr.size; idx++){
        scanf("%d",&arr.A[idx]);
        arr.length++;
    }
    display(arr);
    printf("The value is %d\n", Get(arr,10));
    printf("The max value is %d\n", Max(arr));
    printf("The min value is %d\n", Min(arr));

    return EXIT_SUCCESS;
}
