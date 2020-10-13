#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0; i<n; i++)

int main() {
	ll n;
	cin >> n;
	ll min = 1e9;
	priority_queue<int> que;

	rep(i,n){
		ll a;
		cin >> a;
		if(min>a) min = a;
		que.push(a);
	}
	while(!que.empty()){
		ll x = que.top();
		que.pop();
		if(x == min) break;
		ll y = x%min;
		if(y){
			if(min>y) min = y;
			que.push(y);
		}
	}
	cout << min << '\n';
	return 0;
}