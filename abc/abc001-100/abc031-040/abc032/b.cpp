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
  string s;
  int k;
  cin >> s >> k;
  int n = (int)s.size();
  if (k > n)
  {
    cout << 0 << endl;
    return 0;
  }
  set<string> pass;
  rep(i, 0, n - k + 1) pass.insert(s.substr(i, k));
  cout << pass.size() << endl;
}