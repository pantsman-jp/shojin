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
  int n, k;
  cin >> n >> k;
  set<int> s;
  rep(i, 0, n)
  {
    int a;
    cin >> a;
    s.insert(a);
  }
  rep(i, 0, k)
  {
    if (s.find(i) == s.end())
    {
      cout << i << endl;
      return 0;
    }
  }
  cout << k << endl;
}