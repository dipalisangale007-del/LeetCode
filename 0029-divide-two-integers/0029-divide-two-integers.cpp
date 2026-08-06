class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        if (dividend == INT_MIN && divisor == 1) return INT_MIN;

        long long dd = llabs((long long)dividend);
        long long dv = llabs((long long)divisor);

        int ans = 0;

        while (dv <= dd) {
            long long sum = dv, count = 1;
            while (sum <= dd - sum) {
                sum += sum;
                count += count;
            }
            ans += count;
            dd -= sum;
        }

        if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0))
            return -ans;

        return ans;
    }
};
