#include<stdlib.h>
#include<stdio.h>

typedef struct{
    int *A ;
    int length ;
    int size ;

}Array ;

int * findPair(Array arr){
    int * result;
    result = (int * )malloc(2*sizeof(int));
    // Here all you have to do is find the
    // The complement of each elements
    // Then add them as pair.
    // If the array is not sorted use the hasmap
    // or sort the array
    // depending of what you are optimizing for.
    return result;
}

int * findPairInSortedArray(Array arr){
    // In this case since the list is aleady
    // You can use two pointer, 
    // One to increament the value of the sum obtain 
    // by the two pointer 
    // And another to decrement that same value
    return NULL;
}

int main(){

    return 0;
}



