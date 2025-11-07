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
  int n, m;
  cin >> n >> m;
  vector<string> ss(n), t(m);
  rep(i, 0, n)
  {
    string s;
    cin >> s;
    ss.push_back(s.substr(3));
  }
  rep(i, 0, m) cin >> t[i];
  int ans = 0;
  for (string s : ss)
    if (find(all(t), s) != t.end())
      ans++;
  cout << ans << endl;
}