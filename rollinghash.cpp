// #pragma region Macros
// #include<bits/stdc++.h>
// using namespace std;
// using ll = long long;
// using ull = unsigned long long
// #define rep(i,n) for(ll i=0; i<(n); i++)

 
// namespace RollingHashes {
// static ull base;
// vector<ull> p{1};
// struct RollingHash {
//     static constexpr ull MOD = (1LL << 61) - 1;
//     vector<ull> h;
//     ull mul(ull a, ull b) const {
//         i128 t = (i128)(a) * (i128)(b);
//         t = (t >> 61) + (t & MOD);
//         if(t >= MOD) return t - MOD;
//         return t;
//     }
//     RollingHash(const string &s) {
//         int sz = (int)s.size();
//         if(!base) base = 54754357;
//         h.assign(sz + 1, 0);
//         p[0] = 1;
//         if(sz + 1 > p.size()) {
//             int psz = p.size();
//             p.resize(sz + 1);
//             for(int i = psz; i < sz + 1; i++) p[i] = mul(p[i - 1], base);
//         }
//         for(int i = 0; i < sz; i++) {
//             h[i + 1] = mul(h[i], base) + s[i];
//             if(h[i + 1] >= MOD) h[i + 1] -= MOD;
//         }
//     }
 
//     ull get(int l, int r) const {
//         ull res = h[r] + MOD - mul(h[l], p[r - l]);
//         if(res >= MOD) return res - MOD;
//         return res;
//     }
 
//     ull connect(ull h1, ull h2, int h2len) const {
//         ull res = mul(h1, p[h2len]) + h2;
//         if(res >= MOD) return res - MOD;
//         return res;
//     }
 
//     int LCP(const RollingHash &b, int l1, int r1, int l2, int r2) {
//         int len = min(r1 - l1, r2 - l2);
//         int low = -1, high = len + 1;
//         while(high - low > 1) {
//             int mid = (low + high) / 2;
//             if(get(l1, l1 + mid) == b.get(l2, l2 + mid))
//                 low = mid;
//             else
//                 high = mid;
//         }
//         return (low);
//     }
//     RollingHash() = default;
// };
// }
// using namespace RollingHashes;