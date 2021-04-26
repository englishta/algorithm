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

constexpr int m = 50;
// タイルの整数値とポイントの配列
vector<vector<int>> G(m, vector<int>(100));
vector<vector<int>> p(m, vector<int>(100));
// 既に到達したかを管理する配列
vector<vector<int>> used(m, vector<int>(100, 0));
// 進む方向の配列
vector<int> dx={1, -1, 0, 0};
vector<int> dy={0, 0, 1, -1};
string s = "DURL";
// スコア
ll score = 0;
// 移動経路を記録する配列
vector<char> v;

void solve(int x, int y){
    vector<int> sect;

    for(ll k=0; k<4; k++){
        int nx=x+dx[k];
        int ny=y+dy[k];

        if(nx<0 || nx>=m || ny<0 || ny>=m) continue;
        if(used[nx][ny]!=0 || G[x][y] == G[nx][ny]) continue;
        sect.push_back(k);
    }

    if(sect.size() == 0) return;
    mt19937 mt{ random_device{}() };
    uniform_int_distribution<int> dist(0, sect.size()-1);

    int idx=dist(mt);
    int nx = x+dx[sect[idx]];
    int ny = y+dy[sect[idx]];

    for(ll t=0; t<4; t++){
        ll ax = nx+dx[t]; ll ay = ny+dy[t];
        if(ax<0 || ax>=m || ay<0 || ay>=m) continue;
        if(G[ax][ay] == G[nx][ny]) used[ax][ay]++; 
    }
    used[nx][ny]++;
    v.push_back(s[sect[idx]]);
    score+=G[nx][ny];

    solve(nx, ny);
}

int main() {
    // スタートの値を入力
    int xs, ys;
    cin >> xs >> ys;

    rep(i,m) rep(j,m) cin >> G[i][j];
    rep(i,m) rep(j,m) cin >> p[i][j];

    used[xs][ys]++;

    for(ll t=0; t<4; t++){
        ll ax = xs+dx[t]; ll ay = ys+dy[t];
        if(ax<0 || ax>=m || ay<0 || ay>=m) continue;
        if(G[ax][ay] == G[xs][ys]){
            used[ax][ay]++;
            break;
        }
    }
    // 深さ優先探索start 
    solve(xs, ys);
    // 移動経路出力
    for(auto e : v) cout << e;
    cout << '\n';
    
    return 0;
}