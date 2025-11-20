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
  map<int, vector<int>> ac;
  rep(_, 0, n)
  {
    int a, c;
    cin >> a >> c;
    ac[c].push_back(a);
  }
  vector<int> minis;
  for (auto [_, xs] : ac)
    minis.push_back(*min_element(all(xs)));
  cout << *max_element(all(minis)) << endl;
}