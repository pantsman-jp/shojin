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
  vector<int> p(n), q(n);
  rep(i, 0, n) cin >> p[i];
  rep(i, 0, n) q[p[i] - 1] = i + 1;
  rep(i, 0, n) cout << q[i] << ' ';
  cout << endl;
}