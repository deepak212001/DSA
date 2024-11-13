/*
1. DIGITS CONCEPT

    n=7789
    n=n%10;   9   % ->reminder
    n=n/10; //n=778.9 so n=778

1. COUNT DIGITS
#include<bits/stdc++.h>
using namespace std;

int countdigits(int num) {
    if(num == 0) // Handling the case when the input number is 0
        return 1;
    
    int count = 0;
    while (num > 0) {
        count++;
        num = num / 10;
    }
    return count;
}
//also use 
int countdigit(int num) {
    int count = (int)(log10(num)+1);
    return count;
}
int main() {
    int n;
    cin >> n;
    cout << countdigits(n);
    return 0;
}
    
*/
/*
2. REVERSE A NUMBER

#include<bits/stdc++.h>
using namespace std;

int reverse(int num) {
    int res=0;
    while(num>0)
    {
        int last=num%10;
        res=(res*10)+last;
        num/=10;
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    cout << reverse(n);
    return 0;
}

*/

/*
3. CHECK PALINDROME

#include<bits/stdc++.h>
using namespace std;

int reverse(int num) 
{
    if (num < 0 ) 
         return 0;
    int res=0;
    while(num>0)
    {
        int last=num%10;
        res=(res*10)+last;
        num/=10;
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    int dummy=n;
    int y=reverse(n);
    if(dummy==y)
        cout<<"Palindrome Number "<< endl;
    else cout<<"Not Palindrome Number " << endl;
    return 0;
}


*/

/*
4. GCD AUR HCF

*/

/*
5.ARMSTRONG NUMBER

#include<bits/stdc++.h>
using namespace std;

bool armstrong(int num) 
{
    int originalno = num;
    int res=0;
    int temp=num;
    int count=0;
    while(temp>0)
    {
        count++;
        temp/=10;
    }
    while(num>0)
    {
        int last=num%10;
        res+=pow(last,count);
        num/=10;
    }
    return res==originalno;
}

int main() {
    int n;
    cin >> n;
    if(armstrong(n))
        cout<<"Armstrong Number "<< endl;
    else cout<<"Not Armstrong Number " << endl;
    return 0;
}

*/

/*
6. PRINT ALL DIVISORS


#include<bits/stdc++.h>
using namespace std;

void print(int num)
{
    for(int i=1;i<=num;i++)
    {
        if(num%i==0)
            cout<<i<<endl;
    }
}

int main() {
    int n;
    cin >> n;
    print(n);
    return 0;
}

//aur

// TC= O(nlogn)
#include<bits/stdc++.h>
using namespace std;

void print(int num)
{
    vector<int> v;
    for(int i=1;i*i<=num;i++)    // i<=sqrt(n) bhi use kar skte the par TC increase ho jata 
    {
        if(num%i==0)
        {   
            v.push_back(i);
            if(i!=sqrt(num))
                v.push_back(num/i);
        }
    }
    sort(v.begin(),v.end());
    for(auto i: v) cout<<i<<endl;
}

int main() {
    int n;
    cin >> n;
    print(n);
    return 0;
}

7. prime number ;- excutly 2 factor 1 and itself

// TC= O(n)

#include<bits/stdc++.h>
using namespace std;

void prime(int num)
{
    for(int i=2;i<num;i++)    
    {
        if(num%i==0)
        {
            cout<<num<<" IS NOT A PRIME NUMBER";
            return ;
        }
    }
    cout<<num<<" IS A PRIME NUMBER";
}

int main() {
    int n;
    cin >> n;
    prime(n);
    return 0;
}

// TC= O(nlogn)
#include<bits/stdc++.h>
using namespace std;

void prime(int num)
{
    for(int i=2;i*i<=num;i++)    
    {
        if(num%i==0)
        {
            cout<<num<<" IS NOT A PRIME NUMBER";
            return ;
        }
    }
    cout<<num<<" IS A PRIME NUMBER";
}

int main() {
    int n;
    cin >> n;
    prime(n);
    return 0;
}


8. GCD OR HCF

GCD - greatest common dividors
HCF - highest common factor
n1=9 -> 1,3,9
n2=12 ->1,2,3,4,6,12

common factors-> 1,3
GCD/HCF->3

n1=11 -> 1,11
n2=13 ->1,13

common factors-> 1
GCD/HCF->1
do prime number ka HCF always 1


n1>n2
hcf(n1,n2) = hcf(n1-n2,n2)  // equilateral Algo
hcf(9,12)= hcf(3,9)
hcf(11,13)= hcf(2,11)

//TC=o(n)
//alway wrost case
#include<bits/stdc++.h>
using namespace std;

void hcf(int num1,int num2)
{
    for(int i=min(num1,num2);i>0;i--)     //i=abs(num1-num2) 
    {
        if(num1%i==0 && num2%i==0)
        {
            cout<<"HCF of "<<num1<<" and "<<num2<<" is "<<i;
            break;
        }
    }
}

int main() {
    int n1,n2;
    cin >> n1>>n2;
    hcf(n1,n2);
    return 0;
}

*/


//TC= o(log(min(num1,num2)))
#include<bits/stdc++.h>
using namespace std;

void hcf(int num1,int num2)
{
    while(num1>0 && num2>0)
    {
        if(num1>num2) num1=num1%num2;
        else num2=num2%num1;
        if(num1==0) cout<<num2;
        if(num2==0) cout<<num1;
    }
}

int main() {
    int n1,n2;
    cin >> n1>>n2;
    hcf(n1,n2);
    return 0;
}

