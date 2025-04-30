#include <bits/stdc++.h>
using namespace std;

struct Point {
    long long x;
    long long y;
};

static bool comparePoints(Point &a, Point &b) {
    return a.x < b.x;
}

long long calculateDistance(Point p1, Point p2, Point p) {
    return abs((p.y - p1.y) * (p2.x - p1.x) - (p2.y - p1.y) * (p.x - p1.x));
}

int crossProduct(Point a, Point b, Point c) {
    long long area = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);

    if (area < 0)
        return -1; // clockwise

    if (area > 0)
        return 1; // counter-clockwise

    return 0; // collinear
}

bool tryAddToSet(vector<Point> &pointsSet, Point &p1, Point &p2, Point& p) {
    int crossProd = crossProduct(p1, p2, p);
    if (crossProd >= 0)
        pointsSet.push_back(p);
    
    return crossProd >= 0;
}

void findConvexHull(vector<Point> &points, vector<Point> &hull, Point &left, Point &right) {
    if (points.empty())
        return;
    
    int farthestIdx = 0;
    int maxDist = calculateDistance(left, right, points[0]);
    int n = points.size();

    for (int i = 0; i < n; i++) {
        long long currentDist = calculateDistance(left, right, points[i]);
        if (currentDist > maxDist) {
            maxDist = currentDist;
            farthestIdx = i;
        }
    }
    hull.push_back(points[farthestIdx]);
    
    vector<Point> leftSet, rightSet;
    for (int i = 0; i < n; i++) {
        if (i == farthestIdx)
            continue;

        if(!tryAddToSet(leftSet, left, points[farthestIdx], points[i]))
            tryAddToSet(rightSet, points[farthestIdx], right, points[i]);
    }

    findConvexHull(leftSet, hull, left, points[farthestIdx]);
    findConvexHull(rightSet, hull, points[farthestIdx], right);
}

vector<vector<int>> quickHull(vector<vector<int>>& inputPoints) {
    int n = inputPoints.size();

    // Edge case: No hull to form if the number of points is 1 or less
    if (n <= 1)
      return inputPoints;

    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        points[i].x = inputPoints[i][0];
        points[i].y =inputPoints[i][1];
    }
    
    Point left = points[0];
    Point right = points.back();

    vector<Point> hull;
    
    // Find the leftmost and rightmost points
    sort(points.begin(), points.end(), comparePoints);
    hull.push_back(left);
    hull.push_back(right);
    
    vector<Point> leftSet, rightSet, collinearPoints;
    for (int i = 1; i < n - 1; i++) {
        int crossProd = crossProduct(left, right, points[i]);
        if (crossProd < 0)
            rightSet.push_back(points[i]);
        else if (crossProd > 0)
            leftSet.push_back(points[i]);
        else
            collinearPoints.push_back(points[i]);
    }

    // If one of the sides is empty, add collinear points to the hull
    if (leftSet.empty() || rightSet.empty())
        for (const auto &point : collinearPoints)
            hull.push_back(point);

    findConvexHull(leftSet, hull, left, right);
    findConvexHull(rightSet, hull, right, left);
    
    vector<vector<int>> outputPoints;
    for (const auto &point : hull) {
        outputPoints.push_back({(int)point.x, (int)point.y});
    }

    return outputPoints;
}

int main() {
    vector<vector<int>> data = {{0, 0}, {2, 2}, {3, 4}, {4, 4}, {2, 4}, {4, 8}};

  vector<vector<int>> hullPoints = quickHull(data);

  for(auto point: hullPoints) {
    cout << point[0] << ' ' << point[1] << endl;
  }

  return 0;
}