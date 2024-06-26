#include <stdio.h>
#include <iostream>
#include <stdlib.h>

#define MAX 20

using namespace std;

int frequencyTable[MAX] = {0};
int queue[MAX];
int front=-1, rear=-1;

int isFull(int nFrames)
{
    if (rear-front+1 == nFrames)
    return 1;
    else
    return 0;
}

void enqueue(int i)
{
    if (front == -1)
    front++;
    queue[++rear] = i;
}

int peek()
{
    return queue[front];
}

void dequeue(int i)
{
    for (int j=i; j>front; j--)
    {
        queue[i] = queue[i-1];
    }
    front++;
}

int findElement(int currentState[], int nFrames)
{
    int leastFrequentElements[nFrames];
    int minFrequency = 99;
    for (int i=0; i< nFrames; i++)
    {
        if (frequencyTable[currentState[i]] < minFrequency)
        minFrequency = frequencyTable[currentState[i]];
    }
    // cout << endl << "Min Frequency: " << minFrequency;
    int k=0;
    for (int i=0; i< nFrames; i++)
    {
        if (frequencyTable[currentState[i]] == minFrequency)
        leastFrequentElements[k++] = currentState[i];
    }
    // cout << endl;
    // for (int i=0; i< k; i++)
    // {
    //     cout << leastFrequentElements[i] << "     ";
    // }
    // cout << endl;
    for (int j=front; j<=rear; j++)
    {
        for (int i=0; i<k; i++)
        {
            if (queue[j] == leastFrequentElements[i])
            {
                int ele = queue[j];
                // cout << endl<<"Element" << queue[j];
                dequeue(j);
                
                return ele;
            } 
        }
    }
}

int findIndex(int currentState[], int n, int nFrames)
{
    for (int i=0; i< nFrames; i++)
    {
        if (currentState[i] == n)
        return i;
    }
}

int inCurrentState(int currentState[], int n, int nFrames)
{
    for (int i=0; i< nFrames; i++)
    {
        if (currentState[i] == n)
        return 1;
    }
    return 0;
}

void LeastFrequentlyUsed(int nFrames, int nPages, int pages[])
{
    int currentState[nFrames];
    for(int i=0; i<nFrames; i++)
    currentState[i] = 999;
    int toBeReplacedIndex, toBeReplacedElement, nHits = 0, lastIndex = 0;
    int memory[nFrames][nPages];

    for (int i=0; i< nPages; i++)
    {
        // cout<<endl<<endl;
        // cout<<"State:"<<endl;
        // for (int i=0; i< nFrames; i++)
        // {
        //     cout << currentState[i] << " ";
        // }
        // cout<<endl<<endl;
        frequencyTable[pages[i]]++;
        if (isFull(nFrames))
        {
            if (!inCurrentState(currentState, pages[i], nFrames))
            {
                toBeReplacedElement = findElement(currentState, nFrames);
                toBeReplacedIndex = findIndex(currentState, toBeReplacedElement ,nFrames);
                frequencyTable[toBeReplacedElement] = 0;
                enqueue(pages[i]);
                currentState[toBeReplacedIndex] = pages[i];
            }
            else
            nHits++;
        }
        else
        {
            if (!inCurrentState(currentState, pages[i], nFrames))
            {
                enqueue(pages[i]);
                currentState[lastIndex++] = pages[i];
            }
            else
            nHits++;
        }
        for(int j=0; j<nFrames; j++)
        {
            memory[j][i] = currentState[j];
        }
    //     for(int i=0; i<MAX; i++){
    //         if(frequencyTable[i]!=0)
    //         // cout << i <<  " : " << frequencyTable[i] << endl; 
    //     }
    //     for(int i=front;i<=rear;i++)
    //     // cout<<queue[i]<< " ";
    //     cout<<endl;
    }

    cout << endl << "---------------------------------------" << endl << endl;
    cout << "Pages ->";
    for (int i=0; i<nPages; i++)
    cout << "     " << pages[i];
    for (int i=0; i<nFrames; i++)
    {
        cout << endl;
        cout << "Frame " << i+1 << " ";
        for (int j=0; j<nPages; j++)
        {
            int output = memory[i][j];
            if (output == 999)
            cout << "     " << "-";
            else
            cout << "     " << output;
        }
        
    }
    float hitPercent = float(nHits)/ float(nPages);
    cout << endl << endl << "---------------------------------------" << endl << endl;
    cout << "Number of hits : " << nHits << endl;
    cout << "Number of misses : " << nPages - nHits << endl;
    cout << "Hit percentage : " << hitPercent;
}

int main()
{
    int nFrames, nPages;
    cout << "Enter the number of frames: ";
    cin >> nFrames;
    cout << "Enter the number of pages: ";
    cin >> nPages;
    int pages[nPages];
    cout << endl << "Enter the pages: " << endl;
    for (int i=0; i< nPages; i++)
    {
        cin >> pages[i];
     }
    // int nFrames=3, nPages=12;
    // int pages[15] = {6, 7, 8, 9, 6, 7, 1, 6, 7, 8, 9, 1};
    LeastFrequentlyUsed(nFrames, nPages, pages);
    return 0;
}