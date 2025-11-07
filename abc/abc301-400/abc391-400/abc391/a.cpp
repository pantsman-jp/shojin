#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main()
{
  string d;
  cin >> d;
  map<char, char> oppo = {{'N', 'S'}, {'E', 'W'}, {'S', 'N'}, {'W', 'E'}};
  string ans;
  for (char c : d)
    ans += oppo[c];
  cout << ans << endl;
}
