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
  vector<int> p(n);
  rep(i, 0, n) cin >> p[i];
  if (is_sorted(all(p)))
  {
    cout << "YES" << endl;
    return 0;
  }
  rep(i, 0, n) rep(j, i + 1, n)
  {
    vector<int> q = p;
    swap(q[i], q[j]);
    if (is_sorted(all(q)))
    {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
}