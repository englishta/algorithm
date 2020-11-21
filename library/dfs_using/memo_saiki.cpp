#include<bits/stdc++.h>
#define ll long long
#define rep(i,n) for(ll i=0; i<n; i++)
using namespace std;

//メモ化再帰&ナップサック問題
//グローバル変数
ll n, w;
vector<ll> weight, value;
vector<vector<ll>> dp;

ll rec(ll i, ll k){
    ll res;//戻り値

    if(dp[i][k] > 0){
        res = dp[i][k];
    }else if(i == n){
        res = 0;
    }else if(weight[i]>k){
        res = rec(i+1, k);
    }else{
        res = max(rec(i+1, k), rec(i+1, k-weight[i])+value[i]);
    }
    return dp[i][k] = res;
}

int main(void){
    //グローバル変数の初期化
    cin >> n >> w;
    weight = vector<ll>(n); 
    value = vector<ll>(n); 

    dp = vector<vector<ll>>(n+1, vector<ll>(w+1, -1));

    rep(i,n) cin >> weight[i];
    rep(i,n) cin >> value[i];

    cout << rec(0, w) << endl;

    return 0;    
}