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
  int x, n;
  cin >> x >> n;
  set<int> p;
  rep(i, 0, n)
  {
    int pi;
    cin >> pi;
    p.insert(pi);
  }
  int ans = 0, diff = 1e9;
  rep(i, -200, 201)
  {
    if (p.count(i) != 0)
      continue;
    int d = abs(i - x);
    if (d < diff or (d == diff and i < ans))
      diff = d, ans = i;
  }
  cout << ans << endl;
}