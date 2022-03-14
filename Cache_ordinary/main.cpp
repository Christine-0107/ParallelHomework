#include <iostream>
#include <windows.h>
using namespace std;

int a[10000];
int b[10000][10000];
int sum[10000];
int main()
{
    cout<<"Normal Algorithm"<<endl;
    int step=10;
    for(int N=0;N<=10000;N+=step){
        for(int i=0;i<N;i++){
            a[i]=i;
            for(int j=0;j<N;j++){
                b[i][j]=i+j;
            }
        } //initialize
        long long head,tail,freq;
        long counter;
        if(N<=30)
            counter=10000;
        else if(N>30&&N<=100)
            counter=1000;
        else if(N>100&&N<=1000)
            counter=100;
        else if(N>1000&&N<=5000)
            counter=10;
        else
            counter=1;
        long c=counter;
        QueryPerformanceFrequency((LARGE_INTEGER*)&freq);
        QueryPerformanceCounter((LARGE_INTEGER*)&head);
        while(c>0){
            c--;
            for(int i=0;i<N;i++){
                sum[i]=0;
                for(int j=0;j<N;j++){
                    sum[i]+=b[j][i]*a[j];
                }
            }/*Normal algorithm*/
        }
        QueryPerformanceCounter((LARGE_INTEGER*)&tail);
        double time=(tail-head)*1000/freq;
        cout<<N<<" "<<counter<<" "<<time<<"ms "<<time/counter<<"ms"<<endl;

        if(N==100){
            step=100;
        }
        if(N==1000){
            step=1000;
        }

    }
    return 0;
}
