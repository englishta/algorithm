#include<bits/stdc++.h>
//#include<atcoder/all>
// Begin Header {{{
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
template<typename T> void OutVector(vector<T>& aData){ for(auto& x : aData){ cout << x << " "; } cout << endl; }
// }}} End Header
    
void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll min= a[0];
    rep(i,n){
        if(a[i]%min != 0){
            a[i]%=min;
            if(a[i]<min) min = a[i];
        }
        else{
            a[i] = min;
        } 
    }
    cout << min << endl;
}

int main() {
//#ifdef FILEINPUT
    std::ifstream ifs("./input.txt");
    std::cin.rdbuf(ifs.rdbuf());
//#endif
//#ifdef FILEOUTPUT
    std::ofstream ofs("./output.txt");
    std::cout.rdbuf(ofs.rdbuf());
//#endif
    solve();
    return 0;
}