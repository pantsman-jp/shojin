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
  int n;
  cin >> n;
  set<int> items;
  rep(_, 0, n)
  {
    int a;
    cin >> a;
    if (items.count(a) == 0)
      items.insert(a);
    else
    {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
}