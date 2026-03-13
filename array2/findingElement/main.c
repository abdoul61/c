#include<stdlib.h>
#include<stdio.h>

typedef struct{
    int *A;
    int length;
    int size;

}Array ;

// Sorted Array
int findMissing(Array arr){
    int idx;
    int accu = 0;
    for(idx = 0; idx < arr.length; idx++){
        accu += arr.A[idx];
    }
    int totalValues = (arr.A[arr.length-1] * (arr.A[arr.length-1] + 1))/2;

    printf("total: %d\n",totalValues);
    printf("accumulation: %d\n",accu);
    return totalValues - accu;
    return 0;
}

// Array starting at different any level
int find_missing(Array arr){
    int result = 0;
    int i;
    int spread = arr.A[0] - 0;
    for(i = 0; i < arr.length -1; i++){
        if (arr.A[i] > spread){
            result = arr.A[i-1] + 1;
        }
    }
    return result;
}

// Missing element in an unsorted array.
int * findMissingUnsortedArray(Array arr){
    // Time complexity still O(n) however space complexity is also O(n)
    // You can either sort the initial array 
    // or Just use a different array 
    // Assuming you know the largest element 
    // and you also know the smallest element
    int high ;
    int low;
    int * result;
    result = (int *) malloc((high) * sizeof(int));
    int i;
    for(i = 0; i < arr.length; i++){
        result[arr.A[i]]++;
    }
    int y;
    for(y = low; y < high; y++){
        if(result[y] == 0){
            printf("this %d element is missing",y);
        }
    }
    return result;
}
int * findMultipleMissingElement(Array arr){
    int * result;
    result = (int * ) malloc(arr.length * sizeof(int));
    int spread = arr.A[0] - 0;
    int missingIdx = 0;
    int i ;
    for(i = 0; i < arr.length; i++ ){
        if (arr.A[i] != spread){
            int nbr_element = arr.A[i] - i; 
            while(nbr_element > 0){
                result[missingIdx++] = nbr_element + arr.A[i];
                spread++;
                nbr_element--;
            }
        }
    }
    return result;
}

int main(int argc, char *argv[])
{
    Array  arr;
    printf("Enter the size of the array\n");
    scanf("%d",&arr.size);
    arr.length = 0;
    arr.A = (int *)malloc(arr.size * sizeof(int));
    int idx;
    for(idx = 0; idx < arr.size; idx++){
        printf("Enter an element\n");
        scanf("%d",&arr.A[idx]);
        arr.length++;
    }
    int result = findMissing(arr);
    printf("The missing element is:%d ", result);
    result = find_missing(arr);
    printf("The missing element is:%d ", result);
    return EXIT_SUCCESS;
}
