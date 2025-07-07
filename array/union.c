#include <stdlib.h>
#include <stdio.h>

struct Array{
    int A[20];
    int size;
    int length;
}

void swap(int *a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

struct Array * union(struct Array *arr1, struct Array * arr2){
    int i, j, k;
    i = j = k = 0;
    struct Array * result;
    result = (struct Array *)malloc(sizeof(struct Array));

}
int main(){
    return 0;
}
