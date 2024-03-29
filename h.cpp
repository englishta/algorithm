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
void Yes() {cout << "Yes" << '\n'; exit(0);}
void No() {cout << "No" << '\n'; exit(0);}

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

template<class T, class A> inline T dup(T num, A waru){ return (num%waru == 0)? num/waru : num/waru+1; }
template<class T> T LCM(T a, T b){ return (a*b)/__gcd(a, b);}
template<class T>char chr(T number){ return char('0'+number); }//int(0..9)->char('0'..'9')
ll bai(ll n){ll t=1; rep(i,n) t*=2; return t;}// 2^n
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


ll t[50][50];
ll p[50][50];


pair<ll, string> dfs(ll i, ll j, string track, ll score, char c, vector<bool> used){

    if(used[t[i][j]] == false) return make_pair(score, track);
    used[t[i][j]] = false; // 訪問
    if(c!='a') track+=c;
    score+=p[i][j];
    ll best_score=-1;
    string best_track;

    if(i-1>=0){
        auto e = dfs(i-1, j, track, score, 'U', used);
        if(e.first>best_score){
            best_score = e.first;
            best_track = e.second;
        }
    }
    if(i+1<50){
        auto e = dfs(i+1, j, track, score, 'D', used);
        if(e.first>best_score){
            best_score = e.first;
            best_track = e.second;
        }
    }
    if(j-1>=0){
        auto e = dfs(i, j-1, track, score, 'L', used);
        if(e.first>best_score){
            best_score = e.first;
            best_track = e.second;
        }
    }
    if(j+1<50){
        auto e = dfs(i, j+1, track, score, 'R', used);
        if(e.first>best_score){
            best_score = e.first;
            best_track = e.second;
        }
    }
    return make_pair(best_score, best_track);
    
}

int main(){
    
    ll si, sj;
    cin >> si >> sj;
    vector<bool> used(250, true);// true->未訪問

    rep(i,50) rep(j,50) cin >> t[i][j];
    rep(i,50) rep(j,50) cin >> p[i][j];

    auto e = dfs(si, sj, "", 0, 'a', used);
    string ans = e.second;
    cout << ans << endl;

    return 0;

}
