#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
using ll = long long;
const ll inf = 1LL << 60;

vector<ll> a;
ll n, start = 0;

void solve()
{
  ll t, x, y;
  cin >> t >> x >> y;
  x--, y--;
  if (t == 1)
    swap(a[(start + x) % n], a[(start + y) % n]);
  if (t == 2)
    start = (start + n - 1) % n;
  if (t == 3)
    cout << a[(start + x) % n] << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll q;
  cin >> n >> q;
  a.resize(n);
  rep(i, 0, n) cin >> a[i];
  rep(qi, 0, q) solve();
}
