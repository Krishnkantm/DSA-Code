#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestNumber(int n, int t) {

        //Time complexity: O(100) * O(3) => O(300) => O(1)
        //space complexity: O(1)
        for(int i=n;i<=100;i++){
            int product = 1;
            int x = i;

            while(x){
                int digit = x % 10;
                product *= digit;
                x /= 10;
            }

            if(product % t == 0) return i;
        }

        return -1;
    }
};