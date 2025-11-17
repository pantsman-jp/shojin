#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (ll i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;
const ll mod = 10007;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;
  cin >> n;
  vector<ll> a(n + 1);
  a[1] = 0, a[2] = 0, a[3] = 1;
  rep(i, 4, n + 1) a[i] = (a[i - 1] + a[i - 2] + a[i - 3]) % mod;
  cout << a[n] << endl;
}