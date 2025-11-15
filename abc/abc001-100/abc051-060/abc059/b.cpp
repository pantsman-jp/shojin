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
  string a, b;
  cin >> a >> b;
  if (a.size() < b.size())
    cout << "LESS" << endl;
  else if (a.size() > b.size())
    cout << "GREATER" << endl;
  else if (a < b)
    cout << "LESS" << endl;
  else if (a > b)
    cout << "GREATER" << endl;
  else
    cout << "EQUAL" << endl;
}