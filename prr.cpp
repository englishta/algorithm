#include<bits/stdc++.h>
//#include<atcoder/all>
// Begin Header {{{
//using namespace atcoder;
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using Graph = vector<vector<ll>>;
#define rep(i,n) for(ll i=0; i<n; i++)
#define loop(i, j, n) for(ll i=j; i<n; i++)
#define all(x) (x).begin(), (x).end()
#define UNIQUE(v) v.erase(unique(all(v)), v.end());
#define Sp(p) cout<<setprecision(25)<< fixed<<p<<endl;
constexpr int INF  = 0x3f3f3f3f;
const long long mod=1e9+7;
const long double PI = acos(-1);
template<class T, class S> inline bool chmax(T &a, const S &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T, class S> inline bool chmin(T &a, const S &b) { if (a>b) { a = b; return 1; } return 0; }
#define INT(...)                                                                                                                                               \
    int __VA_ARGS__;                                                                                                                                           \
    IN(__VA_ARGS__)
#define LL(...)                                                                                                                                                \
    ll __VA_ARGS__;                                                                                                                                            \
    IN(__VA_ARGS__)
#define STR(...)                                                                                                                                               \
    string __VA_ARGS__;                                                                                                                                        \
    IN(__VA_ARGS__)
#define CHR(...)                                                                                                                                               \
    char __VA_ARGS__;                                                                                                                                          \
    IN(__VA_ARGS__)
#define DBL(...)                                                                                                                                               \
    double __VA_ARGS__;                                                                                                                                        \
    IN(__VA_ARGS__)
template<class T> void scan(T &a) { cin >> a; }
void IN() {}
template<class Head, class... Tail> void IN(Head &head, Tail &... tail){ scan(head); IN(tail...); }
// }}} End Header
    
int main() {
    LL(n, k);
    vector<vector<ll>> a(n, vector<ll>(k));
    rep(i,n) rep(j,k) cin >> a[i][j];
    vector<vector<ll>> dp(1e4+10, vector<ll>(1e4+10, 0));
    rep(i,k) dp[0][i]++;

    for(ll i=0; i<n; i++){
        for(ll j=0; j<k; j++){
            ll pos = distance(a.begin(), lower_bound(all(a), a[i][j]));
            dp[i+1][j]+=dp[i][pos-1];
            dp[i+1][j]%=mod;
        }
        for(ll t=1; t<k; t++){
            dp[i+1][t]+=dp[i][t-1];
            dp[i+1][t]%=mod;
        }
    }
    ll ans = 0;
    rep(i,k) ans+=dp[n-1][i];
    cout << ans << endl;
	return 0;
}