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
  map<string, int> contest = {{"ABC", 0}, {"ARC", 0}, {"AGC", 0}, {"AHC", 0}};
  string s1, s2, s3;
  cin >> s1 >> s2 >> s3;
  contest[s1]++, contest[s2]++, contest[s3]++;
  for (auto [ans, c] : contest)
    if (c == 0)
      cout << ans << endl;
}