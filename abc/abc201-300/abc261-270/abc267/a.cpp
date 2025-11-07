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
  if (s == "Monday")
    cout << 5 << endl;
  if (s == "Tuesday")
    cout << 4 << endl;
  if (s == "Wednesday")
    cout << 3 << endl;
  if (s == "Thursday")
    cout << 2 << endl;
  if (s == "Friday")
    cout << 1 << endl;
}