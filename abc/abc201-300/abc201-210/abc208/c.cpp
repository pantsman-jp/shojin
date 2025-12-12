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
  ll n, k;
  cin >> n >> k;
  vector<int> a(n);
  rep(i, 0, n) cin >> a[i];
  ll cnt1 = k / n;
  k %= n;
  vector<int> b = a;
  sort(all(b));
  rep(i, 0, n)
  {
    if (a[i] < b[k])
      cout << cnt1 + 1 << endl;
    else
      cout << cnt1 << endl;
  }
}