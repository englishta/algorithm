#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0; i<n; i++)

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll min= a[0];
    rep(i,n){
        if(a[i]%min != 0){
            a[i]%=min;
            if(a[i]<min) min = a[i];
        }
        else{
            a[i] = min;
        } 
    }
    cout << min << endl;
	return 0;
}