#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

char ith_alph(int i)
{
  return 'a' + i;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;
  cin >> n;
  string ans = "";
  while (n != 0)
    n--, ans = ith_alph(n % 26) + ans, n /= 26;
  cout << ans << endl;
}