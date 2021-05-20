#include<iostream>
#include<string>
#include<thread>
#include<cstdlib>
#include<ctime>
#include<chrono>

const int width=100;

const int flipsPerLine=5;

const int sleepTime=100;

using namespace std;

int main()
{
    int i=0,x=0;
    srand(time(NULL));

    bool switches[width]={0};

    const string ch="1234567890qwertyuiopasdfghjklzxcvbnm,./';[]!@#$%^&*()-=_+";
    const int l=ch.size();

    system("Color 0A");

    while(true)
    {
        for(i=0;i<width;i+=2)
        {
            if(switches[i])
                cout<<ch[rand()%l]<<" ";
            else
                cout<<"  ";
        }
        for(i=0;i!=flipsPerLine;++i)
        {
            x=rand()%width;
            switches[x]= !switches[x];
        }
        cout<<endl;
        this_thread::sleep_for(chrono::milliseconds(sleepTime));
    }

    return 0;
}
