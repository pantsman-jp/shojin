#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

string to_base_k(ll n, int k)
{
  if (n == 0)
    return "0";
  string ans = "";
  while (n > 0)
    ans += '0' + (n % k), n /= k;
  reverse(all(ans));
  return ans;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;
  cin >> n;
  string base5 = to_base_k(n - 1, 5), ans = "";
  for (char c : base5)
    ans += '0' + (c - '0') * 2;
  cout << ans << endl;
}