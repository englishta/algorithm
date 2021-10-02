#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using PLL = std::pair<ll, ll>;
#define rep(i,n) for(ll i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
#define lb(c, x) distance((c).begin(), lower_bound(all(c), (x)))


vector<vector<char>> rotate90(vector<vector<char>> s){
    ll h = s.size(), w = s[0].size();
    vector<vector<char>> r(w, vector<char>(h)); 
    for(ll i=0; i<w; i++){
        for(ll j=0; j<h; j++){
            r[i][j] = s[h-1-j][i];
        }
    }
    return r;
}

int main() {
    ll n; cin >> n;
    vector<vector<char>> s(n, vector<char>(n));
    vector<vector<char>> t(n, vector<char>(n));
    for(ll i=0; i<n; i++){
        for(ll j=0; j<n; j++){
            cin >> s[i][j];
        }
    }
    for(ll i=0; i<n; i++){
        for(ll j=0; j<n; j++){
            cin >> t[i][j];
        }
    }
    auto nv = rotate90(t);

    for(ll i=0; i<n; i++){
        for(ll j=0; j<n; j++){
            cout << nv[i][j];
        }
        cout << endl;
    }


    return 0;
}