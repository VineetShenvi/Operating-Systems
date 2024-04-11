#include <stdio.h>
#include <iostream>
#include <stdlib.h>

#define MAX 20

using namespace std;

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

int dequeue()
{
    return queue[front++];
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

void FirstInFirstOut(int nFrames, int nPages, int pages[])
{
    int currentState[nFrames];
    for(int i=0; i<nFrames; i++)
    currentState[i] = 999;
    int toBeReplacedIndex = 99, nHits = 0, lastIndex = 0;
    int memory[nFrames][nPages];

    for (int i=0; i< nPages; i++)
    {
        if (isFull(nFrames))
        {
            if (!inCurrentState(currentState, pages[i], nFrames))
            {
                toBeReplacedIndex = findIndex(currentState, dequeue(), nFrames);
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
}

int main()
{
    int nFrames, nPages, nProcesses;
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
    FirstInFirstOut(nFrames, nPages, pages);
    return 0;
}