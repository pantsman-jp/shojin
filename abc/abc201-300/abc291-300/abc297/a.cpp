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
  int n, d;
  cin >> n >> d;
  vector<int> t(n);
  rep(i, 0, n) cin >> t[i];
  rep(i, 0, n - 1)
  {
    if (t[i + 1] - t[i] <= d)
    {
      cout << t[i + 1] << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}