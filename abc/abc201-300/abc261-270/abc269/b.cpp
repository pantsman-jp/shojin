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
  vector<string> s(10);
  rep(i, 0, 10) cin >> s[i];
  vector<int> row, line;
  rep(i, 0, 10) rep(j, 0, 10) if (s[i][j] == '#') row.push_back(i), line.push_back(j);
  cout << *min_element(all(row)) + 1 << ' ' << *max_element(all(row)) + 1 << endl;
  cout << *min_element(all(line)) + 1 << ' ' << *max_element(all(line)) + 1 << endl;
}