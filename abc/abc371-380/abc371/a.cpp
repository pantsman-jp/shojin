#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main()
{
  string x, y, z;
  cin >> x >> y >> z;
  string s = x + y + z;
  if (s == "><<" or s == "<>>")
  {
    cout << "A" << endl;
    return 0;
  }
  if (s == "<<<" or s == ">>>")
  {
    cout << "B" << endl;
    return 0;
  }
  if (s == "<<>" or s == ">><")
  {
    cout << "C" << endl;
    return 0;
  }
}
