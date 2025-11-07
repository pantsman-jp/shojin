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
  vector<ll> a(n);
  rep(i, 0, n) cin >> a[i];
  vector<ll> diff(n - 1);
  rep(i, 0, n - 1) diff[i] = a[i + 1] - a[i];
  ll ans = n;
  int i = 0;
  while (i < n - 1)
  {
    int j = i;
    while (j < n - 1 and diff[j] == diff[i])
      j++;
    ll len = j - i;
    ans += len * (len + 1) / 2, i = j;
  }
  cout << ans << endl;
}