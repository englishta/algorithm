#pragma region Macros
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0; i<(n); i++)

bool Count(string s, string t){
    if(s.size()>t.size()) swap(s, t);
    for(ll i=0; i+s.size()-1<t.size(); i++){
        bool ok = true;
        for(ll j=0; j<s.size(); j++){
            if(t[i+j] != s[j]){
                ok = false;
                break;
            }
        }
        if(ok == true) return true;
    }
    return false;
}

int main(){

    string E="yoro", z="rock";
    ll j = 1, k=0;
    while(j<min(ll(E.size()), ll(z.size()))){
        if(E.substr(E.size()-j, j) == z.substr(0, j)) k=j;
        j++;
    }
    string ez=E+z.substr(k, z.size()-k);
    
    return 0;
}