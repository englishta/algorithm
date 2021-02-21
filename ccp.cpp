#pragma region Macros
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0; i<(n); i++)
#define rep1(i, j, n) for(ll i=j; i<(n); i++)
#define all(x) (x).begin(), (x).end()
#define lb(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define ub(c, x) distance((c).begin(), upper_bound(all(c), (x)))
#define drop(s) cout << s << '\n', exit(0)
#pragma endregion

constexpr ll INF  = 100000*3000000000;
typedef pair<ll,ll> P;

struct edge{ll to, cost, bai;};

struct graph{
    ll V;
    vector<vector<edge> > G;
    vector<ll> d;

    graph(ll n){
        init(n);
    }

    void init(ll n){
        V = n;
        G.resize(V);
        d.resize(V);
        for(ll i=0; i<V; i++){
            d[i] = INF;
        }
    }

    void add_edge(ll s, ll t, ll cost, ll B){            
        edge e;
        e.to = t, e.cost = cost, e.bai=B;
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
            ll v = p.second;  //現在参照してる頂点
            if(d[v]<p.first) continue;
            for(auto e : G[v]){
                ll plus=e.bai-p.first%e.bai;
                if(p.first==0 || p.first%e.bai==0) plus=0;
                if(d[e.to]>d[v]+e.cost+plus){
                    d[e.to] = d[v]+e.cost+plus;
                    que.push(P(d[e.to],e.to));
                }
            }
        }
    }
};

int main(){
    ll n, m, x, y;
    cin >> n >> m >> x >> y;
    x--; y--;
    graph g(n);

    rep(i,m){
        ll a, b, t, k;
        cin >> a >> b >> t >> k;
        a--;
        b--;
        g.add_edge(a, b, t, k);
        g.add_edge(b, a, t, k);
    }
    g.dijkstra(x);
    ll ans = g.d[y];
    if(ans == INF) drop(-1);
    else drop(ans);

    return 0;
}