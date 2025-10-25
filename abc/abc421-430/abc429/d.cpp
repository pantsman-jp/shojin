#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
using ll = long long;
const ll inf = 1LL << 60;

void print(__int128 n)
{
  if (n == 0)
  {
    cout << 0;
    return;
  }
  if (n < 0)
  {
    cout << '-';
    n = -n;
  }
  string s;
  while (n > 0)
  {
    s += '0' + n % 10;
    n /= 10;
  }
  reverse(s.begin(), s.end());
  cout << s;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n, m;
  int c;
  cin >> n >> m >> c;
  vector<ll> a(n);
  rep(i, 0, n) cin >> a[i];
  sort(a.begin(), a.end());
  vector<ll> u, cnt;
  rep(i, 0, n)
  {
    ll j = i;
    while (j < n and a[j] == a[i])
      j++;
    u.push_back(a[i]), cnt.push_back(j - i);
    i = j - 1;
  }
  int k = u.size();
  vector<ll> sum(2 * k + 1, 0);
  rep(i, 0, 2 * k) sum[i + 1] = sum[i] + cnt[i % k];
  __int128 ans = 0;
  if (k == 1)
    ans = m;
  else
  {
    rep(i, 0, k)
    {
      ll base = sum[i];
      auto j = lower_bound(sum.begin() + i + 1, sum.begin() + i + k + 1, base + c);
      ans += ((__int128)(u[i] - u[(i - 1 + k) % k] + m) % m) * (sum[j - sum.begin()] - base);
    }
  }
  print(ans);
  cout << endl;
}
