#include <stdlib.h>
#include <stdio.h>
#include <string.h>


struct Array{
    int *A;
    int size;
    int length; 
};
int display(struct Array arr){
    for(int i = 0; i < arr.length; i++){
        printf("%d\n",arr.A[i]);
    }
}
int main(){
    struct Array arr;
    int n, i;
    printf("Enter a size: \n");
    scanf("%d",&arr.size);
    printf("The size of arr is %d\n",arr.size);
    arr.A = (int *)malloc(arr.size * sizeof(int));
    arr.length = 0;
    printf("Enter the number of elements you want\n");
    scanf("%d",&n);
    
    for(i=0; i < n; i++){
        printf("Enter element number %d\n",i);
        scanf("%d",&arr.A[i]);
        arr.length += 1;
    }
    
    display(arr);
    printf("The number of element in A is %d\n",arr.length);
    return 0;
}
