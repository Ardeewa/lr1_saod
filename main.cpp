#include <QtCore/QCoreApplication>
#include <iostream>
#include <fstream>
#include <time.h>
#include <conio.h>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
#define size 500

/////////////глупая сортировка///////////////////////
/*void stupidSort(int *data, int n)
{
    int i = 0, tmp;
    FILE *f1;
    string in;
    clock_t start = clock();
    while (i < n - 1)
    {
        if (data[i+1] < data[i])
        {
            tmp = data[i];
            data[i] = data[i+1];
            data[i+1] = tmp;
            i = 0;
        }
        else i++;

    }
    cout<<endl;
    clock_t end = clock();
    double sim_sort_Time = double(end - start)/ CLOCKS_PER_SEC;
    cout<<"stupidSort"<<endl;
    cout<<"Time:";
    cout<<sim_sort_Time<<endl;

for(int i=0; i<15; i++)
    {
     cout<<data[i]<<"\t";
}


}

/////Разрядная////////
void radix(int *a, int n, int *br)
{
    int i,k,m,z;
    int max = a[0];

    for (int i = 1; i < n; i++)
            if (a[i] > max)
                    max = a[i];
    int cr[max];
    k = n;
    m = n;
    clock_t start1 = clock();
    for (i = 0; i <= k; i++)
        cr[i]=0;
    for (i = 0; i < m; i++)
        cr[a[i]]+=1;
    for (i = 1; i < k+1; i++)
        cr[i]+=cr[i-1];
    for (i = m-1; i >= 0; i--)
      {
         br[cr[a[i]]-1]=a[i];
         cr[a[i]]-=1;
      }
    cout<<endl;
    clock_t end1 = clock();
    double sim_sort_Time = double(end1 - start1)/ CLOCKS_PER_SEC;
    cout<<"radixSort"<<endl;
    cout<<"Time:";
    cout<<sim_sort_Time<<endl;

for(int i=0; i<15; i++)
    {
     cout<<cr[i]<<"\t";
}
  }

///////Нисходящая//////////
void N_mergeSort(int *data, int l, int r)
{
  if (l == r) return; // границы сомкнулись
   clock_t start3 = clock();
  int mid = (l + r) / 2; // определяем середину последовательности
  // и рекурсивно вызываем функцию сортировки для каждой половины
//  N_mergeSort(data, l, mid);
//  N_mergeSort(data, mid + 1, r);
  int i = l;  // начало первого пути
  int j = mid + 1; // начало второго пути
  int *tmp = (int*)malloc(r * sizeof(int)); // дополнительный массив
  for (int step = 0; step < r - l + 1; step++) // для всех элементов дополнительного массива
  {
    // записываем в формируемую последовательность меньший из элементов двух путей
    // или остаток первого пути если j > r
    if ((j > r) || ((i <= mid) && (data[i] < data[j])))
    {
      tmp[step] = data[i];
      i++;
    }
    else
    {
      tmp[step] = data[j];
      j++;
    }
  }
  // переписываем сформированную последовательность в исходный массив
  for (int step = 0; step < r - l + 1; step++)
  {
      data[l + step] = tmp[step];
  }

  clock_t end3 = clock();
  double sim_sort_Time3 = double(end3 - start3) / CLOCKS_PER_SEC;
   cout<<"N_mergeSort"<<endl;
   cout<<"Time:";
  cout<<sim_sort_Time3<<endl;

for(int i=0; i<15; i++)
  {
   cout<<data[i]<<"\t";
}
}
*/

///////quickSort//////////
void quickSort(int arr[], int l, int r) {
      int i = l, j = r;
      int tmp;
      clock_t start4 = clock();
      int pivot = arr[(l + r) / 2];
      /* partition */
      while (i <= j) {
            while (arr[i] < pivot)
                  i++;
            while (arr[j] > pivot)
                  j--;
            if (i <= j) {
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  i++;
                  j--;
            }
      };
      /* recursion */
      if (l < j)
            quickSort(arr, l, j);
      if (i < r)
            quickSort(arr, i, r);

      cout<<"quickSort"<<endl;
      cout<<"Time:";
          clock_t end4 = clock();
          for(int i=0; i<15; i++)
          {
           cout<<arr[i]<<"\t";
       }
          double sim_sort_Time4 = double(end4 - start4) / CLOCKS_PER_SEC;
          cout<<sim_sort_Time4<<endl;

}
/*
void sort()
{
const int column =13500;
int data[column];
    QFile file(":/Table.txt");

           if (!file.open(QIODevice::ReadOnly))
            {
                //qDebug() <<  "Cannot open a file";
            }

            int i = 0;
            QDataStream in(&file);
            while (!in.atEnd())
            {
                in >> data[i];
                i++;
            }

}*/
int main()
{
    ifstream f, g;
    int n=0;
    int data[size];
    string line;
    int er[100];
    f.open("500.txt", ios::in);
    g.open("Result.txt", ios::in);
    if(f)
    {
        while(!f.eof())
        {
            f>>data[n];
            n++;
            getline(g, line);
        }
      //  cout<<line<<"\t";
          //stupidSort(data,n);
          //radix(data, size-1, er);
          //N_mergeSort(data, 0, size-1);
          quickSort(data, 0, n);

          f.close();
    }


   system("pause");
}
