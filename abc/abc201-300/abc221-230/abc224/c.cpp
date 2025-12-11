#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

vector<int> x, y;

bool check(int i, int j, int k)
{
  return (x[i] - x[k]) * (y[j] - y[k]) != (x[j] - x[k]) * (y[i] - y[k]);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  x.resize(n), y.resize(n);
  rep(i, 0, n) cin >> x[i] >> y[i];
  int ans = 0;
  rep(i, 0, n) rep(j, i + 1, n) rep(k, j + 1, n) if (check(i, j, k)) ans++;
  cout << ans << endl;
}