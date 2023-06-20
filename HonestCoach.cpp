/*
There are 𝑛
 athletes in front of you. Athletes are numbered from 1
 to 𝑛
 from left to right. You know the strength of each athlete — the athlete number 𝑖
 has the strength 𝑠𝑖
.

You want to split all athletes into two teams. Each team must have at least one athlete, and each athlete must be exactly in one team.

You want the strongest athlete from the first team to differ as little as possible from the weakest athlete from the second team. Formally, you want to split the athletes into two teams 𝐴
 and 𝐵
 so that the value |max(𝐴)−min(𝐵)|
 is as small as possible, where max(𝐴)
 is the maximum strength of an athlete from team 𝐴
, and min(𝐵)
 is the minimum strength of an athlete from team 𝐵
.

For example, if 𝑛=5
 and the strength of the athletes is 𝑠=[3,1,2,6,4]
, then one of the possible split into teams is:

first team: 𝐴=[1,2,4]
,
second team: 𝐵=[3,6]
.
In this case, the value |max(𝐴)−min(𝐵)|
 will be equal to |4−3|=1
. This example illustrates one of the ways of optimal split into two teams.

Print the minimum value |max(𝐴)−min(𝐵)|
.

Input
The first line contains an integer 𝑡
 (1≤𝑡≤1000
) — the number of test cases in the input. Then 𝑡
 test cases follow.

Each test case consists of two lines.

The first line contains positive integer 𝑛
 (2≤𝑛≤50
) — number of athletes.

The second line contains 𝑛
 positive integers 𝑠1,𝑠2,…,𝑠𝑛
 (1≤𝑠𝑖≤1000
), where 𝑠𝑖
 — is the strength of the 𝑖
-th athlete. Please note that 𝑠
 values may not be distinct.

Output
For each test case print one integer — the minimum value of |max(𝐴)−min(𝐵)|
 with the optimal split of all athletes into two teams. Each of the athletes must be a member of exactly one of the two teams.

input:
5
5
3 1 2 6 4
6
2 1 3 2 4 3
4
7 9 3 1
2
1 1000
3
100 150 200

output:
1
0
2
999
50

*/



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