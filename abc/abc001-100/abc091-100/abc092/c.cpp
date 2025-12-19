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
  vector<ll> total_diffs(n + 1);
  ll sum = abs(a[0] - 0);
  rep(i, 1, n) sum += abs(a[i] - a[i - 1]);
  sum += abs(a[n - 1] - 0);
  rep(i, 0, n)
  {
    ll diff;
    if (i == 0)
      diff = abs(0 - a[0]) + abs(a[0] - a[1]) - abs(0 - a[1]);
    else if (i == n - 1)
      diff = abs(a[n - 2] - a[n - 1]) + abs(a[n - 1] - 0) - abs(a[n - 2] - 0);
    else
      diff = abs(a[i - 1] - a[i]) + abs(a[i] - a[i + 1]) - abs(a[i - 1] - a[i + 1]);
    cout << sum - diff << endl;
  }
}