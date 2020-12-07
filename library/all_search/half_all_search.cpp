#pragma region Macros
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
#define lb(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define ub(c, x) distance((c).begin(), upper_bound(all(c), (x)))

int main(void){
    ll N, T; cin >> N >> T;

    vector<ll> a(N);
    rep(i,N) cin >> a.at(i);

    vector<ll> A;
    for (ll bit = 0; bit < (1 << N / 2); bit++) {
        ll sum = 0;
        for (ll i = 0; i < (N / 2); i++) {
            ll mask = 1 << i;
            if (bit & mask) {
                sum += a[i];
            }
        }
        A.push_back(sum);
    }
    vector<ll> B;
    for (ll bit = 0; bit < (1 << (N - N / 2)); bit++) {
        ll sum = 0;
        for (ll i = 0; i < (N - N / 2); i++) {
            ll mask = 1 << i;
            if (bit & mask) {
                sum += a[N / 2 + i];
            }
        }
        B.push_back(sum);
    }
    ll Max_sum=0;
    sort(all(B));

    for(auto x : A){
        if(T-x>=0 && upper_bound(all(B), T-x) != B.begin()){
            Max_sum = max(Max_sum, x+B[ub(B, T-x)-1]);
        }
    }
    cout << Max_sum << endl;
}
