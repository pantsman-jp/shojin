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
  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  if (c * d - b <= 0)
  {
    cout << -1 << endl;
    return 0;
  }
  cout << (a + c * d - b - 1) / (c * d - b) << endl;
}