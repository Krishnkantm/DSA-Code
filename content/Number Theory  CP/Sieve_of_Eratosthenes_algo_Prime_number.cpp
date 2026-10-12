#include<bits/stdc++.h>

using namespace std;

void sieve(vector<bool>& primes){

    //base case
    primes[0] = primes[1] = false;

    int n = primes.size();
    
    //O(log n)
    for(int i=2;i*i<=n;i++){

        if(primes[i]){
            
            //O(long n)
            for(int j=i*i;j<=n;j += i){
               primes[j] = false;
            }
        }
    }
}

int main(){
    int n;

    cout<<"Enter a number"<<endl;
    cin>>n;

    vector<bool> primes(n+1,true);

    sieve(primes); //O(nlong long n)
    //space -> O(n)

    for(int i=0;i<=n;i++){
        if(primes[i]){
            cout<<i<<" ";
        }
    }

    return 0;
}
