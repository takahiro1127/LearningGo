#include<iostream>
#include <cstdlib>
using namespace std;

bool checkTravelable(int[3], int[3]);

int main() {
  int n;
  cin >> n;
  int vectors[n+1][3];
  vectors[0][0] = 0;
  vectors[0][1] = 0;
  vectors[0][2] = 0;

  bool travelable = true;
  for (int i = 1; i <= n && travelable; i++) {
    cin >> vectors[i][0] >> vectors[i][1] >> vectors[i][2];
    travelable = checkTravelable(vectors[i - 1], vectors[i]);
  }
  fputs(travelable ? "Yes" : "No", stdout);
  return 0;
}

bool checkTravelable(int start[3], int goal[3]) {
  bool travelable = false;
  if (start[0] == goal[0]) {
    if (start[1] == goal[1] && start[2] == goal[2]) {
      return true;
    } else {
      return false;
    }
  } else {
    if (start[1] != goal[1]) {
      start[0] += 1;
      start[1] += (goal[1] - start[1]) / abs(goal[1] - start[1]);
      travelable = checkTravelable(start, goal);
    } else if (start[2] != goal[2]) {
      start[0] += 1;
      start[2] += (goal[2] - start[2]) / abs(goal[2] - start[2]);
      travelable = checkTravelable(start, goal);
    } else {
      if ((goal[0] - start[0])%2 == 0) {
        travelable = true;
      }
    }
  }
  return travelable;
}
