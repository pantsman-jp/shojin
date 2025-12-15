#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

string to_base_k(int m, int k)
{
  if (m == 0)
    return "0";
  string ans = "";
  while (m > 0)
    ans += '0' + (m % k), m /= k;
  reverse(all(ans));
  return ans;
}

bool check(string m)
{
  for (char c : m)
  {
    if (c == '7')
      return false;
  }
  return true;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  int ans = 0;
  rep(m, 1, n + 1)
  {
    if (check(to_string(m)) and check(to_base_k(m, 8)))
      ans++;
  }
  cout << ans << endl;
}