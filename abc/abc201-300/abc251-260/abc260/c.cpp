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
  ll x, y;
  cin >> n >> x >> y;
  vector<ll> r(n + 1), b(n + 1);
  b[1] = 1, r[1] = 0;
  rep(i, 2, n + 1)
  {
    b[i] = r[i - 1] + y * b[i - 1];
    r[i] = r[i - 1] + x * b[i];
  }
  cout << r[n] << endl;
}