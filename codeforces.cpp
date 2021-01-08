#pragma region Macros
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()

void solve(){
    ll n; cin >> n;
    ll a=0, b=0;
    rep(i,n){
        ll num; cin >> num;
        if(num == 2) a++;
        else b++;
    }

    if(b%2==0 && a%2 == 0){
        cout << "YES" << endl;
        return;
    }
    else{
        for(ll i=1; i<=a; i++){
            if(2*i == 2*(a-i)+b){
                cout << "YES" << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while(t--){solve();}
    return 0;
}
