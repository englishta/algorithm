#pragma region Macros
#include<bits/stdc++.h>
//#include<atcoder/all>
//using namespace atcoder;
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using Graph = vector<vector<ll>>;//   vector<vector<ll>>v(n,vector<ll>(k, 0));
#define rep(i,n) for(ll i=0; i<n; i++)
#define loop(i, j, n) for(ll i=j; i<n; i++)
#define all(x) (x).begin(), (x).end()
#define UNIQUE(v) v.erase(unique(all(v)), v.end());
#define Sp(p) cout<<setprecision(25)<< fixed<<p<<endl;
#define lb(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define ub(c, x) distance((c).begin(), upper_bound(all(c), (x)))
constexpr int INF  = 0x3f3f3f3f;
const long long mod=1e9+7;
const long double PI = acos(-1);
template<class T, class S> inline bool chmax(T &a, const S &b){ 
    if (a<b){ 
        a = b; 
        return 1; 
    } 
    return 0; 
}
template<class T, class S> inline bool chmin(T &a, const S &b){
    if (a>b){
        a = b;
        return 1; 
    } 
    return 0; 
}
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
template<class Head, class... Tail> void IN(Head &head, Tail &... tail)
{
    scan(head);
    IN(tail...);
}
template<typename T> void OutVector(vector<T>& aData)
{ 
    for(auto& x : aData) cout << x << " "; 
    cout << endl; 
}
/* ------------------------------------------------------------------------- */
#pragma endregion

void solve() {    
    LL(n, W);
    vector<ll> w(n), v(n);
    vector<vector<ll>> dp(n+1, vector<ll>(1e5+1, INF));
    rep(i,n+1) dp[i][0];

    rep(i,n) cin >> w[i] >> v[i];

    dp[0][0] = 0;
    for(ll i=1; i<n+1; i++){//n<=1e2
        for(ll j=0; j<1e5+1; j++){
            dp[i][j]=dp[i-1][j];
            if(j-v[i]>=0) chmin(dp[i][j], dp[i-1][j-v[i-1]]+w[i-1]);
        }
    }
    ll ans = 1e5;
    while(dp[n][ans]>W) ans--;
    cout << ans << endl;
    return;

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
