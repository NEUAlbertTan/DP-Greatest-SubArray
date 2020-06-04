/***********************
***NEU CSE Albert Tan***
*ALL Greatest SubArrays*
************************/
//uncomment the code in MAIN !

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//The length of the array
#define N 7
//sample
int a[N]={2,1,-3,1,2,-1,1};


void greatestSubArr()
{
    int b[N] = {};
    b[0] = a[0];
    //get the b[N] by DP
    for(int i=1; i<N; i++){
        b[i] = b[i-1]>=0 ? b[i-1] + a[i] : a[i];
    }
    int max_sum = 0;
    cout<<"b[i] list:";
    for(int i=0; i<N; i++){
        cout<<b[i]<<' ';
        max_sum = b[i]>max_sum? b[i]:max_sum;
    }
    cout<<endl;

    for(int i=0 ;i<N; i++){
        int low=0,high=i;
        if( b[i]<=0 || a[i] == b[i] ){
            if( b[i] <=0 ){
                low = i+1;
            } else {
                low = i;
            }
            for(int j=i; j<N; j++){
                if( b[j] == max_sum ){
                    high = j;
                    //actually O(n) avoid overlapping
                    i = j;
                    break;
                }
            }
            //print the subarray
            cout<<"The greatest subarray: ";
            for(int n = low; n<=high; n++){
                cout<<a[n]<<' ';
            }
            cout<<endl;
            if( low == 0 ){
            break;
            }
        }
        
    }
    cout<<endl;
    cout<<"The sum of greatest subarray:"<<max_sum<<endl;
}


int main()
{
    /****************************************
    *initialize the array with random numbers*
    *****************************************/
    /*
    srand(time(0));
    cout<<"The array contains: ";
    for(int i=0; i<N; i++){
        a[i] = rand()%100-30;
        cout<<a[i]<<' ';
    }
    cout<<endl;
    //To see if there is any positive number
    bool noPostive=true;
    for(int i=0; i<N; i++){
        if(a[i]>0){
            noPostive=false;
            break;
        }
    }
    //If there is no positive number
    if( noPostive ){
        cout<<"No positive item in this array"<<endl;
        return 0;
    }
    */


    //start searching
    greatestSubArr();

    return 0;
}
