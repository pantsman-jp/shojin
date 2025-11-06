#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

map<int, int> bag;
int cnt = 0;

void solve()
{
  int n, x;
  cin >> n;
  if (n == 1)
  {
    cin >> x;
    if (bag[x] == 0)
      cnt++;
    bag[x]++;
  }
  if (n == 2)
  {
    cin >> x;
    bag[x]--;
    if (bag[x] == 0)
      cnt--;
  }
  if (n == 3)
    cout << cnt << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int q;
  cin >> q;
  rep(_, 0, q) solve();
}