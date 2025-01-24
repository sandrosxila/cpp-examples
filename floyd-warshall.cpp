#include <iostream>
#include <limits>
#include <utility>
using namespace std;

// defining the number of vertices
#define N 4

const int INF = INT_MAX / 2;

void printMatrix(int matrix[][N])
{
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      if (matrix[i][j] == INF)
        printf("%4s", "INF");
      else
        printf("%4d", matrix[i][j]);
    }
    printf("\n");
  }
}

int main() {
  int graph[N][N] = {
      {0, 3, INF, 5},
      {2, 0, INF, 4},
      {INF, 1, 0, INF},
      {INF, INF, 2, 0}
    };

  // Implementing floyd warshall algorithm
  int matrix[N][N], i, j, k;

  for (i = 0; i < N; i++)
    for (j = 0; j < N; j++)
      matrix[i][j] = graph[i][j];

  for (k = 0; k < N; k++) {
    for (i = 0; i < N; i++) {
      for (j = 0; j < N; j++) {
        matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
      }
    }
  }

  printMatrix(matrix);
}