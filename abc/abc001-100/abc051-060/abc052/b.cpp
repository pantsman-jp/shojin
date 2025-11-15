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
  string s;
  cin >> n >> s;
  vector<int> x(n + 1);
  rep(i, 0, n)
  {
    if (s[i] == 'I')
      x[i + 1] = x[i] + 1;
    else
      x[i + 1] = x[i] - 1;
  }
  cout << *max_element(all(x)) << endl;
}