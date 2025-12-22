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
  int n;
  cin >> n;
  map<char, ll> cnt;
  rep(_, 0, n)
  {
    string s;
    cin >> s;
    char c = s[0];
    if (c == 'M' or c == 'A' or c == 'R' or c == 'C' or c == 'H')
      cnt[c]++;
  }
  vector<ll> v;
  for (auto [_, c] : cnt)
    v.push_back(c);
  ll ans = 0;
  int m = v.size();
  rep(i, 0, m) rep(j, i + 1, m) rep(k, j + 1, m) ans += v[i] * v[j] * v[k];
  cout << ans << endl;
}