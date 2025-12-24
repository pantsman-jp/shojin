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
  int n, m, x, y;
  cin >> n >> m >> x >> y;
  vector<int> a(n), b(m);
  rep(i, 0, n) cin >> a[i];
  rep(i, 0, m) cin >> b[i];
  int now = 0, i = 0, j = 0, cnt = 0;
  while (true)
  {
    while (i < n and a[i] < now)
      i++;
    if (i == n)
      break;
    now = a[i] + x;
    while (j < m and b[j] < now)
      j++;
    if (j == m)
      break;
    now = b[j] + y;
    cnt++;
  }
  cout << cnt << endl;
}