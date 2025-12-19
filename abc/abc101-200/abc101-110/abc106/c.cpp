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
  string s;
  ll k;
  cin >> s >> k;
  ll cnt = 0;
  for (char c : s)
  {
    if (c == '1')
      cnt++;
    else
      break;
  }
  if (cnt >= k)
    cout << 1 << endl;
  else
    cout << s[cnt] << endl;
}