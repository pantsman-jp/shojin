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
  int h, w;
  cin >> h >> w;
  vector<string> c(h);
  vector<int> x(w);
  rep(i, 0, h) cin >> c[i];
  rep(i, 0, h) rep(j, 0, w) if (c[i][j] == '#') x[j]++;
  rep(j, 0, w) cout << x[j] << ' ';
  cout << endl;
}