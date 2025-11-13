#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

bool is_all_same(int n)
{
  string s = to_string(n);
  rep(i, 0, s.size() - 1) if (s[i] != s[i + 1]) return false;
  return true;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  while (true)
  {
    if (is_all_same(n))
    {
      cout << n << endl;
      return 0;
    }
    n++;
  }
}