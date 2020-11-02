#include<bits/stdc++.h>
using namespace std;
using ll = long long;

//n??????????????????????prime.size()????
//???O(nloglogn)=n?????
//???10???2, 3, 5, 7??????????

vector<ll> sieve(ll n){
	vector<ll> prime;  //‘f”‚ğŠi”[‚·‚é”z—ñ
	bool is_prime[n+1];  //is_prime[i]‚ªtrue‚È‚çi‚Í‘f”

	for(ll i=0; i<=n; i++) is_prime[i] = true;
	is_prime[0] = is_prime[1] = false;

	for(ll i=2; i<=n; i++){
		if(is_prime[i]){
			prime.push_back(i);
			for(ll j=2*i; j<=n; j+=i) is_prime[j] = false;
		}
	}
	return prime;
}


int main() {
	ll n;
	cin >> n;
	vector<ll> array = sieve(n);
	cout << array.size() << endl;
	for(auto x : array) cout << x << endl;
	return 0;
}
