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
  int n, m;
  cin >> n >> m;
  vector<vector<int>> attend(m);
  rep(i, 0, m)
  {
    int k;
    cin >> k;
    attend[i].resize(k);
    rep(j, 0, k)
    {
      cin >> attend[i][j];
      attend[i][j]--;
    }
  }
  rep(i, 0, n) rep(j, i + 1, n)
  {
    bool ok = false;
    rep(k, 0, m) if (count(all(attend[k]), i) != 0 and count(all(attend[k]), j) != 0) ok = true;
    if (!ok)
    {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}