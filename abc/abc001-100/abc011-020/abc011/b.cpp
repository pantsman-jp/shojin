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
  if (isupper(s[0]))
    cout << (char)s[0];
  else
    cout << (char)toupper(s[0]);
  rep(i, 1, s.size())
  {
    if (islower(s[i]))
      cout << (char)s[i];
    else
      cout << (char)tolower(s[i]);
  }
  cout << endl;
}