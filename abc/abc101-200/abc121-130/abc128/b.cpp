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
  vector<string> s(n);
  vector<int> p(n);
  rep(i, 0, n) cin >> s[i] >> p[i];
  vector<tuple<string, int, int>> data;
  rep(i, 0, n) data.push_back({s[i], -p[i], i + 1});
  sort(all(data));
  rep(i, 0, n) cout << get<2>(data[i]) << endl;
}