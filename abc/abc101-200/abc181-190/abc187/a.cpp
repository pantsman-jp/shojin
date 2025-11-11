#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

int s(string n)
{
  int ans = 0;
  rep(i, 0, n.size()) ans += (int)(n[i] - '0');
  return ans;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string a, b;
  cin >> a >> b;
  int sa = s(a), sb = s(b);
  if (sa < sb)
    cout << sb << endl;
  else
    cout << sa << endl;
}