int mem[101][100001];

int solveUtil(vector<int> &A, int N, int sum) {
    if(sum == 0) return 1;
    if(N == 0) return 0;
    if (mem[N][sum] != -1) return mem[N][sum];
    if(A[N-1] > sum) {
        return mem[N-1][sum] = solveUtil(A, N-1, sum);
    } else {
        return mem[N-1][sum] = (solveUtil(A, N-1, sum-A[N-1]) || solveUtil(A, N-1, sum));
    }
}



int Solution::solve(vector<int> &A, int B) {
    for(int i=0; i<101; i++) {
        for(int j=0; j<100001; j++) {
            if(i==0) mem[i][j] = 0;
            if(j==0) mem[i][j] = 1;
            if(i != 0 && j!=0) mem[i][j] = -1;
            
        }
    }
    return solveUtil(A, A.size(), B);
}

