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
  int n;
  cin >> n;
  vector<int> a(n), b(n - 1);
  rep(i, 0, n) cin >> a[i];
  rep(i, 0, n - 1) cin >> b[i];
  sort(all(a)), sort(all(b));
  rep(i, 0, n - 1)
  {
    if (a[i] > b[i])
    {
      cout << -1 << endl;
      return 0;
    }
  }
  for (int i = n - 2; i >= 0; i--)
  {
    if (a[i + 1] > b[i])
    {
      cout << a[i + 1] << endl;
      return 0;
    }
  }
  cout << a[0] << endl;
}