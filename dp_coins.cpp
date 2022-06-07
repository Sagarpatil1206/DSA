/*You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.*/

#include<iostream>
#include<climits>
#include<algorithm> //to use fill_n (arr,number of elements,value)

using namespace std;

int coins(int n,int arr[],int dp[]){
    if(n==0){
        return 0;
    }

    int ans=INT_MAX;//we want minimum ans

    for(int i=0;i<3;i++){//iterating over 3 elemetns of our coins
        if(n-arr[i]>=0){ //going into first coin
            int subAns;//ans for particular number
            if(dp[n-arr[i]]!=-1){ //if the value is already calculated
                subAns=dp[n-arr[i]];
            }else{   //if its not then calculate it
                subAns=coins(n-arr[i],arr,dp);//subAns is 0 when n-arr[i] is 0 and final ans will be 1 as it will indicate that only one coin is needed
            }

            if(subAns!=INT_MAX && (subAns+1)<ans){ //if its smaller than previous ones (first one is INT_MAX)
                ans=subAns+1; //as 1 more coin for final ans;
            }//finding tino me se chhota
        }
    }
    dp[n]=ans; //for the ones who are smaller than all of three and cant be furthur divivded INT_MAX will be ans;
    return ans;
}

  /*                                           18(7,5,1)                                              
                                        -7       -5            -1
                                    11           13            17
                               4    6    10    6  8  12     10  12  16*/

int main(){
    int n=18;
    int arr[]={1,5,7};//try 5 6 7
    int dp[n+1]; //in this array we will store how many coins are neewdwd to make this
    fill_n(dp,19,-1);//array dp gets filled having 19 elements and intialize with -1
    dp[0]=0;//0 th element will have 0 as for getting 0 rupees 0 coins needed
    int length=sizeof(arr)/sizeof(arr[0]);
    int ans=coins(n,arr,dp);
    cout<<ans<<endl;
    for(int i=0;i<19;i++){
        cout<<dp[i]<<" ";
    }
}