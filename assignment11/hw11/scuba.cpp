/*
	Code Written by Harit Krishan
	Algorithms & Data Structures Spring 2020
	Prof. Dr. Kinga Lipskoch
	Assistance from geeksforgeeks.org, github.com
*/

#include <bits/stdc++.h>

using namespace std;

const int MAX = 1024;
const int INF = 999999999;

int N, O, n, t, cs;
int nitro[MAX];
int oxi[MAX];
int w[MAX];
int dp[MAX][22][80];
int visited[MAX][22][80];

int weight_fin(int i, int co, int cn) {
	if(dp[i][co][cn] != -1) {
		return dp[i][co][cn];
	}

	if(co == 0 && cn == 0) {
		dp[i][co][cn] = 0;
	} else if(i == 0) {
		dp[i][co][cn] = INF;
	} else {	
		dp[i][co][cn] = min(weight_fin(i-1, co, cn), weight_fin(i-1, 
			max(co - oxi[i-1], 0), max(cn - nitro[i-1], 0)) + w[i-1]);
	}
	return dp[i][co][cn];
}

int main() {
	cin >> t;
	while(t--) {
		
		cin >> O >> N >> n;

		for(int i = 0;i < n + 1; i++) {
			for(int j = 0;j < O + 1;j++) {
				for(int k = 0; k < N + 1; k++) {
					dp[i][j][k]=-1;
				}
			}
		}
	
		for(int i = 0; i < n; i++) {
            cin >> oxi[i] >> nitro[i] >> w[i];
		}

		cout << weight_fin(n,O,N) << endl;
		
	}
	return 0;
}