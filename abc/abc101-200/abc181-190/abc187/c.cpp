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
  vector<string> s(n);
  rep(i, 0, n) cin >> s[i];
  set<string> s2(all(s));
  rep(i, 0, n)
  {
    if (s2.count('!' + s[i]) != 0)
    {
      cout << s[i] << endl;
      return 0;
    }
  }
  cout << "satisfiable" << endl;
}