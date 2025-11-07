#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

vector<int> y;
vector<bool> banned;

void solve()
{
  int c, x;
  cin >> c >> x;
  x--;
  if (c == 1)
  {
    y[x]++;
    if (y[x] >= 2)
      banned[x] = true;
  }
  if (c == 2)
    banned[x] = true;
  if (c == 3)
  {
    if (banned[x])
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q;
  cin >> n >> q;
  y.resize(n, 0);
  banned.resize(n, false);
  rep(_, 0, q) solve();
}