#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main()
{
  string s;
  cin >> s;
  if (find(s.begin(), s.end(), 'R') < find(s.begin(), s.end(), 'M'))
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
