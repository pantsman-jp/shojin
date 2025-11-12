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
  int n, k, m;
  cin >> n >> k >> m;
  int sum = 0;
  rep(_, 0, n - 1)
  {
    int a;
    cin >> a;
    sum += a;
  }
  int ans = max(n * m - sum, 0);
  if (ans <= k)
    cout << ans << endl;
  else
    cout << -1 << endl;
}