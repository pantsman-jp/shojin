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
  ll ans = 0, len = 1;
  rep(i, 0, n - 1)
  {
    if (a[i] < a[i + 1])
      len++;
    else
      ans += len * (len + 1) / 2, len = 1;
  }
  ans += len * (len + 1) / 2;
  cout << ans << endl;
}