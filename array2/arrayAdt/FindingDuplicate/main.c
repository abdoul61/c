#include<stdlib.h>
#include<stdio.h>

typedef struct{
    int *A ;
    int length ;
    int size ;

}Array ;

void findDeplicate(Array arr){
    int lastDeplicate;
    int count = 0;
    int i;
    for(i = 0; i < arr.length; i++){
        if(i+1 < arr.length && arr.A[i] == arr.A[i+1]){
            if(arr.A[i] != lastDeplicate){
                printf("Found a duplicate %d\n",arr.A[i]);
                lastDeplicate = arr.A[i];
            }
        }
    }
}

void findDeplicateCount(Array arr){
    int i;
    for(i = 0; i < arr.length; i++){
        if(i + 1 < arr.length && arr.A[i] == arr.A[i+1]){
            int y = i;
            int count = 1;
            while(y + 1 < arr.length && arr.A[i] == arr.A[y+1]){
                y++;
                count++;
            }
            printf("The element %d is %d duplicates \n", arr.A[i], count);
            i = y-1;
            printf("Value of y: %d\n", y);
        }
    }
}
void display(Array arr){
    for(int i = 0; i < arr.length; i++){
        printf("%d: ",arr.A[i]);
    }
}

int main(){
    Array arr;
    arr.size = 11;
    arr.length = 0;
    arr.A = (int *)malloc(arr.size * sizeof(int));
    
    
    for(int i = 0; i < arr.size; i++){
        printf("Enter an element \n");
        scanf("%d", &arr.A[i]);
        arr.length++;
    }
    // display(arr);

    findDeplicateCount(arr);
    findDeplicate(arr);

    return 0;
}


