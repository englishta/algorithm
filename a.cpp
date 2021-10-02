#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = std::pair<ll, ll>;
#define rep(i,n) for(ll i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
#define lb(c, x) distance((c).begin(), lower_bound(all(c), (x)))


int main() {
    ll a, b, c; cin >> a >> b >> c;
    for(ll i=a; i<=b; i++){
        if(i%c == 0){
            cout << i << "\n";
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
