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
  int n, q;
  cin >> n >> q;
  set<int> called;
  int last = 0;
  rep(_, 0, q)
  {
    int t, x;
    cin >> t;
    if (t == 1)
    {
      last++;
      called.insert(last);
    }
    else if (t == 2)
    {
      cin >> x;
      called.erase(x);
    }
    else
      cout << *begin(called) << endl;
  }
}