class Solution {
public:
    long long countCommas(long long n) {
        if(n < 1000){
            return 0;
        }

      //time => O(log n)
      //space => O(1)

        long long start = 1000;
        long long commas = 1;
        long long ans = 0;

        while(start <= n){
            long long end = min(start*1000-1,n);

            ans += (end - start+1) * commas;
            commas += 1;
            start = start*1000;
        }

        return ans;
    }
};
