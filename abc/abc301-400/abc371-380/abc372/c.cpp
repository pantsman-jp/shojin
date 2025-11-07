#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

string s;
int n, q, ans = 0;

bool isABC(int i)
{
  if (i < 0 or i + 3 > n)
    return false;
  return s[i] == 'A' and s[i + 1] == 'B' and s[i + 2] == 'C';
}

void solve()
{
  int x;
  char c;
  cin >> x >> c;
  x--;
  rep(off, 0, 3) if (isABC(x - off)) ans--;
  s[x] = c;
  rep(off, 0, 3) if (isABC(x - off)) ans++;
  cout << ans << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> q >> s;
  rep(i, 0, n - 2) if (isABC(i)) ans++;
  rep(_, 0, q) solve();
}