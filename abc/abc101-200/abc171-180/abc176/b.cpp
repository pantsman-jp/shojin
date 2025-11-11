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
  int sum = 0;
  for (char c : s)
    sum += (int)(c - '0') % 9;
  if (sum % 9 == 0)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}