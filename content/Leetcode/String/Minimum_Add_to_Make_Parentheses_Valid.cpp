class Solution {
public:
    int minAddToMakeValid(string s) {
        int balance = 0;
        int opr = 0;
         
         //time -> O(n)
         //space -> O(1)
        for (char ch : s) {
            if (ch == '('){
                balance++;
            }
            else{
                balance--;

                if(balance < 0){
                    balance++;
                    opr++;
                }
            }
        }

        opr += balance;

        return opr;
    }
};
