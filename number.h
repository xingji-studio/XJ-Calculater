#include <iostream>
#include "init.h"
#include <math.h>
using namespace std;
// 以分数的平方形式储存所有数据

void findprime(long long n);

long long unsquare(long long n);

struct num
{
    int up[N_num] = {0,0,0};
    int down[N_num] = {1,1,0};//0号表示最大值，1~n表示根号i的个数

    void simple()
    {
        
    }

    void out_put()
    {
        
    }

    
    num operator+(const num &n)
    {
        num ans;//here ans作为过程量
        num result;

        result.down[0]=0;
        result.down[1]=0;

        //copy "division"
        ans.down[0]=0;
        ans.down[1]=0;
        int temp,temp1,temp2;
        for (int i=1;i<=up[0];i++)
            {   
                if(up[i]==0) continue;
                for(int j=1;j<=n.down[0];j++)
                {
                    if(n.down[j]==0)continue;
                    temp=up[i]*up[i]*i*n.down[j]*n.down[j]*j;
                    temp1=unsquare(temp);
                    temp2=temp/temp1/temp1;
                    ans.up[temp2]+=temp1;
                    if(ans.up[0]<=temp2) ans.up[0]=temp2;
                }
            }
        for (int i=1;i<=down[0];i++)
            {   
                if(down[i]==0) continue;
                for(int j=1;j<=n.up[0];j++)
                {
                    if(n.up[j]==0) continue;
                    temp=down[i]*down[i]*i*n.up[j]*n.up[j]*j;
                    temp1=unsquare(temp);
                    temp2=temp/temp1/temp1;
                    ans.down[temp2]+=temp1;
                    if(ans.down[0]<=temp2) ans.down[0]=temp2;
                }
            } //a/b+c/d=(ad+bc)/bd 此处ans up->ad down->bc
        
        if(ans.up[0] >= ans.down[0])
            result.up[0]=ans.up[0];
        else
            result.up[0]=ans.down[0];
        for (int i=1;i<=result.up[0];i++)
            {
                result.up[i]=ans.up[i]+ans.down[i];
            }
        
        for (int i=1;i<=down[0];i++)
            {   
                if(down[i]==0) continue;
                for(int j=1;j<=n.down[0];j++)
                {
                    if(n.down[j]==0) continue;
                    temp=down[i]*down[i]*i*n.down[j]*n.down[j]*j;
                    temp1=unsquare(temp);
                    temp2=temp/temp1/temp1;
                    result.down[temp2]+=temp1;
                    if(result.down[0]<=temp2) result.down[0]=temp2;
                }
            }

        Log_layout("kernel","Cal add completed",5);
        Log_layout("kernel","Cal add 求得的结果没有进行化简",1);
        return result;
    }
    num operator-(const num &n)
    {
        num ans;//here ans作为过程量
        num result;

        result.down[0]=0;
        result.down[1]=0;

        //copy "division"
        ans.down[0]=0;
        ans.down[1]=0;
        int temp,temp1,temp2;
        for (int i=1;i<=up[0];i++)
            {   
                if(up[i]==0) continue;
                for(int j=1;j<=n.down[0];j++)
                {
                    if(n.down[j]==0)continue;
                    temp=up[i]*up[i]*i*n.down[j]*n.down[j]*j;
                    temp1=unsquare(temp);
                    temp2=temp/temp1/temp1;
                    ans.up[temp2]+=temp1;
                    if(ans.up[0]<=temp2) ans.up[0]=temp2;
                }
            }
        for (int i=1;i<=down[0];i++)
            {   
                if(down[i]==0) continue;
                for(int j=1;j<=n.up[0];j++)
                {
                    if(n.up[j]==0) continue;
                    temp=down[i]*down[i]*i*n.up[j]*n.up[j]*j;
                    temp1=unsquare(temp);
                    temp2=temp/temp1/temp1;
                    ans.down[temp2]+=temp1;
                    if(ans.down[0]<=temp2) ans.down[0]=temp2;
                }
            } //a/b-c/d=(ad-bc)/bd 此处ans up->ad down->bc
        
        if(ans.up[0] >= ans.down[0])
            result.up[0]=ans.up[0];
        else
            result.up[0]=ans.down[0];
        for (int i=1;i<=result.up[0];i++)
            {
                result.up[i]=ans.up[i]-ans.down[i];
            }
        
        //检查result.up最大值处是否减为0
        while (1)
        {
            if(result.up[result.up[0]]==0) result.up[0]--;
            else break;
        }

        for (int i=1;i<=down[0];i++)
            {   
                if(down[i]==0) continue;
                for(int j=1;j<=n.down[0];j++)
                {
                    if(n.down[j]==0) continue;
                    temp=down[i]*down[i]*i*n.down[j]*n.down[j]*j;
                    temp1=unsquare(temp);
                    temp2=temp/temp1/temp1;
                    result.down[temp2]+=temp1;
                    if(result.down[0]<=temp2) result.down[0]=temp2;
                }
            }

        Log_layout("kernel","Cal minus completed",5);
        Log_layout("kernel","Cal minus 求得的结果没有进行化简",1);
        return result;
    }
    num operator*(const num &n)
    {
        num ans;
        ans.down[0]=0;
        ans.down[1]=0;
        int temp,temp1,temp2;
        for (int i=1;i<=up[0];i++)
            {   
                if(up[i]==0) continue;
                for(int j=1;j<=n.up[0];j++)
                {
                    if(n.up[j]==0)continue;
                    temp=up[i]*up[i]*i*n.up[j]*n.up[j]*j;
                    temp1=unsquare(temp);
                    temp2=temp/temp1/temp1;
                    ans.up[temp2]+=temp1;
                    if(ans.up[0]<=temp2) ans.up[0]=temp2;
                }
            }
        for (int i=1;i<=down[0];i++)
            {   
                if(down[i]==0) continue;
                for(int j=1;j<=n.down[0];j++)
                {
                    if(n.down[j]==0) continue;
                    temp=down[i]*down[i]*i*n.down[j]*n.down[j]*j;
                    temp1=unsquare(temp);
                    temp2=temp/temp1/temp1;
                    ans.down[temp2]+=temp1;
                    if(ans.down[0]<=temp2) ans.down[0]=temp2;
                }
            }
        Log_layout("kernel","Cal multiply completed",5);
        Log_layout("kernel","Cal multiply 求得的结果没有进行化简",1);
        return ans;
    }
    num operator/(const num &n)
    {
        num ans;
        ans.down[0]=0;
        ans.down[1]=0;
        int temp,temp1,temp2;
        for (int i=1;i<=up[0];i++)
            {   
                if(up[i]==0) continue;
                for(int j=1;j<=n.down[0];j++)
                {
                    if(n.down[j]==0)continue;
                    temp=up[i]*up[i]*i*n.down[j]*n.down[j]*j;
                    temp1=unsquare(temp);
                    temp2=temp/temp1/temp1;
                    ans.up[temp2]+=temp1;
                    if(ans.up[0]<=temp2) ans.up[0]=temp2;
                }
            }
        for (int i=1;i<=down[0];i++)
            {   
                if(down[i]==0) continue;
                for(int j=1;j<=n.up[0];j++)
                {
                    if(n.up[j]==0) continue;
                    temp=down[i]*down[i]*i*n.up[j]*n.up[j]*j;
                    temp1=unsquare(temp);
                    temp2=temp/temp1/temp1;
                    ans.down[temp2]+=temp1;
                    if(ans.down[0]<=temp2) ans.down[0]=temp2;
                }
            }
        Log_layout("kernel","Cal division completed",5);
        Log_layout("kernel","Cal division 求得的结果没有进行化简",1);
        return ans;
    }
};


