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
  ll n, x = 1000, ans = 0;
  cin >> n;
  while (n >= x)
    ans += n - x + 1, x *= 1000;
  cout << ans << endl;
}