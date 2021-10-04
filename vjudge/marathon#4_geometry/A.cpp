#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define X first
#define Y second
#define A begin
#define B end
#define S1 100000
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

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
    // print(A);
    // Solve equation Ax=b for an upper triangular matrix A
    vector<double> x(n);
    for (int i=n-1; i>=0; i--) {
    	if(A[i][i]==0) return vector<double>(n, DBL_MAX);
      x[i] = A[i][n]/A[i][i];
      for (int k=i-1;k>=0; k--) {
          A[k][n] -= A[k][i] * x[i];
      }
    }
    return x;
}


int main(){
	int i, ix, t, n;
	double x1,y1,x2,y2,x3,y3,x,y;
	while(scanf("%lf", &x1)!=EOF){
		scanf("%lf", &y1);
		scanf("%lf", &x2);
		scanf("%lf", &y2);
		scanf("%lf", &x3);
		scanf("%lf", &y3);
		vector<vector<double> > v(3,vector<double>(3,0));
		v = { { 2*(x1-x2), 2*(y1-y2), x1*x1+y1*y1-x2*x2-y2*y2 },
					{ 2*(x1-x3), 2*(y1-y3), x1*x1+y1*y1-x3*x3-y3*y3 } };
		vector<double> ans = gauss(v);
		// print(v);
		if(ans[0]==DBL_MAX) printf("Impossible\n");
		else {
			for(auto i:ans) printf("%lf ", (i==-0.0)?0.0:i);
			printf("\n");
		}
	}
}