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
  cin >> s;
  bool a = false, b = false, c = false;
  rep(i, 0, 3)
  {
    if (s[i] == 'a')
      a = !a;
    else if (s[i] == 'b')
      b = !b;
    else
      c = !c;
  }
  if (a and b and c)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}