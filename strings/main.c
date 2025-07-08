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
void display(char *arr,int n){
    int i;
    for(i=0; i < n; i++){
        printf("%d ",arr[i]);
    }
}
bool isAnagram(char s[],char t[]){
    size_t slen = sizeof(s) / sizeof(s[0])-1;
    size_t tlen = sizeof(t) / sizeof(t[0])-1;
    char * hash;
    int i,j;
    hash = (char *)malloc(26 * sizeof(char));
    if (slen != tlen) return false;
    for(i = 0; s[i] != '\0'; i++){
        hash[s[i] - 97] += 1;
    }
    for(j = 0; t[j] != '\0'; j++){
        hash[t[j] - 97] -= 1;
        if(hash[t[j] - 97] < 0){
            return false;
        }
    }
    printf("\n");
    display(hash,26);
    free(hash);
    return true;
}
int main(){
    char a[] = "anagram";
    char b[] = "namagra";
    bool result = isAnagram(a,b);
    printf("result is: %d\n",result);
    char name[] = "findings";
    bool word = isDuplicate(name);
    if(word){
        printf("They are duplicate\n");
    }else{
        printf("There are no duplicate\n");
    }
    return 0;
}
