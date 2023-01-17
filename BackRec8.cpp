#include "pt4.h"
using namespace std;

void research(int* arr, int n, int z, int* MassOfTwice, int* MassOfNumOld, int SumOfNumOld, int CountOld )
{
    bool Flag = FALSE;
    for (int i = 0; i < n; i++)
    {
        if (MassOfTwice[i] == 0)
        {
            Flag = TRUE;          /*проверка на подобную ситуацию 11111*/
            break;
        }
    }

    if (Flag == TRUE)
    {
        MassOfTwice[n - 1] += 1;
        for (int i = n - 1; i >= 0; i--)      /*увеличение двоичного параметра на 1*/
        {
            if (MassOfTwice[i] == 2)
            {
                MassOfTwice[i] = 0;
                MassOfTwice[i - 1] += 1;
            }
        }

        int SumOfNum = 0, Count = 0, MassOfNum[10] = {}, k = 0;

        for (int i = 0; i < n; i++)
        {
            if (MassOfTwice[i] == 1)   /*заполняем массив (возможно верных) чисел, согласно двоичному числу*/
            {
                SumOfNum += arr[i];
                Count += 1;
                MassOfNum[k] = arr[i];
                k++;
            }
        }

        if (SumOfNum > z) /*проверка условий*/
        {
            if (SumOfNumOld == 0 && CountOld == 0) research(arr, n, z, MassOfTwice, MassOfNum, SumOfNum, Count);
            if (SumOfNum < SumOfNumOld) research(arr, n, z, MassOfTwice, MassOfNum, SumOfNum, Count);
            if (SumOfNum > SumOfNumOld ) research(arr, n, z, MassOfTwice, MassOfNumOld, SumOfNumOld, CountOld);
            if (SumOfNum == SumOfNumOld)
                if (Count < CountOld) research(arr, n, z, MassOfTwice, MassOfNum, SumOfNum, Count);
                else if (Count > CountOld && CountOld != 0) research(arr, n, z, MassOfTwice, MassOfNumOld, SumOfNumOld, CountOld);
        }
        else research(arr, n, z, MassOfTwice, MassOfNumOld, SumOfNumOld, CountOld);

    }
    else for (int i = 0; i < CountOld; i++) pt << MassOfNumOld[i];
}
void Solve()
{
    Task("BackRec8");

    int n, z, Mass[100];

    pt >> n >> z;

    for (int i = 0; i < n; i++)
    {
        pt >> Mass[i];
    }

    int *MassOfTwice = new int[n];
    for (int i = 0; i < n; i++)
    {
        MassOfTwice[i] = 0;
    }
    
    int arr[10] = {};
    research(Mass,n,z,MassOfTwice,arr,0,0);

    delete[n] MassOfTwice;
}
