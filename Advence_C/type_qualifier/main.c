#include <stdio.h>
#include <stdlib.h>

int main(void){
    printf("Hello world\n");
    // If you place the * before the 
    const float *pt; // pt points to const value
    float * const pf; // pf points to const pointer
    
    // volalite qualifier tells the compiler not to optmise or cache that valie 
    // because it will change.
    // Restric qualifier tell the compiler that any pointer that has 
    // that qualifier; it's value will never be assigned by any other pointer.
    //
    int array[10];
    int * restrict restart = (int *) malloc(10 * sizeof(int));
    int * par = array;
    // if we loop over the values of restart the and make changes to the
    // values the compiler can actually optimize the instructions if it makes sense
    // however looping over the array par, the compiler will not make an assumption
    // because the another pointer could be modifying the values. 

    return 0;
}
