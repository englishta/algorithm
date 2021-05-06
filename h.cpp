#pragma region Macros
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0; i<(n); i++)

int main(){
    string s;
    cin >> s;
    deque<char> dq;
    ll n = s.size();
    ll flag = 1;
    for(ll i=0; i<n; i++){
        if(s[i] == 'R'){
            flag*=-1;
        }else{
            if(flag == 1){
                if(!dq.empty() && s[i] == dq.back()) dq.pop_back();
                else dq.push_back(s[i]);
            }else{
                if(!dq.empty() && s[i] == dq.front()) dq.pop_front();
                else dq.push_front(s[i]);
            }
        }
    }
    string T = "";
    for(char x : dq) T+=x;
    if(flag == -1) reverse(T.begin(), T.end());
    cout << T << endl;

    return 0;
}