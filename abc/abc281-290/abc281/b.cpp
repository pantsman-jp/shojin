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
  cin >> s;
  if (s.size() != 8)
  {
    cout << "No" << endl;
    return 0;
  }
  int n = stoi(s.substr(1, 6));
  if (isupper(s[0]) and isupper(s[7]) and 100000 <= n and n < 1000000)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}