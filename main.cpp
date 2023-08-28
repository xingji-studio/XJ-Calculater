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

    debug();


    //
    //save(); //bug
    return 0;
}

void debug()
{
    num a,b;
    /*
    a.up[0]=3;
    a.up[1]=1;
    a.up[2]=1;
    a.up[3]=1;
    b.up[0]=3;
    b.up[1]=0;
    b.up[2]=0;
    b.up[3]=1;
    */
    cout << "请输入运算符号:+-*/"<<endl;
    char op;
    cin >> op;
    cout << endl;
    cout << "在该版本中，计算数据以以下方式表示\n5\n2 3 4 0 1\n表示最多至根号五\n2*1+3*sqrt(2)+4*sqrt(3)+1*sqrt(5)\n";
    cout << "input a:\n";
    cin >> a.up[0];
    for (int i=1;i<=a.up[0];i++)
        cin >> a.up[i];
    cout << "------------\n";
    cin >> a.down[0];
    for (int i=1;i<=a.down[0];i++)
        cin >> a.down[i];
    cout << "\ninput b:\n";
    cin >> b.up[0];
    for (int i=1;i<=b.up[0];i++)
        cin >> b.up[i];
    cout << "------------\n";
    cin >> b.down[0];
    for (int i=1;i<=b.down[0];i++)
        cin >> b.down[i];
    
    num ans;
    switch(op)
    {
        case '+':{
            ans=a+b;
            break;
        }
        case '-':{
            ans=a-b;
            break;
        }
        case '*':{
            ans=a*b;
            break;
        }
        case '/':{
            ans=a/b;
            break;
        }
        default:{
            cout << "Error";
            return;
        }
    }
//num ans=a-b;

    cout << ans.up[0] << endl;
    for (int i=1;i<=ans.up[0];i++) cout << ans.up[i] << ' ';
    cout << endl << ans.down[0] << endl;
    for (int i=1;i<=ans.down[0];i++) cout << ans.down[i] << ' ';
    /*long long n;
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
    cout << t << "/" << n / t / t << endl;*/
    //findprime(1000000);
    /*
    num x;
    x.up=100;
    x.down=81;
    x.out_put();*/
}
