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
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i, 0, h) cin >> s[i];
  int ans = 0;
  rep(i, 0, h - 1) rep(j, 0, w - 1)
  {
    int cnt = 0;
    rep(di, 0, 2) rep(dj, 0, 2) if (s[i + di][j + dj] == '#') cnt++;
    if (cnt == 1 or cnt == 3)
      ans++;
  }
  cout << ans << endl;
}