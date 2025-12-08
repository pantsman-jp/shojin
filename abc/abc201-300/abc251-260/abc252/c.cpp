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
  vector<string> s(n);
  rep(i, 0, n) cin >> s[i];
  int ans = 1e9;
  rep(x, 0, 10)
  {
    char c = '0' + x;
    vector<int> num(10);
    rep(i, 0, n) rep(j, 0, 10) if (s[i][j] == c) num[j]++;
    int now = 0;
    rep(i, 0, 10) now = max(now, i + 10 * (num[i] - 1));
    ans = min(ans, now);
  }
  cout << ans << endl;
}