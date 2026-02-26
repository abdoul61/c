// If the elements are not sorted 
// union two sets will be n^2
// If bot set are sorted, it becomes (n+m)
// nlog(n) + n

#include <stdint.h>
#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int A[10] ;
    int size;
    int length;

} Array ;

void display(Array arr){
    int i;
    for(i = 0; i  < arr.size; i++){
        printf("The current element is: %d \n", arr.A[i]);
    }
}

Array * Merge(Array * arr1, Array * arr2){
    int i, j, k;
    i=j=k=0;
    Array *arr3 = (Array * )malloc(sizeof(Array));
    while(i < arr1->length && j < arr2->length ){
        if (arr1->A[i] < arr2->A[j]) {
            arr3->A[k++]  = arr1->A[i++];
        }else{
            arr3->A[k++]  = arr2->A[j++];
        }
    }
    for(; i < arr1->length; i++){
        arr3->A[k++]  = arr1->A[i];
    }
    for(; j < arr2->length; j++){
        arr3->A[k++]  = arr2->A[j];
    }
    arr3->length = arr2->length + arr1->length;
    arr3->size = 10;
    return arr3;
}
Array * Union(Array * arr1, Array * arr2){
    int i, j, k;
    i=j=k=0;
    Array *arr3 = (Array * )malloc(sizeof(Array));
    while(i < arr1->length && j < arr2->length ){
        if (arr1->A[i] < arr2->A[j]) {
            arr3->A[k++]  = arr1->A[i++];
        }else if(arr2->A[j] < arr1->A[i]){
            arr3->A[k++]  = arr2->A[j++];
        }else{
            arr3->A[k++]  = arr2->A[j++];
            i++;
        }
    }
    for(; i < arr1->length; i++){
        arr3->A[k++]  = arr1->A[i];
    }
    for(; j < arr2->length; j++){
        arr3->A[k++]  = arr2->A[j];
    }
    arr3->length = k;
    arr3->size = 10;
    return arr3;
}
Array * Intersection(Array * arr1, Array * arr2){
    int i, j, k;
    i=j=k=0;
    Array *arr3 = (Array * )malloc(sizeof(Array));
    while(i < arr1->length && j < arr2->length ){
        if (arr1->A[i] < arr2->A[j]) {
            i++;
        }else if(arr2->A[j] < arr1->A[i]){
            j++;
        }else{
            arr3->A[k++]  = arr2->A[j++];
            i++;
        }
    }
    
    arr3->length = k;
    arr3->size = 10;
    return arr3;
}

Array * AminusB(Array * arr1, Array * arr2){
    int i, j, k;
    i=j=k=0;
    Array *arr3 = (Array * )malloc(sizeof(Array));
    while(i < arr1->length && j < arr2->length ){
        if (arr1->A[i] < arr2->A[j]) {
            arr3->A[k++]  = arr1->A[i++];
        }else if(arr2->A[j] < arr1->A[i]){
            j++;
        }else{
            j++;
            i++;
        }
    }
    for(; i < arr1->length; i++){
        arr3->A[k++]  = arr1->A[i];
    }
    arr3->length = k;
    arr3->size = 10;
    return arr3;
}
int main(int argc, char *argv[])
{
    Array arr1 = {{2,6,10,15,25},10,5};
    Array arr2 = {{3,6,7,15,20},10,5};
    // Array * arr3 = Union(&arr1,&arr2);
    // Array * arr3 = Merge(&arr1,&arr2);
    // Array * arr3 = Intersection(&arr1,&arr2);
    Array * arr3 = AminusB(&arr1,&arr2);
    display(*arr3);
    return EXIT_SUCCESS;
}
