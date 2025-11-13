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
  int n, t;
  cin >> n >> t;
  vector<P> ct;
  rep(_, 0, n)
  {
    int ci, ti;
    cin >> ci >> ti;
    if (ti <= t)
      ct.push_back(make_pair(ci, ti));
  }
  sort(all(ct));
  if (ct.empty())
    cout << "TLE" << endl;
  else
    cout << ct[0].first << endl;
}