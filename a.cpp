#include<bits/stdc++.h>
#define ll long long
#define rep(i,n) for(ll i=0; i<n; i++)
using namespace std;

vector<ll> func(ll n){
    vector<ll> an;
    ll cnt = 0;
    for(ll p=n-1; p>=2; p--){
        if(n%p!=0) continue;
        while(n%p==0 && n/p > 1){
            cnt++;
            n/=p;
        }
    }
    an.push_back(cnt);
    an.push_back(n);
    return an;
}


int main(void){
    ll t;
    cin >> t;
    rep(i,t){
        ll n; 
        cin >> n;
        auto v = func(n);
        cout << v[0]+v[1]-1 << endl;
    }

    return 0;    
}