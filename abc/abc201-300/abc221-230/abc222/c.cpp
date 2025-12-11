#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

bool win(char a, char b)
{
  return (a == 'G' and b == 'C') or (a == 'C' and b == 'P') or (a == 'P' and b == 'G');
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<string> a(2 * n);
  rep(i, 0, 2 * n) cin >> a[i];
  vector<P> wins(2 * n);
  rep(i, 0, 2 * n) wins[i] = P(0, i);
  rep(mi, 0, m)
  {
    rep(ni, 0, n)
    {
      int i = ni * 2, j = ni * 2 + 1;
      int ai = wins[i].second, aj = wins[j].second;
      if (win(a[ai][mi], a[aj][mi]))
        wins[i].first--;
      if (win(a[aj][mi], a[ai][mi]))
        wins[j].first--;
    }
    sort(all(wins));
  }
  rep(i, 0, 2 * n) cout << wins[i].second + 1 << endl;
}