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

std::vector<ll> Eratos_sieve(ll n){
	//[0, n]のインデックスに対して、最小の素因数を記録するリスト
	vector<ll> sieve(n);
	iota(sieve.begin(), sieve.end(), 0);
	for(ll i=2; i*i<n; ++i){
		if(sieve[i] < i) continue;
		for(ll j=i*i; j<n; j+=i){
			if(sieve[j] == j) sieve[j] = i;
		}
	}
	return sieve;
}
void solve() {    

	ll n, ans = 0;
	cin >> n;
	vector<ll> sieve = Eratos_sieve(n+1);

    ll divisors=1;
    map<ll, ll> cnt;
    ll x = n;

    while(x > 1){
        cnt[sieve[x]]++;
        x/=sieve[x];
    }
    for(auto x : cnt){
        ll t= x.second;
        ll sum = 0;
        for(ll k=1; k<1e12; k++){
            if(t>sum && t<=sum+(k+1)){
                ans+=k;
                break;
            }
            sum+=k+1;
        }
    }
	cout << ans << endl;

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}