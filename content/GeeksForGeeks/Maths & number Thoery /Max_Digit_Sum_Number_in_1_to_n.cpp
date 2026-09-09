class Solution {
  public:
  
   //O(log n)
    int digitSum(string& str){
        
        int ans = 0;
        
        for(char ch : str){
            
            ans = ans + (ch - '0');
        }
        
        return ans;
    }
    
    int findMax(int n) {
        int number = n;
        
        string str = to_string(n);
        int bestSum = digitSum(str);
        
        //log n
        for(int i=0;i<str.size();i++){
            
            string temp = str;
            
            if(temp[i] == '0'){
                continue;
            }
            
            temp[i]--;
            
            for(int j=i+1;j<temp.size();j++){
                temp[j] = '9';
            }
            
            
            int sum = digitSum(temp);
            int new_number = stoi(temp);
            
            if(bestSum < sum  || (bestSum == sum && new_number > number)){
                bestSum = sum;
                number = new_number;
            }
        }
        
        //time =. O(long n)^2
        //space = O(m) => number digit in string
        return number;
    }
};
