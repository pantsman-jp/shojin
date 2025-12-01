#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

map<int, vector<int>> box;
map<int, set<int>> card;

void solve()
{
  int t, i, j;
  cin >> t;
  if (t == 1)
  {
    cin >> i >> j;
    box[j].push_back(i), card[i].insert(j);
  }
  else if (t == 2)
  {
    cin >> i;
    sort(all(box[i]));
    for (int ans : box[i])
      cout << ans << ' ';
    cout << endl;
  }
  else
  {
    cin >> i;
    for (int ans : card[i])
      cout << ans << ' ';
    cout << endl;
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q;
  cin >> n >> q;
  rep(_, 0, q) solve();
}