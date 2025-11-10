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
  int p;
  cin >> p;
  vector<int> fact(11, 1);
  rep(i, 0, 10) fact[i + 1] = fact[i] * (i + 1);
  int ans = 0;
  for (int i = 10; i > 0; i--)
  {
    int use = min(100, p / fact[i]);
    ans += use, p -= use * fact[i];
  }
  cout << ans << endl;
}