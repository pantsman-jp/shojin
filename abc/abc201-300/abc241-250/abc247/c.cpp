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
  vector<vector<int>> s(n + 1);
  s[1] = {1};
  rep(i, 2, n + 1)
  {
    s[i].insert(s[i].end(), s[i - 1].begin(), s[i - 1].end());
    s[i].push_back(i);
    s[i].insert(s[i].end(), s[i - 1].begin(), s[i - 1].end());
  }
  rep(i, 0, s[n].size()) cout << s[n][i] << ' ';
  cout << endl;
}