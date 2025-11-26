#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using ll = long long;
using P = pair<ll, ll>;
const ll inf = 1LL << 60;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  vector<P> ab;
  ll sum = 0;
  rep(_, 0, n)
  {
    ll a, b;
    cin >> a >> b;
    ab.push_back(make_pair(a, b));
    sum += b;
  }
  if (sum <= k)
  {
    cout << 1 << endl;
    return 0;
  }
  sort(all(ab));
  for (auto [a, b] : ab)
  {
    sum -= b;
    if (sum <= k)
    {
      cout << a + 1 << endl;
      return 0;
    }
  }
}