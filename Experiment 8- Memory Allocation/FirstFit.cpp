#include <stdio.h>
#include <iostream>
#include <stdlib.h>

#define MAX 10

using namespace std;

int totalMemory=0, totalConsumed=0;

struct process
{
    int value;
    int isAllocated = 0;
};

struct memory
{
    int value;
    int isEmpty = 1;
    int processNumber = 999;
};

struct memory m[MAX];
struct process p[MAX];

void FirstFit(int nBlocks, int nProcesses)
{
    for (int i=0; i< nProcesses; i++)
    {
        for (int j=0; j< nBlocks; j++)
        {
            if (m[j].isEmpty && m[j].value >= p[i].value)
            {
                m[j].processNumber = i;
                m[j].isEmpty = 0;
                p[i].isAllocated = 1;
                break;
            }
        }
    }
}

void printResults(int nBlocks, int nProcesses)
{
    cout << endl << endl << "The memory blocks at the end of allocation are:" << endl;
    for (int i=0; i< nBlocks; i++)
    {
        cout << m[i].value << "  ---->  ";
        if (m[i].isEmpty)
        cout << "Empty Block" << endl;
        else if (!m[i].isEmpty)
        {
            cout << "P" << m[i].processNumber << " (" << p[m[i].processNumber].value << ")" << endl;
        }
    }
    cout << endl << endl << "The non - allocated processes are:" << endl;
    for (int i=0; i< nProcesses; i++)
    {
        if (!p[i].isAllocated)
        cout << "P" << i << " (" << p[i].value << ")" << endl;
        else
        totalConsumed += p[i].value;
    }
    float perc = float(totalConsumed)/float(totalMemory);
    cout << endl << "---------------------------------------" << endl << endl;
    cout << "Total Memory: " << totalMemory << endl;
    cout << "Consumed Memory: " << totalConsumed << endl;
    cout << "Consumed Memory Percentage: " << perc*100 << "%";
}

int main()
{
    cout << "Vineet Shenvi    60004220012    C182" << endl << endl;
    int nBlocks, nProcesses;
    cout << "Enter the number of memory blocks: ";
    cin >> nBlocks;
    cout << "Enter the number of processes: ";
    cin >> nProcesses;
    cout << endl << "Enter the memory blocks: " << endl;
    for (int i=0; i< nBlocks; i++)
    {
        cin >> m[i].value;
    }
    cout << endl << "Enter the processes: " << endl;
    for (int i=0; i< nProcesses; i++)
    {
        cin >> p[i].value;
    }
    cout << endl << "The memory is: " << endl;
    for (int i=0; i< nBlocks; i++)
    {
        cout << m[i].value << "    ";
        totalMemory += m[i].value;
    }
    cout << endl << endl << "The processes are: " << endl;
    for (int i=0; i< nProcesses; i++)
    {
        cout << p[i].value << "    ";
    }
    FirstFit(nBlocks, nProcesses);
    printResults(nBlocks, nProcesses);
    return 0;
}