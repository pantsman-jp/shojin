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
  string o, e;
  cin >> o >> e;
  int n = o.size(), m = e.size();
  rep(i, 0, m) cout << o[i] << e[i];
  if (n == m)
    cout << endl;
  else
    cout << o.back() << endl;
}