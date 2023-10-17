#include "stdafx.h"
#include <iostream>
#include <time.h>

using namespace std;

int _tmain(int argc, _TCHAR* argv[]){
    int b[10][10];
    int i,j,k;
    srand(time(NULL));
    for(i=0;i<9;i++){
        for (j=0;j<9;j++){
            b[i][j]=rand()%21-10;
            cout<<b[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"k=";
    cin>>k;
    for(i=0;i<9;i++)
        for (j=0;j<9;j++)
            if (b[i][j]>k) 
                cout<<b[i][j]<<"\t";
    cout<<endl;
    system("pause");
    return 0;
}