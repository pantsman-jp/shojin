#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using ll = long long;
const ll inf = 1LL << 60;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<string> s(n);
  rep(i, 0, n) cin >> s[i];
  map<string, int> cnt;
  rep(i, 0, n - m + 1)
  {
    rep(j, 0, n - m + 1)
    {
      string t;
      rep(di, 0, m) rep(dj, 0, m) t += s[i + di][j + dj];
      cnt[t]++;
    }
  }
  cout << cnt.size() << endl;
}
