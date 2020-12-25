#pragma region Macros
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
#define lb(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define ub(c, x) distance((c).begin(), upper_bound(all(c), (x)))
#define drop(s) cout << s << '\n', exit(0)
#pragma endregion


int main() {
    ll n; cin >> n; 
    if(n == 1) drop("Not Prime");
    bool flag = true;
    for(ll i=2; i*i<=n; i++){
        if(n%i == 0) flag = false; 
    }
    if(flag) drop("Prime");

    ll k = n;
    if(k%3 != 0 && k%2 != 0 && k%5 != 0) drop("Prime");
    drop("Not Prime"); 
    return 0;
}