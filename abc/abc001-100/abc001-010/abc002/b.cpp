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
  string w;
  cin >> w;
  vector<char> vowel = {'a', 'i', 'u', 'e', 'o'};
  for (char c : w)
  {
    if (find(all(vowel), c) != vowel.end())
      continue;
    else
      cout << c;
  }
  cout << endl;
}