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
  vector<ll> a(n), sum(n + 1);
  rep(i, 0, n) cin >> a[i];
  sum[0] = 0;
  rep(i, 0, n) sum[i + 1] = sum[i] + a[i];
  ll init = 0;
  rep(i, 0, n + 1) if (sum[i] < 0) init = max(init, abs(sum[i]));
  cout << init + sum[n] << endl;
}