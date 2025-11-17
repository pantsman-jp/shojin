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
  int h = n / 3600, m = (n % 3600) / 60, s = n % 60;
  string hh = to_string(h), mm = to_string(m), ss = to_string(s);
  if (h < 10)
    hh = '0' + hh;
  if (m < 10)
    mm = '0' + mm;
  if (s < 10)
    ss = '0' + ss;
  cout << hh << ':' << mm << ':' << ss << endl;
}