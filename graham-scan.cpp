#include <bits/stdc++.h>
using namespace std;

class Point
{
public:
  int x, y;

  bool operator<(Point b)
  {
    if (y != b.y)
      return y < b.y;
    return x < b.x;
  }
};

// returns -1 if a -> b -> c forms a counter-clockwise turn,
// +1 for a clockwise turn, 0 if they are collinear
int ccw(Point a, Point b, Point c)
{
  long long area = (1LL * b.x - a.x) * (1LL * c.y - a.y) - (1LL * b.y - a.y) * (1LL * c.x - a.x);
  if (area > 0)
    return -1;
  else if (area < 0)
    return 1;
  return 0;
}

// returns square of Euclidean distance between two points
long long sqrDist(Point a, Point b)
{
  long long dx = a.x - b.x, dy = a.y - b.y;
  return dx * dx + dy * dy;
}

// used for sorting points according to polar order w.r.t the pivot
bool compare(Point &a, Point &b, Point &pivot)
{
  int order = ccw(pivot, a, b);
  if (order == 0)
    return sqrDist(pivot, a) < sqrDist(pivot, b);
  return (order == 1);
}

stack<Point> grahamScan(vector<Point> points)
{
  int n = points.size();
  stack<Point> hull;

  // find the point having the least y coordinate (pivot),
  // ties are broken in favor of lower x coordinate
  int minY = 0;
  for (int i = 1; i < n; i++)
    if (points[i] < points[minY])
      minY = i;

  // swap the pivot with the first point
  swap(points[0], points[minY]);

  // sort the remaining point according to polar order about the pivot
  Point &pivot = points[0];

  sort(points.begin() + 1, points.end(), [&](auto &a, auto &b)
       { return compare(a, b, pivot); });

  // Remove collinear points
  int m = 1;
  for (int i = 1; i < n; i++)
  {
    while (i < n - 1 && ccw(pivot, points[i], points[i + 1]) == 0)
    {
      i++;
    }
    points[m] = points[i]; // rewrite them eventually they will be popped and thrown away
    m++;
  }

  hull.push(points[0]);
  hull.push(points[1]);
  hull.push(points[2]);

  for (int i = 3; i < n; i++)
  {
    Point top = hull.top();
    hull.pop();
    while (ccw(hull.top(), top, points[i]) <= 0)
    {
      top = hull.top();
      hull.pop();
    }
    hull.push(top);
    hull.push(points[i]);
  }
  return hull;
}

vector<vector<int>> findConvexHull(vector<vector<int>> &inputPoints)
{
  int n = inputPoints.size();
  if (n < 3)
  {
    return inputPoints;
  }

  vector<Point> points;
  for (auto &point : inputPoints)
  {
    points.push_back({point[0], point[1]});
  }

  stack<Point> hull = grahamScan(points);

  vector<vector<int>> outputPoints;
  while (!hull.empty())
  {
    Point point = hull.top();
    hull.pop();
    outputPoints.push_back({point.x, point.y});
  }

  return outputPoints;
}

int main()
{
  vector<vector<int>> data = {{0, 0}, {2, 2}, {3, 4}, {4, 4}, {2, 4}, {4, 8}};

  vector<vector<int>> hullPoints = findConvexHull(data);

  for (auto point : hullPoints)
  {
    cout << point[0] << ' ' << point[1] << endl;
  }

  return 0;
}