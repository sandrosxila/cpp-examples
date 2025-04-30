#include <bits/stdc++.h>
using namespace std;

class Point    {
    public:
        int x, y;

        bool operator < (Point b) {
            if (y != b.y)
                return y < b.y;
            return x < b.x;
        }

        string toString() {
            return "(" + to_string(x) + "," + to_string(y) + ")";
        }
};

// returns -1 if a -> b -> c forms a counter-clockwise turn,
// +1 for a clockwise turn, 0 if they are collinear
int ccw(Point a, Point b, Point c) {
    int area = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    if (area > 0)
        return -1;
    else if (area < 0)
        return 1;
    return 0;
}

// returns square of Euclidean distance between two points
int sqrDist(Point a, Point b)  {
    int dx = a.x - b.x, dy = a.y - b.y;
    return dx * dx + dy * dy;
}

// used for sorting points according to polar order w.r.t the pivot
bool compare(Point& a, Point& b, Point& pivot, bool side)  {
    int order = (side ? 1 : -1) * ccw(pivot, a, b);
    if (order == 0)
        return sqrDist(pivot, a) < sqrDist(pivot, b);
    return (order == -1);
}

stack<Point> grahamScan(vector<Point> points, int side)    {
    int n = points.size();
    stack<Point> hull;

    // find the point having the least y coordinate (pivot),
    // ties are broken in favor of lower x coordinate
    int leastY = 0;
    for (int i = 1; i < n; i++)
        if (points[i] < points[leastY])
            leastY = i;

    // swap the pivot with the first point
    swap(points[0], points[leastY]);

    // sort the remaining point according to polar order about the pivot
    Point &pivot = points[0];
    sort(points.begin() + 1, points.end(), [&](auto &a, auto &b) {
        return compare(a, b, pivot, side);
    });

    hull.push(points[0]);
    hull.push(points[1]);
    hull.push(points[2]);

    for (int i = 3; i < n; i++) {
        Point top = hull.top();
        hull.pop();
        while (ccw(hull.top(), top, points[i]) == (side ? 1 : -1))   {
            top = hull.top();
            hull.pop();
        }
        hull.push(top);
        hull.push(points[i]);
    }
    return hull;
}

vector<vector<int>> findConvexHull(vector<vector<int>>& inputPoints) {
    int n = inputPoints.size();
    if(n < 3) {
        return inputPoints;
    }

    vector<Point> points;
    for (auto &point : inputPoints) {
        points.push_back({point[0], point[1]});
    }

    stack<Point> hullLower = grahamScan(points, false);
    stack<Point> hullUpper = grahamScan(points, true);
    unordered_map<string, bool> taken;
    
    vector<vector<int>> outputPoints;
    while (!hullUpper.empty() || !hullLower.empty()) {
        stack <Point>& hull = !hullUpper.empty() ? hullUpper : hullLower;
        Point point = hull.top();
        hull.pop();
        string key = point.toString();

        if(!taken[key])
            outputPoints.push_back({point.x, point.y});
        
        taken[key] = true;
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