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
void Yes(bool b) { cout << (b ? "Yes" : "No") << '\n'; }
void YES(bool b) { cout << (b ? "YES" : "NO") << '\n'; }
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
// 素因数分解 O(√n)
// たとえば 60 = 2^2 x 3 x 5 だったら {(2, 2), (3, 1), (5, 1)} を返す
// 素因数の個数はlogn
class Eratos{
    public:

	vector<ll> array;//0～N-1までの最小の素因数を格納するリスト
	ll N;

	Eratos(ll size){
		array = vector<ll>(size);
		N = size;
		iota(array.begin(), array.end(), 0);
	}

	vector<ll> make(){
		for(ll i=2; i*i<N; ++i){
			if(array[i] < i) continue;
			for(ll j=i*i; j<N; j+=i){
				if(array[j] == j) array[j] = i;
			}
		}
		return array;
	}

	map<ll, ll> factor(ll x){
		map<ll, ll> cnt;
		while(x>1){
			cnt[array[x]]++;
			x/=array[x];
		}
		return cnt;
	}

};


void solve() {
    LL(n);
    Eratos clas(n+1);
    clas.make();
    auto cnt = clas.factor(n);
	ll ans = 0, x = n;
    
    for(auto x : cnt){
        ll t= x.second;
        ll tmp=1;
        while(tmp<=t){
            t-=tmp;
            tmp++;
        }
        ans+=tmp-1;
    }
	cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}

