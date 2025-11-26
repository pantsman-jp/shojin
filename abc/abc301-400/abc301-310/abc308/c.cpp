#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
using ld = long double;
const ll inf = 1LL << 60;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<pair<ld, int>> ans;
  rep(i, 0, n)
  {
    ld a, b;
    cin >> a >> b;
    ans.push_back(make_pair(a / (a + b), i + 1));
  }
  sort(all(ans), [](const pair<ld, int> &p1, const pair<ld, int> &p2)
       {
      if (p1.first != p2.first) {
          return p1.first > p2.first;
      }
      return p1.second < p2.second; });
  for (auto [_, x] : ans)
    cout << x << ' ';
  cout << endl;
}