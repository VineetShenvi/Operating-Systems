#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;
#define MAX 10

int sequence[MAX];
int top = -1;

void push(int i)
{
    sequence[++top] = i;
}

    // int available[3] ={3, 3, 2};
    
    // int allocationMatrix[10][10]={
    //     {0, 1, 0},
    //     {2, 0, 0},
    //     {3, 0, 2},
    //     {2, 1, 1},
    //     {0, 0, 2}
    // };

    // int maxMatrix[10][10]={
    //     {7, 5, 3},
    //     {3, 2, 2},
    //     {9, 0, 2},
    //     {2, 2, 2},
    //     {4, 3, 3}
    // };

    // int needMatrix[MAX][MAX];

void printMatrix(int nProcesses, int nResources, int Matrix[MAX][MAX])
{
    for(int i=0; i<nProcesses; i++)
    {
        for(int j=0; j<nResources; j++)
        {
            cout << Matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int checkProcess(int process, int nResources, int available[], int needMatrix[MAX][MAX])
{
    int zeroFlag = 0;
    for(int i=0; i<nResources; i++)
    {
        if(needMatrix[process][i] != 0)
        {
            zeroFlag++;
            break;
        }
    }
    if(!zeroFlag)
    return 0;
    for(int i=0; i<nResources; i++)
    {
        if(needMatrix[process][i] > available[i])
        {
            return 0;
        }
    }
    return 1;
}

int allocation(int nProcesses, int nResources, int available[], int needMatrix[MAX][MAX])
{
    for(int i=0; i<nProcesses; i++)
    {
        if (checkProcess(i, nResources, available, needMatrix))
        {
            return i;
        }
    }
    return -1;
}

int operation(int process, int nProcesses, int nResources, int available[], int allocationMatrix[MAX][MAX] ,int needMatrix[MAX][MAX])
{
    for(int i=0; i< nResources; i++)
    {
        needMatrix[process][i] -= needMatrix[process][i];
        

        available[i] += allocationMatrix[process][i];
    }
    // cout << endl;
    //     printMatrix(nProcesses, nResources, needMatrix);
}

void bankersAlgorithm(int nProcesses, int nResources, int available[], int needMatrix[MAX][MAX], int allocationMatrix[MAX][MAX])
{
    int process=1;
    while(1)
    {
        process = allocation(nProcesses, nResources, available, needMatrix);
        if (process == -1)
        break;
        cout << endl << "Process " << process+1 << " has been allocated." << endl;
        push(process);
        operation(process, nProcesses, nResources, available, allocationMatrix, needMatrix);
        cout << endl << "Available Rescources: " << endl;
        for(int i=0; i<nResources; i++)
        {
            cout << available[i] << " ";
        }
        cout << endl;

        cout << endl << "Need matrix: " << endl;
        printMatrix(nProcesses, nResources, needMatrix);
    }
    cout << endl << "Safe Sequence: " << endl;
    for(int i=0; i<=top; i++)
    {
        cout << "P" << sequence[i]+1 << " -> ";
    }
}

void calculateNeedMatrix(int nProcesses, int nResources, int maxMatrix[MAX][MAX], int needMatrix[MAX][MAX], int allocationMatrix[MAX][MAX])
{
    for(int i=0; i<nProcesses; i++)
    {
        for(int j=0; j<nResources; j++)
        {
            needMatrix[i][j] = maxMatrix[i][j]-allocationMatrix[i][j];
        }
    }
}



int main()
{
    cout << "Vineet Shenvi      C182       60004220012" << endl;
    int nProcesses, nResources;
    
    
    cout << "Enter the number of processes: ";
    cin >> nProcesses;

    cout << "Enter the number of types of resources: ";
    cin >> nResources;

    int available[nResources], allocationMatrix[MAX][MAX], maxMatrix[MAX][MAX], needMatrix[MAX][MAX];

    


    cout << "Enter the allocation matrix: " << endl;
    for(int i=0; i<nProcesses; i++)
    {
        cout << "Process " << i+1 << ": ";
        for(int j=0; j<nResources; j++)
        {
            cin >> allocationMatrix[i][j];
        }
    }

    cout << "Enter the max matrix: " << endl;
    for(int i=0; i<nProcesses; i++)
    {
        cout << "Process " << i+1 << ": ";
        for(int j=0; j<nResources; j++)
        {
            cin >> maxMatrix[i][j];
        }
    }

    cout << "Enter the available resources: " << endl;
    for(int i=0; i<nResources; i++)
    {
        cin >> available[i];
    }

    cout << endl << "The enterred matrices: " << endl << endl;
    cout << "Max matrix: " << endl;
    printMatrix(nProcesses, nResources, maxMatrix);

    cout << endl << "Allocation matrix: " << endl;
    printMatrix(nProcesses, nResources, allocationMatrix);

    cout << endl << "Available Rescources: " << endl;
    for(int i=0; i<nResources; i++)
    {
        cout << available[i] << " ";
    }
    cout << endl;

    cout << endl << "Need matrix: " << endl;
    calculateNeedMatrix(nProcesses, nResources, maxMatrix, needMatrix, allocationMatrix);
    printMatrix(nProcesses, nResources, needMatrix);

    // int process = allocation(nProcesses, nResources, available, needMatrix);
    // cout << process;

    bankersAlgorithm(nProcesses, nResources, available, needMatrix, allocationMatrix);

    return 0;
}