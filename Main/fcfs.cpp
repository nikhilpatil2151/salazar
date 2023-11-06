#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cout<<"Enter the No of Process : ";
    cin>>n;

    int bt[n];
    cout<<"Enter BT : ";
    for(int i=0;i<n;i++){
        cin>>bt[i];
    }

    int at[n];
    cout<<"Enter AT : ";
    for(int i=0;i<n;i++){
        cin>>at[i];
    }

    // findCT(bt,at,n);
    int ct[n],x=0;
    x=bt[0]+at[0];
    for(int i=0;i<n;i++){
        ct[i]=x;
        x=bt[i+1]+x;

    }

    cout<<"CT : ";

    for(int i=0;i<n;i++){
        cout<<ct[i]<<" ";
    }
    cout<<endl;
    cout<<"Bt : ";

    int tat[n];
    for(int i=0;i<n;i++){

        tat[i]=ct[i]-at[i];
        cout<<tat[i]<<" ";
    }

    cout<<endl;
    cout<<"Wt : ";
    int wt[n];
    for(int i=0;i<n;i++){
        wt[i]=tat[i]-bt[i];
        cout<<wt[i]<<" ";
    }

    cout<<endl;

    float avg_tat=0;
    for(int i=0;i<n;i++){
        avg_tat+=tat[i];
    }

    cout<<"Avg TAT : "<<avg_tat/n;
    cout<<endl;

    float avg_wt=0;
    for(int i=0;i<n;i++){
        avg_wt+=wt[i];
    }

    cout<<"Avg WT : "<<avg_wt/n;

}
