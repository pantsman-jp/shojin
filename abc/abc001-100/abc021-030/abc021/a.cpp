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
  int n, pow2 = 8;
  cin >> n;
  vector<int> ans;
  while (n != 0)
  {
    if (n < pow2)
      pow2 /= 2;
    else
      n -= pow2, ans.push_back(pow2);
  }
  cout << ans.size() << endl;
  for (int a : ans)
    cout << a << endl;
}