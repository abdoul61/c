#include <stdlib.h>
#include <stdio.h>


struct Array{
    int * A;
    int length;
    int size;
};

void display(struct Array arr){
    int i;
    for(i = 0; i  < arr.length; i++){
        printf("The current element is: %d \n", arr.A[i]);
    }
}
void swapp(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void reverse_array(struct Array *arr){
    int left = 0;
    int right = arr->length -1 ;
    while(left <= right){
        swapp(&arr->A[left],&arr->A[right]);
        left++;
        right--;
    }
}

struct Array * merge_array(struct Array * arr_1, struct Array arr){
    if((arr_1->length - 3 + arr.length) > arr_1->size){
        printf("Bad code ): \n");
        exit(EXIT_FAILURE);
    }
    int curr_pointer = arr_1->size - 1;
    int curr_arr_1 = arr_1->length -1;
    int curr_arr = arr.length-1;
    while(curr_pointer >= 0 && curr_arr >= 0){
        if(arr_1->A[curr_arr_1] > arr.A[curr_arr]){
            arr_1->A[curr_pointer] = arr_1->A[curr_arr_1];
            curr_arr_1--;
        }else{
            arr_1->A[curr_pointer] = arr.A[curr_arr];
            curr_arr--;
        }
        curr_pointer--;
    }
    return arr_1;
}

void add_in_sorted_array(struct Array * arr, int key){
    if(arr->length >= arr->size){
        exit(EXIT_FAILURE);
    }
    int l = arr->length -1 ;
    while(l > 0 && arr->A[l] >= key && l+1 < arr->size){
        arr->A[l+1]  = arr->A[l];
        l--;
    }
    arr->A[l+1] = key;
    arr->length++;
}

int  main(int argc, char *argv[])
{
    struct Array arr;
    struct Array arr2;
    printf("What is the size of the buffer ? \n");
    scanf("%d",&arr.size);
    arr2.size = 4;
    printf("size of the arr2 : %d", arr2.size);

    arr.A = (int *)malloc(arr.size * sizeof(int));
    arr2.A = (int *)malloc(arr2.size * sizeof(int));
    arr.length = 0;
    arr2.length = 0;

    int idx;
    for(idx = 0; idx < arr.size; idx++){
        scanf("%d",&arr.A[idx]);
        arr.length++;
    }
    for(idx = 0; idx < arr2.size; idx++){
        scanf("%d",&arr2.A[idx]);
        arr2.length++;
    }
    struct Array  * return_arr;
    return_arr->size = arr.size;
    // return_arr.A = (int *)malloc(return_arr.size * sizeof(int));
    return_arr = merge_array(&arr,arr2);
    display(arr);
    // reverse_array(&arr);
    // add_in_sorted_array(&arr, 15);
    display(arr);
    printf("\n");
    display(arr2);
    printf("\n");
    display(*return_arr);
    return EXIT_SUCCESS;
}
