#pragma region Macros
#include<bits/stdc++.h>
//#include<atcoder/all>
//using namespace atcoder;
using namespace std;
using ll = long long;
#define endk '\n'
#define pf(a, e) a.insert(a.begin(), e)
#define pb push_back
#define eb emplace_back
#define vi vector<int>
#define vll vector<ll>
#define rep(i,n) for(ll i=0; i<(n); i++)
#define Rep(i, j, n) for(ll i=j; i<(n); i++)
#define vv(type, name, h, ...) vector<vector<type>> name(h, vector<type>(__VA_ARGS__))
#define vvv(type, name, h, w, ...) vector<vector<vector<type>>> name(h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))
#define drop(s) cout << s << endk, exit(0)
#define print(x) cout << (x) << '\n'
#define all(x) (x).begin(), (x).end()
#define UNIQUE(v) v.erase(unique(all(v)), v.end())
#define SP(num, keta) cout << setprecision(keta) << fixed <<num<< '\n'
#define lb(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define ub(c, x) distance((c).begin(), upper_bound(all(c), (x)))
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
#define debug(var)  do{std::cout << #var << " : ";view(var);}while(0)
template<typename T> void view(T e){std::cout << e << std::endl;}
template<typename T> void view(const std::vector<T>& v){for(const auto& e : v){ std::cout << e << " "; } std::cout << std::endl;}
template<typename T> void view(const std::vector<std::vector<T> >& vv){ for(const auto& v : vv){ view(v); } }

void dump() { cerr << '\n'; }
template <class Head, class... Tail> void dump(Head head, Tail... tail) {
    cerr << to_string(head) << " ";
    dump(tail...);
}
#define Dump(...) cout<<"  "; \
cout<<#__VA_ARGS__<<" :["<<__LINE__<<":"<<__FUNCTION__<<"]"<<endl; \
cout<<"   "; \
dump(__VA_ARGS__)

template<class T, class A> inline T dup(T num, A waru){
    return (num%waru == 0)? num/waru : num/waru+1; 
}
template<class T> T LCM(T a, T b){ return (a*b)/__gcd(a, b);}

template<class T>
vector<T> compress(vector<T> &X){
    vector<T> Uni = X;
    sort(all(Uni));
    UNIQUE(Uni);
    for(ll i=0; i<(ll)X.size(); i++) X[i]=lb(Uni, X[i]);
    return X; 
}
//デバッグ方法
//debug(配列、変数など一つだけ);
//Dump(変数を複数 a, b, c);
//多次元配列初期化方法
// vv(int, seq, 5, 5, -1);
// vv(型, 名前, 縦, 横, 埋める数);
/* ------------------------------------------------------------------------- */
#pragma endregion   

int main() {
    LL(n);
    vll X, Y, xs(n), xe(n), ys(n), ye(n);
    
    rep(i,n){
        LL(a, b, c, d);
        xs[i]=a; xe[i]=c; ys[i]=b; ye[i]=d;

        X.eb(a);
        X.eb(c);
        Y.eb(b);
        Y.eb(d);
    } 
    X.eb(0);
    Y.eb(0);

    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());


    X.erase(unique(X.begin(),X.end()),X.end());
    Y.erase(unique(Y.begin(),Y.end()),Y.end());
    // debug(X);
    // debug(Y);

    vv(ll, v1, 2*n+1, 2*n+1);
    vv(ll, v2, 2*n+1, 2*n+1);

    for(ll i=0; i<n; i++){
        ll x1=lb(X, xs[i]);
        ll x2=lb(X, xe[i]);
        ll y1=lb(Y, ys[i]);
        ll y2=lb(Y, ye[i]);

// v1 : 頂点の座標

        v1[x1][y1]++;
        v1[x2][y2]++;
        v1[x1][y2]++;
        v1[x2][y1]++;

// v2 : 長方形の可視化

        for(ll x_=x1; x_<=x2; x_++){
            for(ll y_=y1; y_<=y2; y_++){
                v2[x_][y_]++;
            }
        }
    }

    debug(v2);
    cout << endk;
    debug(v1);


// input
// n
// a, b, c, d

// (a, b), (c, d)が対角線の頂点のである長方形

// 2
// 1 1 3 3
// 2 2 4 4

// output
// 0 0 0 0 0 
// 0 1 0 1 0 
// 0 0 1 0 1 
// 0 1 0 1 0 
// 0 0 1 0 1
    
    

    

    return 0;
}
