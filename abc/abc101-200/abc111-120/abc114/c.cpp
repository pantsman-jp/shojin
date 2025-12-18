#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

bool is753(const string &s)
{
  bool has3 = false, has5 = false, has7 = false;
  for (char c : s)
  {
    if (c == '3')
      has3 = true;
    else if (c == '5')
      has5 = true;
    else if (c == '7')
      has7 = true;
  }
  return has3 and has5 and has7;
}

int solve(ll n, const string &s)
{
  if (!s.empty() and stoll(s) > n)
    return 0;
  return (is753(s) ? 1 : 0) + solve(n, s + "3") + solve(n, s + "5") + solve(n, s + "7");
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  cout << solve(n, "") << endl;
}