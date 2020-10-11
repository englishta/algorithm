#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main(){
    map<char, int> t;
    char b;
    string e, l;
    cin >> e >> b >> l;
    for(int i=0;i<5;i++) t[e[i]]++;

    int cnt=0;
    bool bonas=false;


    for(int i=0;i<5;i++){
        if(t[l[i]] > 0) cnt++;
        if(l[i] == b) bonas = true;
    }

    


    return 0;
}