#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

bool is_pali(string s)
{
  if (s.empty())
    return true;
  if (s.size() == 1)
    return true;
  if (s.front() != s.back())
    return false;
  return is_pali(s.substr(1, s.size() - 2));
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string n;
  cin >> n;
  rep(_, 0, 10)
  {
    if (is_pali(n))
    {
      cout << "Yes" << endl;
      return 0;
    }
    n = '0' + n;
  }
  cout << "No" << endl;
}