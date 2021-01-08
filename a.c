#include<stdio.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep1(i, J, n) for(int i=(J); i<(n); i++)

int main(void){
    const int n;
    scanf("%d", &n);
    int a[n];
    int u = 0;
    int d = 0; 
    int ans = 1;

    rep(i,n) scanf("%d", &a[i]);
    rep1(i, 1, n){
        if(u && a[i-1]>a[i]){
            u=0; ans++; 
        }else if(d && a[i-1]<a[i]){
            d=0; ans++;
        }else{
            if(a[i-1]<a[i]) u = 1;
            else if(a[i-1]>a[i]) d = 1;
        }
    }
    printf("%d", ans);
    printf("\n");

    return 0;
}