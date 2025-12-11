#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string x;
  int n;
  cin >> x >> n;
  vector<string> s(n);
  rep(i, 0, n) cin >> s[i];
  map<char, char> f, g;
  rep(i, 0, 26) f[x[i]] = 'a' + i, g['a' + i] = x[i];
  rep(i, 0, n) for (char &c : s[i]) c = f[c];
  sort(all(s));
  rep(i, 0, n) for (char &c : s[i]) c = g[c];
  rep(i, 0, n) cout << s[i] << endl;
}