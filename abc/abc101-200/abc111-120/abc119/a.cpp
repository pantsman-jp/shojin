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
  int mm = stoi(s.substr(5, 2)), dd = stoi(s.substr(8, 2));
  if (mm <= 4 and dd <= 30)
    cout << "Heisei" << endl;
  else
    cout << "TBD" << endl;
}