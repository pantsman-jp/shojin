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
  int n, k;
  cin >> n >> k;
  vector<bool> tricked(n, true);
  rep(_, 0, k)
  {
    int d;
    cin >> d;
    rep(_, 0, d)
    {
      int a;
      cin >> a;
      a--;
      tricked[a] = false;
    }
  }
  int ans = 0;
  rep(i, 0, n) if (tricked[i]) ans++;
  cout << ans << endl;
}