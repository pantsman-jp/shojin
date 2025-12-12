#include <bits/stdc++.h>
using namespace std;
#define rep(i, ab, b) for (int i = (ab); i < (b); i++)
#define all(p) p.begin(), p.end()
using ll = long long;
using P = pair<ll, ll>;
const ll inf = 1LL << 60;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  ll k;
  cin >> n >> k;
  vector<P> ab;
  rep(i, 0, n)
  {
    ll a, b;
    cin >> a >> b;
    ab.push_back({a, b});
  }
  sort(all(ab));
  rep(i, 0, n)
  {
    auto [a, b] = ab[i];
    if (a > k)
      break;
    k += b;
  }
  cout << k << endl;
}