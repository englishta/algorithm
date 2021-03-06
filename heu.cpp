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
double P_score(ll r, ll s){
    double sub = (1-min(r, s)/(double)max(r, s));
    return 1-sub*sub;
}


int main() {
    LL(n);
    vll x(n), y(n), r(n), s(n);
    vll a(n), b(n), c(n), d(n);//(x1, y1), y(x2, y2)taikakusen
    vector<double> p(n);
    ll Max_len=100000;
    vll x_ray(Max_len+1);
    vll y_ray(Max_len+1);

    rep(i,n){
        cin >> x[i] >> y[i] >> r[i];
        x_ray[x[i]]++; y_ray[y[i]]++;
    }
    rep(i,15) cout << x_ray[i] << " ";
    cout << endk;

    rep(i,n){
        ll t = 2;

        a[i]=x[i];
        c[i]=x[i]+1;
        b[i]=y[i];
        d[i]=y[i]+1;


        for(ll J=1; J<=t; J++){
            if(x_ray[x[i]-J]!=0 || x[i]-J<0) break;
            a[i]=x[i]-J;
        }
        for(ll J=1; J<=t; J++){
            if(x_ray[x[i]+J]!=0 || x[i]+J>Max_len) break;
            c[i]=x[i]+J;
        }

        for(ll J=1; J<=t; J++){
            if(y_ray[y[i]-J]!=0 || y[i]-J<0) break;
            b[i]=y[i]-J;
        }
        for(ll J=1; J<=t; J++){
            if(y_ray[y[i]+J]!=0 || y[i]+J>Max_len) break;
            d[i]=y[i]+J;
        }
        
        for(ll J=a[i]; J<=c[i]; J++) x_ray[J]++;
        for(ll J=b[i]; J<=d[i]; J++) y_ray[J]++;
    }
    rep(i,n) s[i]=(d[i]-b[i])*(c[i]-a[i]);
    rep(i,n) p[i]= P_score(r[i], s[i]);
//    rep(i,n) cout << p[i] << endl;
//    double Ans = 0;
//    rep(i,n) Ans+=p[i];
//    Ans = 1000000000*Ans/n;

//    cout << Ans << endk;

//Output Answer
    // cout << "*****************************" << endl;
    rep(i,n) cout << a[i] << " " << b[i] << " " << c[i] << " " << d[i] << endk;
    rep(i,15) cout << x_ray[i] << " ";
    cout << endk;
    rep(i,15) cout << y_ray[i] << " ";
    cout << endk;
    return 0;
}
