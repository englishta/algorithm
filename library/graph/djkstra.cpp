//djkstrahou
//https://nexusuica.hatenablog.jp/entry/2018/08/14/114524
/*
graph g(n);
n頂点のグラフが作成される

g.add_edge(a, b, cost);
頂点aから頂点bへコストcostの辺が張られる

g.dijkstra(s);
頂点ｓから各頂点への最短経路をダイクストラ法で探索

int dist = g.d[i]
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF  = 1000000000000000;
typedef pair<ll,ll> P;

struct edge{ll to, cost;};

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
            ll v = p.second; //現在参照している頂点の番号
            if(d[v]<p.first) continue;//p.first=参照している頂点がpushされた時点での最短距離or時間
            for(auto e : G[v]){
                if(d[e.to]>d[v]+e.cost){
                    d[e.to] = d[v]+e.cost;
                    que.push(P(d[e.to],e.to));
                }
            }
        }
    }
};

/*
graph g(n);
n頂点のグラフが作成される

g.add_edge(a, b, cost);
頂点aから頂点bへコストcostの辺が張られる

g.dijkstra(s);
頂点ｓから各頂点への最短経路をダイクストラ法で探索

int dist = g.d[i]
*/

int main(void){
    //有向グラフなので双方向は両方とも設定する
    int n = 3;
    graph g(n);
    g.add_edge(0, 1, 5);
    g.add_edge(0, 2, 3);
    g.add_edge(2, 1, 1);
    g.dijkstra(0);
    cout << g.d[1] << endl;

    return 0;
}