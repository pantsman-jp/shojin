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
  ll k;
  cin >> n >> k;
  vector<pair<ll, ll>> ab(n);
  rep(i, 0, n) cin >> ab[i].first >> ab[i].second;
  sort(all(ab));
  for (auto [a, b] : ab)
  {
    k -= b;
    if (k <= 0)
    {
      cout << a << endl;
      return 0;
    }
  }
}