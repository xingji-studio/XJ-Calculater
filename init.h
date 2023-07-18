// This is the start of the program
//

#include <sys/stat.h>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <stdio.h>
using namespace std;

const long long N = 1e8 + 5; // 数据上限
// 素数推演存储
short Prime[13] = {12, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}; // 打表，init
// 注意，该数组只用于创建时的
long long MaxInCal = 40;                                                                                                                       // 当前最大值
bool isPrime[N] = {0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0}; // 打表，init，运算
vector<long long> primes;                                                                                                                      // 素数运行，关闭时存储
//int mPF[N] = {0, 0, 0, 0, 2, 0, 2, 0, 2, 3, 2, 0, 2, 0, 2, 3, 2, 0, 2, 0, 2, 3, 2, 0, 2, 5, 2, 3, 2, 0, 2, 0, 2, 3, 2, 5, 2, 0, 2, 3, 2};      // 最小质因数->欧拉筛法，关闭后存储


void simple_init()
{
    
}


bool isthere(const std::string &name)
{
    struct stat buffer;
    return (stat(name.c_str(), &buffer) == 0);
}

int whichsys() // 系统类型
{
#ifdef _WIN32
    cout << "Windows";
    return 1;
#elif __linux__
    cout << "Linux";
    return 2;
#elif __APPLE__
    cout << "Apple";
    return 3;
#endif
}
int init()
{
    if (isthere("data.txt")) // 输入data.txt
    {
        int temp = whichsys();
        switch (temp)
        {
        case 1:
        {
            cout << "Warning: system Microsoft Windows(c) is not available" << endl;
            return 2;
            break;
        }
        case 2:
        {
            freopen("./data.txt", "r", stdin);
            int t;           // push_back primes
            cin >> MaxInCal; // 仅作temp
            for (int i = 1; i <= MaxInCal; i++)
            {
                cin >> t;
                primes.push_back(t);
            }
            cin >> MaxInCal;
            for (int i = 1; i <= MaxInCal; i++)
            {
                cin >> isPrime[i];
            }
            /*for (int i = 1; i <= MaxInCal; i++)
            {
                cin >> mPF[i];
            }*/
            fclose(stdin); // linux下输入保存数据
            return 0;
            break;
        }
        case 3:
        {
            cout << "Warning: system APPLE MacOs(c) is not available" << endl;
            // return 1;
            return 2;
        }
        default:
        {
            cout << "System Error!We couldn't know your system and create files\n";
            cout << "However you could use the calculater while it might be very SLOW.";
            return 2;
        }
        }
    }
    else // 创建并初始化
    {
        int temp = whichsys();
        switch (temp)
        {
        case 1:
        {
            cout << "Warning: system Microsoft Windows(c) is not available" << endl;
            // system("md data.txt");
            // freopen(".\\data.txt","w",stdout);
            return 2;
            break;
        }
        case 2:
        {
            system("touch data.txt");
            freopen("./data.txt", "w", stdout);
            cout << Prime[0] << endl;
            for (int i = 1; i <= Prime[0]; i++)
            {
                cout << Prime[i] << ' ';
            }
            cout << '\n';
            cout << MaxInCal << endl;
            for (int i = 1; i <= MaxInCal; i++)
            {
                cout << isPrime[i] << ' ';
            }
            cout << endl;
            /*for (int i = 1; i <= MaxInCal; i++)
            {
                cout << mPF[i] << ' ';
            }*/
            fclose(stdout); // linux下data.txt初始化
            break;
        }
        case 3:
        {
            cout << "Warning: system APPLE MacOs(c) is not available" << endl;
            // cout << "You should create an new text called data.txt" << endl;
            // cout << "请你在本程序所在文件夹内创建名为data.txt的文件"<< endl;
            // cout << "Warning:"
            // return 1;
            return 2;
        }
        default:
        {
            cout << "System Error!We couldn't know your system and create files\n";
            cout << "However you could use the calculater while it might be very SLOW.";
            return 2;
        }
        }
        init();
    }
    return 0;
}

int save()
{
    cout << "Could you want to exit? Your results won't save but calculater will save some things." << endl;
    cout << "If so, please press(s/n/q)\n";
    cout << "    s for quit and save\n";
    cout << "    n for not to quit\n";
    cout << "    q for quit without save\n";


    {
        char in;
        cout << endl;
        cin >> in;
        if (in == 's' or in == 'S')
        {
            if (isthere("data.txt")) // 输入data.txt
            {
                int temp = whichsys();
                switch (temp)
                {
                case 1:
                {
                    cout << "Warning: system Microsoft Windows(c) is not available" << endl;
                    cout << "However you could try quit without save.";
                    return 2;
                    break;
                }
                case 2:
                {
                    freopen("./data.txt", "w", stdout);
                    for (int i = 1; i <= primes.size(); i++)
                    {
                        cout << primes[i] << ' ';
                    }
                    cout <<  MaxInCal;
                    for (int i = 1; i <= MaxInCal; i++)
                    {
                        cout << isPrime[i];
                    }
                    /*cout << endl;
                    for (int i = 1; i <= MaxInCal; i++)
                    {
                        cout << mPF[i];
                    }*/
                    fclose(stdout); // linux下输入保存数据
                    return 0;
                }
                case 3:
                {
                    cout << "Warning: system APPLE MacOs(c) is not available" << endl;
                    cout << "However you could try quit without save.";
                    // return 1;
                    return 2;
                    break;
                }
                default:
                {
                    cout << "System Error!We couldn't know your system and save files\n";
                    cout << "However you could try quit without save.";
                    return 2;
                }
                }
            }
            else
            {
                cout << "Error:Can't find data.txt\n";
                cout << "Could you create a file called data.txt and try again?";
                return 2;
            }
            return 0;
        }
    }
    return 0;
}