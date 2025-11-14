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
  int a, b, k;
  cin >> a >> b >> k;
  set<int> ans;
  rep(i, 0, k)
  {
    if (a + i <= b)
      ans.insert(a + i);
    if (b - i >= a)
      ans.insert(b - i);
  }
  for (int x : ans)
    cout << x << endl;
}