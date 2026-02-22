#include <stdio.h>
#include <stdlib.h>

struct HashMap {
    int * keys;
    int * values;
    int size;
    int index;
};

void put(struct HashMap * map,int key, int value){
   if (key < 0 || key > map->index) {
        printf("key index too big");
        exit(EXIT_FAILURE);
    }
}

int  main(int argc, char *argv[])
{
    struct HashMap mymap;
    printf("Enter the size of your HashMap\n");
    scanf("%d",&mymap.size);
    mymap.keys = (int *)malloc(mymap.size * sizeof(int));
    mymap.values = (int *)malloc(mymap.size * sizeof(int));
    mymap.index = 0;

    return EXIT_SUCCESS;
}
