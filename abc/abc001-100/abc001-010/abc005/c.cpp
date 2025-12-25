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
  int t, n, m;
  cin >> t >> n;
  vector<int> a(n);
  rep(i, 0, n) cin >> a[i];
  cin >> m;
  vector<int> b(m);
  rep(i, 0, m) cin >> b[i];
  int i = 0;
  rep(j, 0, m)
  {
    while (i < n and a[i] < b[j] - t)
      i++;
    if (i == n or a[i] > b[j])
    {
      cout << "no" << endl;
      return 0;
    }
    i++;
  }
  cout << "yes" << endl;
}