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
  ll n;
  cin >> n;
  vector<ll> ans;
  for (ll m = n;; m = (m - 1) & n)
  {
    ans.push_back(m);
    if (m == 0)
      break;
  }
  sort(all(ans));
  for (ll m : ans)
    cout << m << endl;
}