//XJ-Normal-apps logengine
//It has nothing to do with XJ380OS
//
//in order to debug, write this
//writer:___
//Warning: Language:C++

#include <iostream>
using namespace std;


void Log_layout(string from,string out,int level)
{
    switch(level)
    {
        case 0:{
            cout << "\033[31mError:";
            break;
        }
        case 1:{
            cout << "\033[33mWarning:";
            break;
        }
        default:{
            cout << "Normal:";
        }
    }
    cout << ' '<< from << ' ' << out << endl;
    cout << "\033[0m";
}