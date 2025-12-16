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
  vector<int> p(n), q(n), ns(n);
  rep(i, 0, n) cin >> p[i];
  rep(i, 0, n) cin >> q[i];
  rep(i, 0, n) ns[i] = i + 1;
  int a, b, i = 1;
  do
  {
    if (p == ns)
      a = i;
    if (q == ns)
      b = i;
    i++;
  } while (next_permutation(all(ns)));
  cout << abs(a - b) << endl;
}