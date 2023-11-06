#include<bits/stdc++.h> 
using namespace std;


int main()
{
    int pageFaults = 0;
    int frames;
    int m, n, s, pages;

    cout<<"Enter Size of Incoming-Stream : ";
    cin>>pages;    
    int incomingStream[pages];

    cout<<endl;
    cout<<"Enter the values of incoming stream : ";
    for(int i=0;i<pages;i++){

        cin>>incomingStream[i];
    }

    cout<<endl;
    cout<<"Enter the size of Frame : ";
    cin>>frames;

    // pages = sizeof(incomingStream)/sizeof(incomingStream[0]);

    printf("Incoming \t Frame 1 \t\t\t Frame 2 \t\t\t Frame 3");
    int temp[frames];
    for(m = 0; m < frames; m++)
    {
        temp[m] = -1;
    }

    for(m = 0; m < pages; m++)
    {
        s = 0;

        for(n = 0; n < frames; n++)
        {
            if(incomingStream[m] == temp[n])
            {
                s++;
                pageFaults--;
            }
        }
        pageFaults++;
        
        if((pageFaults < frames) && (s == 0))
        {
            temp[m] = incomingStream[m];
        }
        else if(s == 0)
        {
            temp[(pageFaults - 1) % frames] = incomingStream[m];
        }
      
        printf("\n");
        printf("%d\t\t\t",incomingStream[m]);
        for(n = 0; n < frames; n++)
        {
            if(temp[n] != -1)
                printf(" %d\t\t\t", temp[n]);
            else
                printf(" - \t\t\t");
        }
    }

    printf("\nTotal Page Faults:\t%d\n", pageFaults);
    return 0;
}