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
  vector<int> a(n);
  rep(i, 0, n) cin >> a[i];
  if (reduce(all(a)) % n != 0)
  {
    cout << -1 << endl;
    return 0;
  }
  vector<int> prefix(n + 1);
  prefix[0] = 0;
  rep(i, 0, n) prefix[i + 1] = prefix[i] + a[i];
  int avg = reduce(all(a)) / n, ans = 0;
  rep(i, 1, n) if (prefix[i] != avg * i) ans++;
  cout << ans << endl;
}