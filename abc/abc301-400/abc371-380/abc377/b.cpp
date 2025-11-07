#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

int main()
{
  vector<string> s(8);
  for (int i = 0; i < 8; i++)
    cin >> s[i];
  set<int> row, line;
  for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < 8; j++)
    {
      if (s[i][j] == '#')
      {
        row.insert(i);
        line.insert(j);
      }
    }
  }
  cout << (8 - row.size()) * (8 - line.size()) << endl;
}
