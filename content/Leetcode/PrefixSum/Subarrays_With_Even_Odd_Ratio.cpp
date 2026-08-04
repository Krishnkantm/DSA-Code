#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
using namespace __gnu_pbds;
using namespace std;

typedef tree<
    pair<long long,int>,
    null_type,
    less<pair<long long,int>>,
    rb_tree_tag,
    tree_order_statistics_node_update
> ordered_multiset;

class Solution {
public:
    typedef long long ll;

    long long countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n = nums.size();

        ordered_multiset st; 

         //o(n)
        for (int i = 0; i < n; i++) {
            nums[i] = nums[i] % 2;
        }
  
        vector<ll> even(n, 0);
        vector<ll> odd(n, 0);

        ll ones = 0;
        ll zeroes = 0;
    
       //o(n)
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0)
                zeroes++;
            else
                ones++;

            even[i] = zeroes;
            odd[i] = ones;
        }

        ll ans = 0;
        int idx = 0;

        st.insert({0, idx++});

         //o(n)
        for(int j=0;j<n;j++){
            ll RHS = odd[j]*a - even[j]*b;

            ll LHS = (j-1 >= 0) ?  odd[j-1]*a - even[j-1]*b : 0;

            if(j-1 >= 0){
                st.insert({LHS,idx++});
            }

            ll curr = st.order_of_key({RHS,INT_MAX}); // O(log n)
            ans += curr;
        }

        //time complexity => o(n log n)
       //space complexity => O(n)

        return ans;
    }
};