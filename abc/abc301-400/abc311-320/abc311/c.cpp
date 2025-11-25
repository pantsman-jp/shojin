#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

int n;
vector<int> a, ans;

void get_cycle()
{
  int v = 0;
  rep(i, 0, n) v = a[v];
  int s = v;
  do
  {
    ans.push_back(v), v = a[v];
  } while (v != s);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  a.resize(n);
  rep(i, 0, n) cin >> a[i], a[i]--;
  get_cycle();
  cout << ans.size() << endl;
  for (int x : ans)
    cout << x + 1 << ' ';
  cout << endl;
}