#include<stdio.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep1(i, J, n) for(int i=(J); i<(n); i++)

int main(void){
    char s[4]; // char型の配列
    scanf("%s", s);
    printf("%c%c%c\n", s[1], s[2], s[0]);

    return 0;
}