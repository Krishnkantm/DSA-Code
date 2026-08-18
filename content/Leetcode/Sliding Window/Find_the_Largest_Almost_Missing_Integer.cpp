class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        //time => O(n)
        //space => O(50)

        if(n == k){
            return *max_element(nums.begin(),nums.end());
        }

        //case k == 1
        vector<int> freq(51,0);

        for(int i=0;i<n;i++){
            freq[nums[i]]++;
        }

        if(k == 1){
            for(int i=50;i>=0;i--){
                if(freq[i] == 1){
                    return i;
                }
            }

            return -1;
        }

        int temp = -1;

        if(freq[nums[0]] == 1){
            temp = max(temp,nums[0]);
        }

        if(freq[nums[n-1]] == 1){
            temp = max(temp,nums[n-1]);
        }

        return temp;
    }
};
