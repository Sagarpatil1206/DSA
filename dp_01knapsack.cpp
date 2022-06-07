#include<iostream>
using namespace std;

int knapSack(int objectWeights[],int price[],int n,int capacity){

    int matrix[n+1][capacity+1];
    for(int i=0;i<n+1;i++){
        matrix[i][0]=0;
    }

    for(int i=0;i<=capacity;i++){
        matrix[0][i]=0;
    }

    for(int i=1;i<n+1;i++){
        for(int j=1;j<=capacity;j++){
            if(objectWeights[i]>j){
                matrix[i][j]=matrix[i-1][j];
            }else{

                int currVal=price[i]+matrix[i-1][j-objectWeights[i]];
                int prevVal=matrix[i-1][j];

                if(currVal>=prevVal){
                    matrix[i][j]=currVal;
                }else{
                    matrix[i][j]=prevVal;
                }
            }

            }
        }
    cout<<"here\n";
    for(int i=0;i<n+1;i++){
        for(int j=0;j<=capacity;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return matrix[n][capacity];
}

int main(){
    int objectWeights[5]={0,1,3,4,6};
    int capacity=10;
    int price[5]={0,20,30,10,50};
    //find maximum profit
    int maxProfit=knapSack(objectWeights,price,4,capacity);
    cout<<maxProfit;
}