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
  ll a, b, k;
  cin >> a >> b >> k;
  ll eat = min(a, k);
  a -= eat, k -= eat;
  b -= min(b, k);
  cout << a << ' ' << b << endl;
}