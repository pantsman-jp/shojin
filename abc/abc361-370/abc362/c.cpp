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
  vector<ll> l(n), r(n);
  rep(i, 0, n) cin >> l[i] >> r[i];
  ll suml = reduce(all(l)), sumr = reduce(all(r));
  if (suml > 0 or sumr < 0)
  {
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
  vector<ll> x = l;
  ll rem = -suml;
  rep(i, 0, n)
  {
    ll canadd = r[i] - l[i];
    ll add = min(rem, canadd);
    x[i] += add;
    rem -= add;
    if (rem == 0)
      break;
  }
  rep(i, 0, n) cout << x[i] << ' ';
  cout << endl;
}