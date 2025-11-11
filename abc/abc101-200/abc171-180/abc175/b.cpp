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
  vector<int> l(n);
  rep(i, 0, n) cin >> l[i];
  int ans = 0;
  rep(i, 0, n) rep(j, i + 1, n) rep(k, j + 1, n)
  {
    if (l[i] == l[j] or l[j] == l[k] or l[k] == l[i])
      continue;
    vector<int> side = {l[i], l[j], l[k]};
    sort(all(side));
    if (side[2] < side[0] + side[1])
      ans++;
  }
  cout << ans << endl;
}