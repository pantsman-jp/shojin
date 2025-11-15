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
  char c;
  cin >> c;
  if (c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u')
    cout << "vowel" << endl;
  else
    cout << "consonant" << endl;
}