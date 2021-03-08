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

    rep(i,n){
        cin >> x[i] >> y[i] >> r[i];
        a[i]=c[i]=x[i]; b[i]=d[i]=y[i];
        c[i]++;
        d[i]++;
    }

    // *****************************<デバッグ>****************************

    vll xs(n), xe(n), ys(n), ye(n); 
    vll X, Y;
    ll X_mx=-1, Y_mx=-1;

    rep(i,n){
        xs[i]=a[i]; xe[i]=c[i]; ys[i]=b[i]; ye[i]=d[i];
        X.eb(a[i]);
        X.eb(c[i]);
        Y.eb(b[i]);
        Y.eb(d[i]);

        chmax(X_mx, xe[i]);
        chmax(Y_mx, ye[i]);
    }
    X.eb(0);
    Y.eb(0);

    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());

    X.erase(unique(X.begin(),X.end()),X.end());
    Y.erase(unique(Y.begin(),Y.end()),Y.end());

    vv(ll, v1, 4*n, 4*n);
    vv(ll, v2, 4*n, 4*n);

    ll Endx_idx=lb(X, X_mx);
    ll Endy_idx=lb(Y, Y_mx);

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

    for(ll x_=0; x_<=Endx_idx+1; x_++){
        v2[x_][Endy_idx+1]=-1;
    }
    for(ll y_=0; y_<=Endy_idx+1; y_++){
        v2[Endx_idx+1][y_]=-1;
    }
    // debug(v2);
    // cout << endk;

// *****************************************************************************************


    for(ll i=0; i<n; i++){
        ll x1=lb(X, a[i]);
        ll x2=lb(X, c[i]);
        ll y1=lb(Y, b[i]);
        ll y2=lb(Y, d[i]);
        for(ll y_=y2+1; ; y_++){
            bool f=false;
            for(ll x_=x1; x_<=x2; x_++){
                if(v2[x_][y_]>0){
                    d[i]=min(d[i]+abs(Y[y_]-d[i])/2, (ll)9999);
                    f = true;
                    break;
                }else if(v2[x_][y_]==-1){
                    d[i]=min(d[i]+abs(999-d[i])/2, (ll)9999);
                    f = true;
                    break;
                }
            }
            if(f){
                X_mx=-1; Y_mx-1;
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
            }
            v1 = vector<vector<ll>> (4*n, vector<ll>(4*n, 0));
            v2 = vector<vector<ll>> (4*n, vector<ll>(4*n, 0));


            for(ll J=0; J<n; J++){
                ll x1=lb(X, a[J]);
                ll x2=lb(X, b[J]);
                ll y1=lb(Y, c[J]);
                ll y2=lb(Y, d[J]);

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
            Endx_idx = lb(X, X_mx);
            Endy_idx = lb(Y, Y_mx);

            for(ll x_=0; x_<=Endx_idx+1; x_++){
                v2[x_][Endy_idx+1]=-1;
            }
            for(ll y_=0; y_<=Endy_idx+1; y_++){
                v2[Endx_idx+1][y_]=-1;
            }
            break;
        }
    }
    // cout << "conform-1 movement!!" << endl;
    // debug(v2);

    for(ll i=0; i<n; i++){
        ll x1=lb(X, a[i]);
        ll x2=lb(X, c[i]);
        ll y1=lb(Y, b[i]);
        ll y2=lb(Y, d[i]);
        for(ll y_=y2+1; ; y_++){
            bool f=false;
            for(ll x_=x1; x_<=x2; x_++){
                if(v2[x_][y_]>0){
                    d[i]=min(d[i]+abs(Y[y_]-d[i])/2, (ll)9999);
                    f = true;
                    break;
                }else if(v2[x_][y_]==-1){
                    d[i]=min(d[i]+abs(999-d[i])/2, (ll)9999);
                    f = true;
                    break;
                }
            }
            if(f){
                X_mx=-1; Y_mx-1;
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
            }
            v1 = vector<vector<ll>> (4*n, vector<ll>(4*n, 0));
            v2 = vector<vector<ll>> (4*n, vector<ll>(4*n, 0));


            for(ll J=0; J<n; J++){
                ll x1=lb(X, a[J]);
                ll x2=lb(X, b[J]);
                ll y1=lb(Y, c[J]);
                ll y2=lb(Y, d[J]);

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
            Endx_idx = lb(X, X_mx);
            Endy_idx = lb(Y, Y_mx);

            for(ll x_=0; x_<=Endx_idx+1; x_++){
                v2[x_][Endy_idx+1]=-1;
            }
            for(ll y_=0; y_<=Endy_idx+1; y_++){
                v2[Endx_idx+1][y_]=-1;
            }
            break;
        }
    }
// ******************<いったん記録1>*************************************
//     v1 = vector<vector<ll>> (4*n, vector<ll>(4*n, 0));
//     v2 = vector<vector<ll>> (4*n, vector<ll>(4*n, 0));

//     for(ll i=0; i<n; i++){
//         ll x1=lb(X, a[i]);
//         ll x2=lb(X, c[i]);
//         ll y1=lb(Y, b[i]);
//         ll y2=lb(Y, d[i]);
// // v1 : 頂点の座標
//         v1[x1][y1]++;
//         v1[x2][y2]++;
//         v1[x1][y2]++;
//         v1[x2][y1]++;
// // v2 : 長方形の可視化
//         for(ll x_=x1; x_<=x2; x_++){
//             for(ll y_=y1; y_<=y2; y_++){
//                 v2[x_][y_]++;
//             }
//         }

    // cout << "Conform!!" << endl;
    
    // debug(v2);

// ******************<いったん記録>*************************************


    // for(ll i=0; i<n; i++){
    //     ll x1=lb(X, a[i]);
    //     ll x2=lb(X, c[i]);
    //     ll y1=lb(Y, b[i]);
    //     ll y2=lb(Y, d[i]);

    //     for(ll x_=x2+1; x_<=Endx_idx; x_++){
    //         bool f=false;
    //         for(ll y_=y1; y_<=y2; y_++){
    //             if(v2[x_][y_]>0){
    //                 c[i]=X[x_];
    //                 f=true;
    //             }
    //             v2[x_][y_]++;
    //         }
    //         if(f) break;
    //         if(x_==Endx_idx) c[i]=X_mx;
    //     }
    // }

//Output Answer
    // cout << '\n';
    // cout << "*****************************" << endl;
    // cout << '\n';
    rep(i,n) cout << a[i] << " " << b[i] << " " << c[i] << " " << d[i] << endk;


// <Calc_Score> ***************************************
    // vector<long double> p(n);
    // long double Sum=0;
    // for(ll i=0; i<n; i++){
    //     s[i]=(c[i]-a[i])*(d[i]-b[i]);
    //     p[i]=P_score(r[i], s[i]);
    //     Sum+=p[i];
    // }
    // cout << endl;
    // cout << "Score=" << 1000000000*Sum/n << endk;
    return 0;
}