long long unsquare(long long n)
{
    if(n==1) return 1;
    findprime(n);
    long long ans, m = n;
    ans = 1;
    // int i=mPF[n];
    int p = 0;
    int i;
    for (int pos = 0;; pos++)
    {
        p = 0;
        i = primes[pos];
        if (m <= i)
        {
            break;
        }
        while (1)
        {
            if (m % i == 0)
            {
                m = m / i;
                p++;
            }
            else
            {
                break;
            }
            if (p % 2 == 0 and p != 0)
            {
                ans = ans * i;
            }
        }
    }
    return ans;
    /*while (1)
        {
            if(m % i==0)
                {
                    m = m/i;
                    p++;
                }
            if(p % 2 == 0 and p != 0)
                {
                    ans = ans * i;
                }
        }*/
}

void findprime(long long n)
{
    if (n <= MaxInCal)
        return;
    if (n==1) n=10,cout << "prime search:turn 1 to 10";
    cout << "run prime searching" << endl;
    for (int i = 1; i <= n; i++) // 欧拉筛法
        isPrime[i] = true;

    for (int i = 2; i <= n; i++)
    {
        if (isPrime[i])
            primes.push_back(i);
        for (int j = 0; j < primes.size(); j++)
        {
            int p = primes[j];
            if (i * p > n)
                break;
            isPrime[i * p] = false;
            // mPF[i * p] = p;
            if (i % p == 0)
                break;
        }
    }
    MaxInCal = n;
    /*cout << primes.size() << endl;
    for (int i = 0; i < primes.size(); i++)
        printf("%d ", primes[i]);
    for (int i = 1; i <= n; i++)
    {
        cout << isPrime[i] << ",";
    }
    cout << '\n';
    for (int i = 1; i <= n; i++)
    {
        cout << mPF[i] << ",";
    }*/
}