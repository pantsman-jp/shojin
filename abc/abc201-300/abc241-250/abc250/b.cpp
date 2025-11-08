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
  int n, a, b;
  cin >> n >> a >> b;
  vector<string> ans(a * n, string(b * n, '-'));
  rep(i, 0, a * n) rep(j, 0, b * n)
  {
    if (((i / a) + (j / b)) % 2 == 0)
      ans[i][j] = '.';
    else
      ans[i][j] = '#';
  }
  rep(i, 0, a * n) cout << ans[i] << endl;
}