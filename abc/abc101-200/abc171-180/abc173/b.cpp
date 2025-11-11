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
  int ac = 0, wa = 0, tle = 0, re = 0;
  rep(_, 0, n)
  {
    string s;
    cin >> s;
    if (s == "AC")
      ac++;
    if (s == "WA")
      wa++;
    if (s == "TLE")
      tle++;
    if (s == "RE")
      re++;
  }
  cout << "AC" << " x " << ac << endl;
  cout << "WA" << " x " << wa << endl;
  cout << "TLE" << " x " << tle << endl;
  cout << "RE" << " x " << re << endl;
}