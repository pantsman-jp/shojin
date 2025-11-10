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
  rep(i, 0, n) rep(j, i + 1, n)
  {
    if (s[i] == s[j] and t[i] == t[j])
    {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}