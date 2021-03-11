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

const long double k = 99.5;

double P_score(ll r, ll s){
    double sub = (1-min(r, s)/(double)max(r, s));
    return 1-sub*sub;
}
long double ALL_score(ll n, vll a, vll b, vll c, vll d, vll r){
    long double Sum=0;
    rep(i,n) Sum+=P_score(r[i], (c[i]-a[i])*(d[i]-b[i]));
    return 1000000000*Sum/n;
}

void Set_Table(ll n, vll &X, vll &Y, vll a, vll b, vll c, vll d, vector<vll> &v2){
    ll X_mx=-1; ll Y_mx=-1;
    X=vector<ll>();
    Y=vector<ll>();
    X.eb(0); Y.eb(0);

    rep(J,n){
        X.eb(a[J]);
        X.eb(c[J]);
        Y.eb(b[J]);
        Y.eb(d[J]);
        chmax(X_mx, c[J]);
        chmax(Y_mx, d[J]);
    }
    sort(all(X));
    sort(all(Y));
    X.erase(unique(X.begin(),X.end()),X.end());
    Y.erase(unique(Y.begin(),Y.end()),Y.end());

    v2 = vector<vector<ll>> (4*n, vector<ll>(4*n, 0));


    for(ll J=0; J<n; J++){
        ll x1=lb(X, a[J]);
        ll x2=lb(X, c[J]);
        ll y1=lb(Y, b[J]);
        ll y2=lb(Y, d[J]);

// v2 : 長方形の可視化
        for(ll x_=x1; x_<=x2; x_++){
            for(ll y_=y1; y_<=y2; y_++){
                v2[x_][y_]++;
            }
        }
    }
    ll Endx_idx = lb(X, X_mx);
    ll Endy_idx = lb(Y, Y_mx);

    for(ll x_=0; x_<=Endx_idx+1; x_++){
        v2[x_][Endy_idx+1]=-1;
    }
    for(ll y_=0; y_<=Endy_idx+1; y_++){
        v2[Endx_idx+1][y_]=-1;
    }
}

void Search_Y_pls(ll n, vll &X, vll &Y, vll &a, vll &b, vll &c, vll &d, vector<vll> &v2, vll r){

    for(ll i=0; i<n; i++){
        ll x1=lb(X, a[i]);
        ll x2=lb(X, c[i]);
        ll y1=lb(Y, b[i]);
        ll y2=lb(Y, d[i]);
        ll od = d[i];
        ll s = (c[i]-a[i])*(d[i]-b[i]);
        if(100*P_score(r[i], s)>k) continue;

        for(ll y_=y2+1; ; y_++){
            bool f=false;
            for(ll x_=x1; x_<=x2; x_++){
                if(v2[x_][y_]>0){
                    if(s<r[i]){
                        if(sqrt(r[i])>d[i]-b[i]) d[i]+=min((ll)sqrt(r[i])-(d[i]-b[i])+10, 3*(Y[y_]-d[i])/4);
                        else d[i]+=(Y[y_]-d[i])/4;
                        chmin(d[i], 10000);
                    }
                    f = true;
                }else if(v2[x_][y_]==-1){
                    if((d[i]-b[i])<sqrt(r[i])){
                        d[i]+=(ll)sqrt(r[i])-(d[i]-b[i]);
                        chmin(d[i], 10000);
                    }else if(s<r[i]){
                        d[i]+=(r[i]-s)/(4*(c[i]-a[i]));
                        chmin(d[i], 10000);
                    }
                    f = true;
                }
                ll ns = (d[i]-b[i])*(c[i]-a[i]);
                if(P_score(r[i], ns)<P_score(r[i], s)) d[i] = od;
                if(f) break;
            }
            if(f){
                Set_Table(n, X, Y, a, b, c, d, v2);
                break;
            }
        }
    }
}

void Search_X_pls(ll n, vll &X, vll &Y, vll &a, vll &b, vll &c, vll &d, vector<vll> &v2, vll r){

    for(ll i=0; i<n; i++){
        ll x1=lb(X, a[i]);
        ll x2=lb(X, c[i]);
        ll y1=lb(Y, b[i]);
        ll y2=lb(Y, d[i]);
        ll s = (c[i]-a[i])*(d[i]-b[i]);
        ll oc = c[i];
        if(100*P_score(r[i], s)>k) continue;

        for(ll x_=x2+1; ; x_++){
            bool f=false;
            for(ll y_=y1; y_<=y2; y_++){
                if(v2[x_][y_]>0){
                    if(s<r[i]){
                        if(sqrt(r[i])>(c[i]-a[i])) c[i]+=min((ll)sqrt(r[i])-(c[i]-a[i])+10, 3*(X[x_]-c[i])/4);
                        else c[i]+=abs(X[x_]-c[i])/4;
                        chmin(c[i], 10000);
                    }
                    f = true;
                }else if(v2[x_][y_]==-1){
                    if((c[i]-a[i])<sqrt(r[i])){
                        c[i]+=abs((ll)sqrt(r[i])-(c[i]-a[i]));
                        chmin(c[i], 10000);
                    }else if(s<r[i]){
                        c[i]+=(r[i]-s)/(4*(d[i]-b[i]));
                        chmin(c[i], 10000);
                    }
                    f = true;
                }
                ll ns = (d[i]-b[i])*(c[i]-a[i]);
                if(P_score(r[i], ns)<P_score(r[i], s)) c[i] = oc;
                if(f) break;
            }
            if(f){
                Set_Table(n, X, Y, a, b, c, d, v2);
                break;
            }
        }
    }
}

