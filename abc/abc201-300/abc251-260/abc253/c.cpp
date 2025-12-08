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
  int q;
  cin >> q;
  multiset<int> s;
  rep(_, 0, q)
  {
    int t;
    cin >> t;
    if (t == 1)
    {
      int x;
      cin >> x;
      s.insert(x);
    }
    else if (t == 2)
    {
      int x, c;
      cin >> x >> c;
      while (c-- and s.find(x) != s.end())
        s.erase(s.find(x));
    }
    else
      cout << *s.rbegin() - *s.begin() << endl;
  }
}