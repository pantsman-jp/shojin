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
  string ans;
  if (s == "WBWBWWBWBWBWWBWBWWBW")
    ans = "Do";
  else if (s == "WBWWBWBWBWWBWBWWBWBW")
    ans = "Re";
  else if (s == "WWBWBWBWWBWBWWBWBWBW")
    ans = "Mi";
  else if (s == "WBWBWBWWBWBWWBWBWBWW")
    ans = "Fa";
  else if (s == "WBWBWWBWBWWBWBWBWWBW")
    ans = "So";
  else if (s == "WBWWBWBWWBWBWBWWBWBW")
    ans = "La";
  else
    ans = "Si";
  cout << ans << endl;
}