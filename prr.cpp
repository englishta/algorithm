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
#define rep1(i, j, n) for(ll i=j; i<(n); i++)
#define vv(type, name, h, ...) vector<vector<type>> name(h, vector<type>(__VA_ARGS__))
#define vvv(type, name, h, w, ...) vector<vector<vector<type>>> name(h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))
#define drop(s) cout << s << endk, exit(0)
#define print(x) cout << (x) << '\n'
#define all(x) (x).begin(), (x).end()
#define UNIQUE(v) v.erase(unique(all(v)), v.end())
#define SP(num, keta) cout << setprecision(keta) << fixed <<num<< '\n'
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

typedef pair<ll,ll> P;

struct edge{ll to, cost;};

struct graph{
    ll V;
    vector<vector<edge> > G;
    vector<ll> d, ret;

    graph(ll n){
        init(n);
    }

    void init(ll n){
        V = n;
        G.resize(V);
        d.resize(V);
        ret.resize(V);
        for(ll i=0; i<V; i++){
            d[i] = INF;
            ret[i]=INF;
        }
    }

    void add_edge(ll s, ll t, ll cost){            
        edge e;
        e.to = t, e.cost = cost;
        G[s].push_back(e);
    }

    void dijkstra(ll s){
        for(ll i=0; i<V; i++){
            d[i] = INF;
        }
        d[s] = 0;
        priority_queue<P,vector<P>, greater<P> > que;
        que.push(P(0,s));

        while(!que.empty()){
            P p = que.top(); que.pop();
            ll v = p.second;
            if(d[v]<p.first) continue;
            for(auto e : G[v]){
                if(d[e.to]>d[v]+e.cost){
                    d[e.to] = d[v]+e.cost;
                    que.push(P(d[e.to],e.to));
                }
            }
        }
    }
};

int main() {

    // int n = 3;
    // graph g(n);
    // g.add_edge(0, 1, 5);
    // g.add_edge(0, 2, 3);
    // g.add_edge(2, 1, 1);
    // g.dijkstra(0);
    // cout << g.d[1] << endl;
    LL(n, m);
    graph g(n+1);

    rep(i,m){
        LL(a, b, c);
        g.add_edge(a, b, c);
    }

    vv(ll, dist, n+1, n+1, 0);
    rep1(i, 1, n+1){
        g.dijkstra(i);
        rep1(J, 1, n+1){
            if(J==i) continue;
            dist[i][J] = g.d[J]; 
        }
    }
    return 0;
}