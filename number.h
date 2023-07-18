#include <iostream>
#include "init.h"
#include <math.h>
using namespace std;
// 以分数的平方形式储存所有数据

void findprime(long long n);

long long unsquare(long long n);

struct num
{
    int up[N] = {0,0};
    int down[N] = {1,1};//0号表示最大值，1~n表示n的个数

    void simple()
    {
        
    }

    void out_put()
    {
        
    }

    
    num operator+(const num &n)
    {
        num ans;
        return ans;
    }
    num operator-(const num &n)
    {
        num ans;
        return ans;
    }
    num operator*(const num &n)
    {
        num ans;
        return ans;
    }
    num operator/(const num &n)
    {
        num ans;
        return ans;
    }
};


long long unsquare(long long n)
{
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
    cout << "run searching" << endl;
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