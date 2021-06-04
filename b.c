#include<stdio.h>
int main(){
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    a=a*a;
    b=b*b;
    c=c*c;
    if(a+b<c){
        printf("Yes\n");
    }else{
        printf("No\n");
    }
    return(0);
}