#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

void solve(vector<int> t)
{
  int p, x;
  cin >> p >> x;
  p--, t[p] = x;
  cout << reduce(all(t)) << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> t(n);
  rep(i, 0, n) cin >> t[i];
  int m;
  cin >> m;
  rep(_, 0, m) solve(t);
}