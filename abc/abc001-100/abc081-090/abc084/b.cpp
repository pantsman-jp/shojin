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
  int a, b;
  string s;
  cin >> a >> b >> s;
  bool ok = s[a] == '-';
  rep(i, 0, a + b + 1)
  {
    if (i == a)
      continue;
    if ('0' > s[i] or s[i] > '9')
      ok = false;
  }
  if (ok)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}