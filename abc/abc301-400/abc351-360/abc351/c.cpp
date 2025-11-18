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
  vector<ll> ans;
  rep(_, 0, n)
  {
    ll a;
    cin >> a;
    ans.push_back(a);
    while (ans.size() >= 2)
    {
      ll x = ans.back();
      ans.pop_back();
      ll y = ans.back();
      if (x == y)
        ans.pop_back(), ans.push_back(x + 1);
      else
      {
        ans.push_back(x);
        break;
      }
    }
  }
  cout << ans.size() << endl;
}