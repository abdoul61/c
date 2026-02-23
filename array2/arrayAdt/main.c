#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


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
int Delete(struct Array * arr, int idx){
    int i;
    int result;
    if( idx < 0 || idx > arr->length){
        printf("Error maximum length already reach");
        exit(EXIT_FAILURE);
    }
    result = arr->A[idx];
    for(i = idx; i < arr->length -1 ; i++){
        if(i+1 < arr->length){
            arr->A[i] = arr->A[i+1];
        }
    }
    arr->A[i] = 0;
    arr->length--;
    
    return result;
}
void swapp(int * add_1, int * add_2){
    int temp = *add_1;
    *add_1 = *add_2;
    *add_2 = temp;
}

bool linear_search(struct Array arr, int x){
    int i;
    for(i = 0; i < arr.length; i++){
        if(x == arr.A[i]) {
            swapp(&arr.A[0] ,&arr.A[i]);
            return true;
        }
    }
    return false;
}

int binary_search_recc(struct Array *arr, int left, int right, int key){
    if (left > right){
        return -1;
    }
    int mid = (left + right )/ 2;
    if (arr->A[mid] == key){
        return mid;
    }else if( arr->A[mid] < key){
        return binary_search_recc(arr, mid + 1, right, key);
    } else{
        return binary_search_recc(arr, left, mid - 1 , key);
    }
}

int binary_search(struct Array *arr, int x){
    int left;
    int right;
    int mid;
    left = 0;
    right = arr->length;
    while(left <= right){
        mid = (left + right) / 2;
        printf(" the current mid index is: %d\n", mid);
        if (arr->A[mid] == x){
            return mid;
        }else if (arr->A[mid] < x){
            left = mid + 1;
        }else{
            right = mid -1;
        }
    }

    return -1;
}
int main(){
    struct Array arr;
    int deleted;
    printf("Enter the size of the array\n");
    scanf("%d",&arr.size);
    arr.A = (int * )malloc(arr.size*sizeof(int));
    arr.length = 0;
    int i ;
    // for(i = 0; i < arr.size - 1; i++){
    for(i = 0; i < arr.size; i++){
        scanf("%d",&arr.A[i]);
        arr.length++;
    }

    // display(arr);
    // Append(&arr,8);
    // Insert(&arr,5,10);

    // display(arr);
    // deleted = Delete(&arr,2);
    // printf("Element deleted was %d\n",deleted);
    display(arr);
    // printf("%d\n", linear_search(arr,4));
    printf("%d\n", binary_search(&arr,4));
    printf("%d\n", binary_search_recc(&arr,0,arr.size,10));
    
    display(arr);
    free(arr.A);
    return 0;
}
