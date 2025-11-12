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
  if (n % 2 != 0)
    cout << "No" << endl;
  else if (s.substr(0, n / 2) == s.substr(n / 2))
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}