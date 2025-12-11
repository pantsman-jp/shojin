#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

string solve(ll n)
{
  if (n == 0)
    return "";
  if (n % 2 == 0)
  {
    int c = 0;
    while (n % 2 == 0)
      n /= 2, c++;
    return solve(n) + string(c, 'B');
  }
  return solve(n - 1) + "A";
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;
  cin >> n;
  cout << solve(n) << endl;
}