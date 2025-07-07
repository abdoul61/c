#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

bool isDuplicate(char s[]){
    int long h,x;
    int i;
    h = 0;
    for(i = 0; s[i] != '\0'; i++){
        x = 1;
        x = x << (s[i] - 97);
        if((h&x) > 0){
            return true;
        }else{
            h = x | h;
        }

    }
    return false;
}

int main(){
    char name[] = "findings";
    bool word = isDuplicate(name);
    if(word){
        printf("They are duplicate\n");
    }else{
        printf("There are no duplicate\n");
    }
    return 0;
}
