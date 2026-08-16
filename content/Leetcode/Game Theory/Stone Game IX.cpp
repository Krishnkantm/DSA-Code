class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int n = stones.size();

        vector<int> reminder(3,0);
        //time => O(n)
        //space => O(3) => O(1)

        for(int i=0;i<n;i++){
           reminder[stones[i] % 3]++;
        }

        if(reminder[0] % 2 == 0){
            return reminder[1] > 0 && reminder[2] > 0;
        }
        else{
            return abs(reminder[1] - reminder[2]) > 2;
        }

    }
};
