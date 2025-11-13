#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

bool check(int n)
{
  return 1 <= n and n <= 12;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  int s01 = stoi(s.substr(0, 2)), s23 = stoi(s.substr(2, 2));
  bool mm01 = check(s01), mm23 = check(s23);
  if (mm01 and mm23)
    cout << "AMBIGUOUS" << endl;
  else if (!mm01 and mm23)
    cout << "YYMM" << endl;
  else if (mm01 and !mm23)
    cout << "MMYY" << endl;
  else
    cout << "NA" << endl;
}