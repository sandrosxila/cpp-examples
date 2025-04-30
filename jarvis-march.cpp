#include <bits/stdc++.h>
using namespace std;

class Point
{
public:
  int x, y;

  bool operator<(const Point& b) const
  {
    if (y != b.y)
      return y < b.y;
    return x < b.x;
  }

  bool operator==(const Point& b) const
  {
    return x == b.x && y == b.y;
  }
};

long long getCrossProduct(Point& a, Point& b, Point& c)
{
  return (1LL * b.x - a.x) * (1LL * c.y - a.y) - (1LL * b.y - a.y) * (1LL * c.x - a.x);
}

// returns square of Euclidean distance between two points
long long getDistance(Point& a, Point& b)
{
  long long dx = a.x - b.x, dy = a.y - b.y;
  return dx * dx + dy * dy;
}

set<Point> jarvisMarch(vector<Point> points) {
  int n = points.size();
  Point& startPoint = points[0];
  int startIndex = 0;

  // Find the leftmost point as the start point
  for (int i = 1; i < n; i++) {
      if (points[i].x < startPoint.x) {
          startPoint = points[i];
          startIndex = i;
      }
  }

  set<Point> hull;
  vector<Point> collinearPoints;

  hull.insert(startPoint);

  Point curPoint = startPoint;
  int curIndex = startIndex;

  while(true) {
    Point nextPoint = points[0];
    int nextIndex = 0;

    for (int i = 1; i < n; i++) {
      if (curIndex == i) continue;

      int crossProduct = getCrossProduct(curPoint, nextPoint, points[i]);
      // if crossProduct > 0, points[i] is on the left of line curPoint-nextPoint
      if (crossProduct > 0) {
          nextPoint = points[i];
          nextIndex = i;
          // Clear collinearPoints because we change the nextPoint
          collinearPoints.clear();
      }
      // if crossProduct = 0, points[i] is collinear with curPoint and nextPoint
      else if (crossProduct == 0) {
          // Update nextPoint with points[i] is points[i] is further from curPoint
          if (getDistance(curPoint, points[i]) > getDistance(curPoint, nextPoint)) {
              collinearPoints.push_back(nextPoint);
              nextPoint = points[i];
              nextIndex = i;
          }
          // If nextPoint is on the boundary of convex hull
          // then all points in collinear points will be also on boundary.
          else {
              collinearPoints.push_back(points[i]);
          }
      }
    }

    // If nextPoint is the same as startPoint, we have formed an envelope and it is done.
    if (nextPoint == startPoint) {
      break;
  }

  // Add nextPoint to the result and set curPoint as nextPoint
  hull.insert(nextPoint);
  curPoint = nextPoint;
  curIndex = nextIndex;
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

  set<Point> hull = jarvisMarch(points);

  vector<vector<int>> outputPoints;
  for (auto point : hull)
  {
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