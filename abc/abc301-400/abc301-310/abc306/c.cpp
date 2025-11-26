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
  map<int, vector<int>> pos;
  rep(i, 0, 3 * n)
  {
    int a;
    cin >> a;
    pos[a].push_back(i);
  }
  vector<P> ans;
  rep(i, 1, n + 1) ans.push_back(make_pair(pos[i][1], i));
  sort(all(ans));
  for (auto [_, i] : ans)
    cout << i << ' ';
  cout << endl;
}