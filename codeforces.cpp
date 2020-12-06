
#pragma region Macros
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0; i<(n); i++)

ll manh(pair<ll, ll> v1, pair<ll, ll> v2){
    ll Dist = abs(v1.first-v2.first)+abs(v1.second-v2.second);
    return Dist;
}

void solve(){
    ll n, k; cin >> n >> k;
    vector<pair<ll, ll>> ary(n); 

    for(int i=0; i<n; i++){
        cin >> ary[i].first >> ary[i].second;
    }

    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(manh(ary[i], ary[j])>k){
                cout << -1 << endl;
                return;
            }
        }
    }
    cout << 1 << endl;
    return;
}

int main(void){
    ll t; cin >> t;
    while(t--){solve();}
    return 0;
}
