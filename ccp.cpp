#pragma region Macros
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0; i<(n); i++)
#define rep1(i, j, n) for(ll i=j; i<(n); i++)
#define all(x) (x).begin(), (x).end()
#define lb(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define ub(c, x) distance((c).begin(), upper_bound(all(c), (x)))
#define drop(s) cout << s << '\n', exit(0)
#pragma endregion


int main() {
    vector<ll> a = {1, 2, 3, 4, 5};
    a.erase(a.begin()+1);
    rep(i,a.size()) cout << a[i] << endl;
    cout << a.size() << endl;
    return 0;
}
