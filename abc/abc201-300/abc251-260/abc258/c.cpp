#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

int n, q, i = 0;
string s;

void solve()
{
  int t, x;
  cin >> t >> x;
  if (t == 1)
    i = (i - x + n) % n;
  else
    cout << s[(i + x - 1) % n] << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> q >> s;
  rep(_, 0, q) solve();
}