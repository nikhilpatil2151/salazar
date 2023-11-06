#include <bits/stdc++.h>
using namespace std;
int checkHit(int incomingPage, int queue[], int occupied) {
    for (int i = 0; i < occupied; i++) {
        if (incomingPage == queue[i])
            return 1;
    }
    return 0;
}

void printFrame(int queue[], int occupied) {
    for (int i = 0; i < occupied; i++)
        cout << queue[i] << "\t\t\t";
        
}

int main() {

    int n;
    cout<<"Enter the size of Incoming stream : ";
    cin>>n;
    cout<<endl;
    
    int incomingStream[n];


    cout<<"Enter the values of stream : ";


    for(int i=0;i<n;i++){
        cin>>incomingStream[i];
    } 

    cout<<endl;

    cout<<"Enter Frame size : ";
    int frames;
    cin>>frames;
    cout<<endl;
    // = {1, 2, 3, 2, 1, 5, 2, 1, 6, 2, 5, 6, 3, 1, 3};
    // int n = sizeof(incomingStream) / sizeof(incomingStream[0]);

    int queue[frames];
    int distance[frames];
    int occupied = 0;
    int pagefault = 0;

    cout << "Page\t Frame1 \t Frame2 \t Frame3\n";

    for (int i = 0; i < n; i++) {
        cout << incomingStream[i] << ":  \t\t";

        if (checkHit(incomingStream[i], queue, occupied)) {
            printFrame(queue, occupied);
        } else if (occupied < frames) {
            queue[occupied] = incomingStream[i];
            pagefault++;
            occupied++;
            printFrame(queue, occupied);
        } else {
            int max = INT_MIN;
            int index;
            for (int j = 0; j < frames; j++) {
                distance[j] = 0;
                for (int k = i - 1; k >= 0; k--) {
                    ++distance[j];
                    if (queue[j] == incomingStream[k])
                        break;
                }
                if (distance[j] > max) {
                    max = distance[j];
                    index = j;
                }
            }
            queue[index] = incomingStream[i];
            printFrame(queue, occupied);
            pagefault++;
        }
        cout << endl;
    }

    cout << "Page Fault: " << pagefault;

    return 0;
}