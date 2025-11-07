#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

int h, w;

void solve()
{
  rep(_, 0, w)
  {
    int a;
    cin >> a;
    if (a == 0)
      cout << '.';
    else
      cout << (char)('A' + a - 1);
  }
  cout << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> h >> w;
  rep(_, 0, h) solve();
}