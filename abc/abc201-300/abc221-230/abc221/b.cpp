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
  string s, t;
  cin >> s >> t;
  if (s == t)
  {
    cout << "Yes" << endl;
    return 0;
  }
  rep(i, 0, s.size() - 1)
  {
    string u = s;
    swap(u[i], u[i + 1]);
    if (u == t)
    {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}