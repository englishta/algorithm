#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main(){
    ll n,k;
    cin >> n >> k;
    vector<vector<ll>>v(n,vector<ll>(k));
    for(ll i=0;i<n;i++){
        for(ll j=0;j<k;j++) cin >> v[i][j];
    }
    vector<vector<ll>>dp(1e4+10,vector<ll>(1e4+10,0));
    for(ll i=0;i<k;i++) dp[0][i]++;
    for(ll i=0;i<n-1;i++){
        for(ll j=0;j<k;j++){
            auto ite=lower_bound(v[i+1].begin(),v[i+1].end(),v[i][j]);
            ll x=ite-v[i+1].begin();
            dp[i+1][x]+=dp[i][j];
            dp[i+1][x]%=MOD;
        }
        for(ll j=1;j<k;j++){
            dp[i+1][j]+=dp[i+1][j-1];
            dp[i+1][j]%=MOD;
        }
    }
    for(ll i=1;i<k;i++){
        dp[n-1][i]+=dp[n-1][i-1];
        dp[n-1][i]%=MOD;
    }
    cout << dp[n-1][k-1] << endl;
}