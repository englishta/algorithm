#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0; i<n; i++)


int main() {
    ll x, y, a, b;
    int ans = 0;
    cin >> x >> y >> a >> b;
    while(x < min(y, b / (a - 1)) / a) {
        x *= a;
        ans++;
    }
    cout << ans + (y - x) / b - ((y - x) % b == 0) << endl;
	return 0;
}