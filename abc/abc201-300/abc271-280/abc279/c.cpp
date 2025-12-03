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
  int h, w;
  cin >> h >> w;
  vector<string> s(h), t(h);
  rep(i, 0, h) cin >> s[i];
  rep(i, 0, h) cin >> t[i];
  vector<string> ts(w), tt(w);
  rep(i, 0, h) rep(j, 0, w) ts[j].push_back(s[i][j]), tt[j].push_back(t[i][j]);
  sort(all(ts)), sort(all(tt));
  if (ts == tt)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}