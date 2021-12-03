#include <iostream>
#include <fstream>
using namespace std;
  
int main()
{
    
  
  int n, m, i, j, k;
  n = 5; 
  m = 3; 
  int allocation[5][3] = { { 0, 1, 0 }, 
                     { 2, 0, 0 }, 
                     { 3, 0, 2 }, 
                     { 2, 1, 1 }, 
                     { 0, 0, 2 } }; 
  
  int maxmatrix[5][3] = { { 7, 5, 3 }, 
                   { 3, 2, 2 }, 
                   { 9, 0, 2 }, 
                   { 2, 2, 2 }, 
                   { 4, 3, 3 } }; 
  
  int available[3] = { 3, 3, 2 }; // For the resources
  
  int f[n], ans[n], ind = 0;
  for (k = 0; k < n; k++) {
    f[k] = 0;
  }
  int need[n][m];// this is for the matrix 
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++)
      need[i][j] = maxmatrix[i][j] - allocation[i][j];
  }
  int y = 0;
  for (k = 0; k < 5; k++) {
    for (i = 0; i < n; i++) {
      if (f[i] == 0) {
  
        int flag = 0;
        for (j = 0; j < m; j++) {
          if (need[i][j] > available[j]){
            flag = 1;
            break;
          }
        }
  
        if (flag == 0) {
          ans[ind++] = i;
          for (y = 0; y < m; y++)
            available[y] += allocation[i][y];
          f[i] = 1;
        }
      }
    }
  }
  
  cout << "The safe sequence from the data is" << endl; // this is the output for the a.out file 
  for (i = 0; i < n - 1; i++)
    cout << ans[i] << " ";
  cout << ans[n - 1] <<endl;
  
    return (0);
}