void Search_X_mi(ll n, vll &X, vll &Y, vll &a, vll &b, vll &c, vll &d, vector<vll> &v2, vll r){

    for(ll i=0; i<n; i++){
        ll x1=lb(X, a[i]);
        ll x2=lb(X, c[i]);
        ll y1=lb(Y, b[i]);
        ll y2=lb(Y, d[i]);
        ll s = (c[i]-a[i])*(d[i]-b[i]);
        ll oa = a[i];
        if(100*P_score(r[i], s)>k) continue;

        for(ll x_=x1-1; x_>=0; x_--){
            bool f=false;
            for(ll y_=y1; y_<=y2; y_++){
                if(v2[x_][y_]>0){
                    if((d[i]-b[i])*(c[i]-a[i])<r[i]){
                        if(sqrt(r[i]>c[i]-a[i]))a[i]-=min((ll)sqrt(r[i])-(c[i]-a[i])+10, 3*(a[i]-X[x_])/4);
                        else a[i]-=(a[i]-X[x_])/4;
                        chmax(a[i], 0ll);
                    }
                    f = true;
                }else if(x_==0){
                    if(c[i]-a[i]<(ll)sqrt(r[i])){
                        a[i]-=(ll)sqrt(r[i])-(c[i]-a[i]);
                        chmax(a[i], 0ll);
                    }else if(s<r[i]){
                        a[i]-=(r[i]-s)/(4*(d[i]-b[i]));
                        chmax(a[i], 0ll);
                    }
                    f = true;
                }
                ll ns = (d[i]-b[i])*(c[i]-a[i]);
                if(P_score(r[i], ns)<=P_score(r[i], s)) a[i] = oa;
                if(f) break;
            }
            if(f){
                Set_Table(n, X, Y, a, b, c, d, v2);
                break;
            }
        }
    }
}

void Search_Y_mi(ll n, vll &X, vll &Y, vll &a, vll &b, vll &c, vll &d, vector<vll> &v2, vll r){

    for(ll i=0; i<n; i++){
        ll x1=lb(X, a[i]);
        ll x2=lb(X, c[i]);
        ll y1=lb(Y, b[i]);
        ll y2=lb(Y, d[i]);
        ll s = (c[i]-a[i])*(d[i]-b[i]);
        ll ob=b[i];
        if(100*P_score(r[i], s)>k) continue;

        for(ll y_=y1-1; y_>=0; y_--){
            bool f=false;
            for(ll x_=x1; x_<=x2; x_++){
                if(v2[x_][y_]>0){
                    if(s<r[i]){
                        if(sqrt(r[i])>(d[i]-b[i])) b[i]-=min((ll)sqrt(r[i])-(d[i]-b[i])+10, 3*(b[i]-Y[y_])/4);
                        else b[i]-=(b[i]-Y[y_])/4;
                        chmin(b[i], d[i]);
                    }
                    f = true;
                }else if(y_==0){
                    if(d[i]-b[i]<(ll)sqrt(r[i])){
                        b[i]-=(ll)sqrt(r[i])-(d[i]-b[i]);
                        chmax(b[i], 0ll);
                    }else if(s<r[i]){
                        b[i]-=(r[i]-s)/(4*(c[i]-a[i]));
                        chmax(b[i], 0ll);
                    }
                    f = true;
                }
                ll ns = (d[i]-b[i])*(c[i]-a[i]);
                if(P_score(r[i], ns)<P_score(r[i], s)) b[i]=ob;
                if(f) break;
            }
            if(f){
                Set_Table(n, X, Y, a, b, c, d, v2);
                break;
            }
        }
    }
}




int main() {
    LL(n);
    vll X, Y;
    vll x(n), y(n), r(n), s(n);
    vll a(n), b(n), c(n), d(n);
    vv(ll, v2, 4*n, 4*n);

    rep(i,n){
        cin >> x[i] >> y[i] >> r[i];
        a[i]=c[i]=x[i]; b[i]=d[i]=y[i];
        c[i]++; d[i]++;
    }

    Set_Table(n, X, Y, a, b, c, d, v2); 

        
    rep(i,20){
        Search_Y_pls(n, X, Y, a, b, c, d, v2, r);
        Search_X_pls(n, X, Y, a, b, c, d, v2, r);
        Search_X_mi(n, X, Y, a, b, c, d, v2, r);
        Search_Y_mi(n, X, Y, a, b, c, d, v2, r);
    }

    // cout << endk;
    // drop(ALL_score(n, a, b, c, d, r));


//Output Answer
    // cout << '\n';
    // cout << "*****************************" << endl;
    // cout << '\n';
    rep(i,n) cout << a[i] << " " << b[i] << " " << c[i] << " " << d[i] << endk;

    return 0;
}

