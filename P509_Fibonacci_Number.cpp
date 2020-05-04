class Solution {
public:
    int fib(int N) {
        if(N == 0 || N == 1) return (N==0)? 0 : 1;
        int tmp1 = 0, tmp2 = 1;
        int res;
        for(int i = 2; i <= N; i++){
            res = tmp1 + tmp2;
            tmp1 = tmp2, tmp2 = res;
        }
        return res;
    }
};
