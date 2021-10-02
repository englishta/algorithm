#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int Max_x, Max_y;
    cin >> Max_x >> Max_y;
    vector<string> A(Max_x), L(Max_y);
    vector<int> W(Max_x);
    vector<vector<int>> d(Max_y, vector<int>(Max_x)); // セルの重み
    vector<vector<int>> v(Max_y, vector<int>(Max_x));
    for(int i=0; i<Max_x; i++) cin >> A[i];
    for(int i=0; i<Max_y; i++) cin >> L[i];
    for(int i=0; i<Max_x; i++) cin >> W[i];

    // 値の初期化
    for(int j=1; j<Max_x; j++){
        v[0][j] = j;
        d[0][j] = d[0][j-1];
        if(W[j]>0 && L[0]!=A[j]) d[0][j] += W[j];
    }

    for(int i=1; i<Max_y; i++){
        v[i][0] = i;
        d[i][0] = d[i-1][0];
        if(W[0]>0 && L[i]!=A[0]) d[i][0]+=W[0];
    }
    // dpによる計算
    for(int i=1; i<Max_y; i++){
        for(int j=1; j<Max_x; j++){
            d[i][j] = min({d[i-1][j], d[i][j-1], d[i-1][j-1]});
            if(W[j]>0 && L[i]!=A[j]) d[i][j]+=W[j];
            v[i][j] = min({v[i-1][j], v[i][j-1], v[i-1][j-1]});
            if(L[i] != A[j]) v[i][j]++;
        }
    }
    // output
    for(ll i=0; i<Max_y; i++){
        for(ll j=0; j<Max_x; j++){
            cout << d[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    for(ll i=0; i<Max_y; i++){
        for(ll j=0; j<Max_x; j++){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}