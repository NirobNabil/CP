#include <bits/stdc++.h>

using namespace std;

void print(vector< vector<double> > A) {
    int n = A.size();
    for (int i=0; i<n; i++) {
        for (int j=0; j<n+1; j++) {
            cout << A[i][j] << "\t";
            if (j == n-1) {
                cout << "| ";
            }
        }
        cout << "\n";
    }
    cout << endl;
}

vector<double> gauss(vector< vector<double> > A) {
    int n = A.size();

    for (int i=0; i<n; i++) {
        // Search for maximum in this column
        double maxEl = abs(A[i][i]);
        int maxRow = i;
        for (int k=i+1; k<n; k++) {
            if (abs(A[k][i]) > maxEl) {
                maxEl = abs(A[k][i]);
                maxRow = k;
            }
        }

        // Swap maximum row with current row (column by column)
        for (int k=i; k<n+1;k++) {
            double tmp = A[maxRow][k];
            A[maxRow][k] = A[i][k];
            A[i][k] = tmp;
        }

        // Make all rows below this one 0 in current column
        for (int k=i+1; k<n; k++) {
            double c = -A[k][i]/A[i][i];
            for (int j=i; j<n+1; j++) {
                if (i==j) {
                    A[k][j] = 0;
                } else {
                    A[k][j] += c * A[i][j];
                }
            }
        }
    }

    // Solve equation Ax=b for an upper triangular matrix A
    vector<double> x(n);
    for (int i=n-1; i>=0; i--) {
        x[i] = A[i][n]/A[i][i];
        for (int k=i-1;k>=0; k--) {
            A[k][n] -= A[k][i] * x[i];
        }
    }
    return x;
}

int main() {
    int n;
    scanf("%d", &n);
    vector<vector<double> > v(n, vector<double>(n+1,0));
    for(int i=0; i<n; i++) {
        for(int j=0; j<n+1; j++) {
            cin >> v[i][j];
        } 
    }
    vector<double> x;
    print(v);
    x = gauss(v);
    for(auto i:x) printf("%f ", i);
}

//////////////////////////
///// input format ///////
/////// 3       //////////
/////// 1 2 3 1 //////////
/////// 4 5 6 1 //////////
/////// 1 0 1 1 //////////
/// 1x + 2y + 3z = 1 /////
/// 4x + 4y + 6z = 1 /////
/// 1x + 0y + 1z = 1 /////