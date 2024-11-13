// Sum of first N numbers



/*
#include<bits/stdc++.h>
using namespace std;
 void solve(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
      sum += i;
    }
    cout<<"The sum of the first "<<n<<" numbers is: "<<sum<<endl;
  }

  void solve1(int N) {
    int sum = N * (N + 1) / 2;
    cout<<"The sum of the first "<<N<<" numbers is: "<<sum<<endl;
  }


 int main() {

    solve(5);
    solve(6);
  }
*/

/*
#include<bits/stdc++.h>
using namespace std;

int sum=0;
void printCounting(int i,int num)
{   
    if(i>num) 
    {
        cout<<sum;
        return;
    }
    sum+=i;
    printCounting(i+1,num);
}

int main() 
{
    int printTime=0;
    cin>>printTime;
    printCounting(1,printTime);
    return 0;
}
*/

#include<bits/stdc++.h>
using namespace std;
int sum(int num)
{   
    if(num==0) return 0 ;
    else return num+sum(num-1);
}

int main() 
{
    int printTime=0;
    cin>>printTime;
    cout<<sum(printTime);
    return 0;
}