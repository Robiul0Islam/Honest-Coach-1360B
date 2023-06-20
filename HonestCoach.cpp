#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    int tt[t];
    
    for(int i=0;i<t;i++){

        int n;
        cin>>n;
        int s[n];
        for(int j=0;j<n;j++){
            cin>>s[j];
        }

        for(int k=0;k<n;k++){
            for(int l=0;l<n-k-1;l++){
                if(s[l+1]<s[l]){
                    int temp=s[l+1];
                    s[l+1]=s[l];
                    s[l]=temp;
                }
            }
        }

        int min=s[n-1]-s[0];
        for(int m=0;m<n-1;m++){
            int ans=s[m+1]-s[m];
            if(ans<=min){
                min=ans;
            }
        }

        tt[i]=min;



    }
    for(int i=0;i<t;i++){
        cout<<tt[i]<<"\n";
    }
}