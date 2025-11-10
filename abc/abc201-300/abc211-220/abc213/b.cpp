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
  vector<pair<int, int>> a;
  rep(i, 0, n)
  {
    int x;
    cin >> x;
    a.push_back(make_pair(x, i + 1));
  }
  sort(all(a), greater<pair<int, int>>());
  cout << a[1].second << endl;
}