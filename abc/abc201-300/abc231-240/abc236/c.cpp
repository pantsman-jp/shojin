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
  int n, m;
  cin >> n >> m;
  vector<string> s(n), t(m);
  set<string> st;
  rep(i, 0, n) cin >> s[i];
  rep(i, 0, m) cin >> t[i], st.insert(t[i]);
  sort(all(t));
  rep(i, 0, n)
  {
    if (st.count(s[i]) != 0)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
}