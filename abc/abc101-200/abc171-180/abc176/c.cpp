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
  ll pivot = a[0], ans = 0;
  rep(i, 1, n)
  {
    if (a[i] < pivot)
      ans += pivot - a[i];
    pivot = max(pivot, a[i]);
  }
  cout << ans << endl;
}