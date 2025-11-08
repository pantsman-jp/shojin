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
  vector<string> s(n), t(n);
  rep(i, 0, n) cin >> s[i] >> t[i];
  rep(i, 0, n)
  {
    bool oks = true, okt = true;
    rep(j, 0, n) if (i != j)
    {
      if (s[i] == s[j] or s[i] == t[j])
        oks = false;
      if (t[i] == s[j] or t[i] == t[j])
        okt = false;
    }
    if (!oks and !okt)
    {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}