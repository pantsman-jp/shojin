#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;
using mint = modint998244353;

mint sum(ll x)
{
  return mint(1 + x) * x / 2;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;
  cin >> n;
  ll l = 1, digit = 1;
  mint ans;
  while (l <= n)
    ans += sum(min(n + 1, l * 10) - l), l *= 10, digit++;
  cout << ans.val() << endl;
}