// https://dai1741.github.io/maximum-algo-2012/docs/parsing/
// 再帰降下型構文解析

// AOJの問題
// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0109&lang=jp

#include<bits/stdc++.h>
using namespace std;

int expr(string& s, int& i);
int term(string& s, int& i);
int factor(string& s, int& i);
int number(string& s, int& i);

int expr(string& s, int& i) {
  int val = term(s, i);
  while(s[i] == '+' || s[i] == '-') {
    char op = s[i];
    i++;
    int val2 = term(s, i);
    if (op == '+') val += val2;
    else val -= val2;
  }
  return val;
}



int term(string& s, int& i) {
  int val = factor(s, i);
  while(s[i] == '*' || s[i] == '/') {
    char op = s[i];
    i++;
    int val2 = factor(s, i);
    if (op == '*') val *= val2;
    else val /= val2;
  }
  return val;
}

int factor(string& s, int& i) {
  if (isdigit(s[i])) return number(s, i);

  // ここで構文が正しければ s[i] == '(' となる
  i++; // '('を読み飛ばす
  int ret = expr(s, i);
  i++; // ')'を読み飛ばす
  return ret;
}

int number(string& s, int& i) {
  int n = s[i++] - '0';
  while(isdigit(s[i])) n = n*10 + s[i++] - '0';
  return n;
}

// AOJの問題を解くための関数宣言
void solve(){
  int n; cin >> n;
  for(int j=0; j<n; j++){
    string s; cin >> s;
    int i = 0;
    cout << expr(s, i) << endl;
  }
}

int main() {
  // solve();
  string str = "1+2*6/(10-7)";
  int i = 0;
  cout << str << " = " << expr(str, i) << endl; // => 5
  return 0;
}
