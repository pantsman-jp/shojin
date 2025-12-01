#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
using ld = long double;
const ll inf = 1LL << 60;

void mean(vector<ld> xs)
{
  cout << fixed << setprecision(10) << reduce(all(xs)) / xs.size() << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<vector<ld>> bird(m);
  rep(_, 0, n)
  {
    int a;
    ld b;
    cin >> a >> b;
    bird[a - 1].push_back(b);
  }
  rep(i, 0, m) mean(bird[i]);
}