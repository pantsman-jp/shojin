#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main()
{
  vector<int> count(13);
  rep(i, 7)
  {
    int a;
    cin >> a;
    count[a - 1]++;
  }
  rep(i, 13)
  {
    for (int j = i + 1; j < 13; j++)
    {
      if ((count[i] >= 3 and count[j] >= 2) or (count[i] >= 2 and count[j] >= 3))
      {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
}
