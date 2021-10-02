#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = std::pair<ll, ll>;
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

// sを固定，tを平行移動させてsの#群と一致させられるか
bool trans(vector<vector<char>> s, vector<vector<char>> t){
    ll sW = s[0].size(), sH = s.size();
    ll tW = t[0].size(), tH = t.size();
    ll cnt_sharp = 0;
    for(ll i=0; i<sH; i++)for(ll j=0; j<sW; j++){
        if(s[i][j] == '#') cnt_sharp++;
    }
    for(ll I=0; I<sH; I++){
        for(ll J=0; J<sW; J++){
            ll cnt = 0;
            bool ok = true; 
            for(ll i=I; i<min(sH, I+tH); i++){
                for(ll j=J; j<min(sW, J+tW); j++){
                    if(s[i][j] == '#'){
                        if(t[i-I][j-J] == '.') ok = false;
                        cnt++;
                    }
                }
            }
            if(cnt == cnt_sharp && ok) return true;
        }
    }
    for(ll I=0; I<tH; I++){
        for(ll J=0; J<tW; J++){
            ll cnt = 0;
            bool ok = true;
            for(ll i=I; i<min(tH, I+sH); i++){
                for(ll j=J; j<min(tW, J+sW); j++){
                    if(t[i][j] == '#'){
                        if(s[i-I][j-J] == '.') ok = false;
                        cnt++;
                    }
                }
            }
            if(cnt == cnt_sharp && ok) return true;
        }
    }
    return false;
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
    if(trans(s, t)){
        cout << "Yes" << "\n";
        return 0;
    }
    vector<vector<char>> t1 = rotate90(t);

    if(trans(s, t1)){
        cout << "Yes" << "\n";
        return 0;
    }
    vector<vector<char>> t2 = rotate90(t1);

    if(trans(s, t2)){
        cout << "Yes" << "\n";
        return 0;
    }
    vector<vector<char>> t3 = rotate90(t2);

    if(trans(s, t3)){
        cout << "Yes" << "\n";
        return 0;
    }
    
    cout << "No" << "\n";

    return 0;
}