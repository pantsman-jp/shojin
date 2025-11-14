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
  vector<int> a(n + 1);
  rep(i, 1, n + 1) cin >> a[i];
  vector<bool> pushed(n, false);
  int now = 1, ans = 0;
  while (true)
  {
    now = a[now], ans++;
    if (now == 2)
    {
      cout << ans << endl;
      return 0;
    }
    if (pushed[now])
    {
      cout << -1 << endl;
      return 0;
    }
    pushed[now] = true;
  }
}