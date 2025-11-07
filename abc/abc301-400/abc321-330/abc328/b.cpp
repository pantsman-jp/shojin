#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main()
{
  int N;
  cin >> N;
  vector<int> D(N);
  for (auto &&d : D)
    cin >> d;
  vector<pair<int, int>> zorome;
  for (int i = 1; i <= 9; ++i)
  {
    zorome.emplace_back(i, i);
    zorome.emplace_back(i, i * 11);
    zorome.emplace_back(i * 11, i);
    zorome.emplace_back(i * 11, i * 11);
  }
  int ans{};
  for (const auto &[month, day] : zorome)
    if (month <= N && day <= D[month - 1])
      ++ans;
  cout << ans << endl;
}