#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using PLL = std::pair<ll, ll>;
#define rep(i,n) for(ll i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
#define lb(c, x) distance((c).begin(), lower_bound(all(c), (x)))

ll h, w;
vector<string> v;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool inside(ll I, ll J){
    if(I>=0 && I<h && J>=0 && J<w) return true;
    else return false;
}

ll solve(ll start_i, ll start_j){
    queue<tuple<ll, ll, ll>> Q;
    vector<vector<bool>> visit(h, vector<bool>(w, false));
    Q.push({start_i, start_j, 0ll});
    visit[start_i][start_j] = true;
    ll Max_dist = -1;
    while(!Q.empty()){
        auto [now_I, now_J, dist] = Q.front();
        if(dist>Max_dist) Max_dist = dist;
        Q.pop();
        for(ll i=0; i<4; i++){
            ll NI = now_I+dy[i];
            ll NJ = now_J+dx[i];
            if(!inside(NI, NJ)) continue;
            if(visit[NI][NJ] || v[NI][NJ] == '#') continue;
            visit[NI][NJ] = true;
            Q.push({NI, NJ, dist+1});
        }
    }
    return Max_dist;
}

int main() {
    cin >> h >> w;
    v.resize(h);
    ll ans = -1;
    rep(i,h) cin >> v[i];
    for(ll i=0; i<h; i++){
        for(ll j=0; j<w; j++){
            if(v[i][j] == '#') continue;
            ll d = solve(i, j);
            if(d>ans) ans = d;
        }
    }
    cout << ans << "\n";

    return 0;
}