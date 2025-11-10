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
  string s1, s2, s3, t, ans = "";
  cin >> s1 >> s2 >> s3 >> t;
  rep(i, 0, t.size())
  {
    if (t[i] == '1')
      ans += s1;
    if (t[i] == '2')
      ans += s2;
    if (t[i] == '3')
      ans += s3;
  }
  cout << ans << endl;
}