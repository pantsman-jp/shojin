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
  int k;
  cin >> k;
  vector<int> a(k);
  a[1] = 7 % k;
  rep(i, 2, k + 1) a[i] = (a[i - 1] * 10 + 7) % k;
  rep(i, 1, k + 1)
  {
    if (a[i] == 0)
    {
      cout << i << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}