#include <stdio.h>
#include <vector>
#include <cfloat>
#include <math.h>
using namespace std;
#define ll long long int

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
	vector<double> a(9);
	double m1, m2, c1, c2;
	scanf("%d", &t);
	printf("INTERSECTING LINES OUTPUT\n");
	for(int i=0; i<t; i++) {
		// a[0] = x1   a[1] = y1
		// a[2] = x2   a[3] = y2
		// a[4] = x3   a[5] = y3
		// a[6] = x4   a[7] = y4
		for(int i=0; i<8; i++) scanf("%lf", &a[i]);
		if(a[0] == a[2] && a[4]==a[6]) {
			if(a[0]==a[4]) printf("LINE\n");
			else printf("NONE\n");
			continue;
		}else if(a[0]==a[2] || a[4]==a[6]) {
			printf("POINT ");
			vector<vector<double> > mat(2);
			mat[0].push_back(a[1]-a[3]);
			mat[0].push_back(-(a[0]-a[2]));
			mat[0].push_back(a[0]*mat[0][0]+a[1]*mat[0][1]);
			mat[1].push_back(a[5]-a[7]);
			mat[1].push_back(-(a[4]-a[6]));
			mat[1].push_back(a[4]*mat[1][0]+a[5]*mat[1][1]);
			vector<double> v;
			// for(auto i:r1) cout << i << " ";
			// printf("\n");
			// for(auto i:r2) cout << i << " ";
			// printf("\n"); 
			v = gauss(mat);
			if(v[0]==DBL_MAX) {
				printf("NONE\n");
				continue;
			}
			printf("%.2lf ", v[0]==-0.0?0.0:v[0]);
			printf("%.2lf", v[1]==-0.0?0.0:v[1]);
			// printf("GG\n");
			printf("\n");
			continue;
		}
		m1 = (a[1]-a[3])/(a[0]-a[2]==0.0?(double)0.000001:a[0]-a[2]);
		m2 = (a[5]-a[7])/(a[4]-a[6]==0.0?(double)0.000001:a[4]-a[6]);
		c1 = (a[1]-a[0]*m1);
		c2 = (a[5]-a[4]*m2);
		if(m1 == m2 && c1 == c2) {
			printf("LINE\n");
		}else if(m1 == m2) {
			printf("NONE\n");
		}else {
			printf("POINT ");
			vector<vector<double> > mat(2);
			mat[0].push_back(m1);
			mat[0].push_back(-1);
			mat[0].push_back(-c1);
			mat[1].push_back(m2);
			mat[1].push_back(-1);
			mat[1].push_back(-c2);
			vector<double> v;
			// for(auto i:r1) cout << i << " ";
			// printf("\n");
			// for(auto i:r2) cout << i << " ";
			// printf("\n"); 
			v = gauss(mat);
			printf("%.2lf ", v[0]);
			printf("%.2lf", v[1]);
			printf("\n");
		}
	}
	printf("END OF OUTPUT\n");
}