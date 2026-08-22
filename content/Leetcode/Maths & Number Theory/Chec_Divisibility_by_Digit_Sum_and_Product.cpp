class Solution {
public:
    int digitSum(int num) {
        int sum = 0;
        int p = 1;

        int n = num;

        while (n != 0) {
            int digit = n % 10;
            sum += digit;
            p *= digit;
            n /= 10;
        }

        return sum + p;
    }

    bool checkDivisibility(int n) {
        int ans = digitSum(n);

        //time => O(d) => d = number of digits 
        //space => (1)

        if (n % ans == 0) {
            return true;
        }

        return false;
    }
};
