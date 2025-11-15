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
  vector<string> s(n), ans(n, string(n, ' '));
  rep(i, 0, n) cin >> s[i];
  rep(i, 0, n) rep(j, 0, n) ans[j][n - i - 1] = s[i][j];
  rep(i, 0, n) cout << ans[i] << endl;
}