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
  ll a, b, c, k;
  cin >> a >> b >> c >> k;
  if (k <= a)
    cout << k << endl;
  else if (k - a <= b)
    cout << a << endl;
  else
    cout << a - (k - a - b) << endl;
}