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
  vector<P> attend;
  rep(i, 0, n)
  {
    int a;
    cin >> a;
    attend.push_back({a, i + 1});
  }
  sort(all(attend));
  for (auto [_, ans] : attend)
    cout << ans << ' ';
  cout << endl;
}