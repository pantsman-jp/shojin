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
  string n;
  cin >> n;
  int m = n.size();
  sort(all(n));
  int ans = 0;
  do
  {
    rep(i, 1, m)
    {
      string l = "", r = "";
      rep(j, 0, i) l += n[j];
      rep(j, i, m) r += n[j];
      ans = max(ans, stoi(l) * stoi(r));
    }
  } while (next_permutation(all(n)));
  cout << ans << endl;
}