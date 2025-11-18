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
  vector<int> a(n), pos(n + 1);
  rep(i, 0, n) cin >> a[i];
  rep(i, 0, n) pos[a[i]] = i;
  vector<P> ans;
  rep(i, 0, n)
  {
    if (a[i] == i + 1)
      continue;
    int j = pos[i + 1];
    ans.push_back(make_pair(i + 1, j + 1));
    swap(a[i], a[j]), pos[a[j]] = j, pos[a[i]] = i;
  }
  cout << ans.size() << endl;
  for (auto p : ans)
    cout << p.first << ' ' << p.second << endl;
}