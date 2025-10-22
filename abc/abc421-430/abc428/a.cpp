#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
using namespace std;
using ll = long long;
const ll inf = 1LL << 60;

int main()
{
  int s, a, b, x;
  cin >> s >> a >> b >> x;
  cout << x / (a + b) * a * s + min(x % (a + b), a) * s << endl;
}
