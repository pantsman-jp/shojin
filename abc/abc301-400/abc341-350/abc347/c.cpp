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
  int n, a, b;
  cin >> n >> a >> b;
  vector<int> d(n);
  rep(i, 0, n) cin >> d[i], d[i] %= a + b;
  sort(all(d)), d.push_back(d[0] + a + b);
  rep(i, 0, n)
  {
    if (d[i + 1] - d[i] >= b + 1)
    {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}