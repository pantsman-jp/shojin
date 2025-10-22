#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

double dist(vector<int> pos1, vector<int> pos2)
{
  int diffx = abs(pos1[0] - pos2[0]), diffy = abs(pos1[1] - pos2[1]);
  return sqrt(diffx * diffx + diffy * diffy);
}

bool is_phyta(vector<double> side)
{
  for (int i = 0; i < 3; i++)
  {
    double a = side[i], b = side[(i + 1) % 3], c = side[(i + 2) % 3];
    if (abs(a * a + b * b - c * c) < 1e-9)
      return true;
  }
  return false;
}

int main()
{
  vector<vector<int>> xy(3, vector<int>(2));
  for (int i = 0; i < 3; i++)
    cin >> xy[i][0] >> xy[i][1];
  vector<double> side(3);
  side[0] = dist(xy[0], xy[1]);
  side[1] = dist(xy[1], xy[2]);
  side[2] = dist(xy[2], xy[0]);
  if (is_phyta(side))
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
