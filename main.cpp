#include "number.h"
#include "config.h"

void debug();

int main()
{
    /*if(init())
    {
        cout << "Error init!";
    }*/  //bug
    //in init.h
    //



    while(1)
    debug();


    //
    //save(); //bug
    return 0;
}

void debug()
{
    long long n;
    cin >> n;
    long long t=unsquare(n);
    long long temp=t;
    short s=0;
    while(1)
    {
        if(temp == 0)
            break;
        temp = temp / 10;
        s++;
    }
    for (short i=1;i<=s;i++)
        cout << ' ';
    cout << " ________\n";
    cout << t << "/" << n / t / t << endl;
    //findprime(1000000);
    /*
    num x;
    x.up=100;
    x.down=81;
    x.out_put();*/
}
