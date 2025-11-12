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
  vector<int> a(n), b(n), c(n - 1);
  rep(i, 0, n) cin >> a[i], a[i]--;
  rep(i, 0, n) cin >> b[i];
  rep(i, 0, n - 1) cin >> c[i];
  int ans = 0, pre = -2;
  rep(i, 0, n)
  {
    int eat = a[i];
    ans += b[eat];
    if (pre + 1 == eat)
      ans += c[eat - 1];
    pre = eat;
  }
  cout << ans << endl;
}