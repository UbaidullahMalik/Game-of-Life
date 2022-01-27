#include <iostream>
#include<cstdlib>
#include<ctime>
using namespace std;


//creating  a function for giving intial values
void intial_values(char** a, int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            a[i][j] = ' ';//assiging space to empty all the array
        }
    }
    srand(time(NULL));//for random number genration
    for (int i = 1; i < r-1; i++)
    {
        for (int j = 1; j < c - 1; j++)
        {
            int num = rand() % 100;//using 60 40 ratio for spaces and *
            if (num >= 60)
            {
                a[i][j] = ' ';
            }
            else
            {
                a[i][j] = '*';
            }
        }
    }
}

//the function to print the values
void print_values(char** a, int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}


//function to check the neighbours of the cell
void neighbour_check(char** a, int r, int c)
{
    int count = 0;
    for (int i = 1; i < r-1;i++)
    {
        for (int j = 1; j < c-1; j++)
        {
             if (a[i - 1][j] == '*')
             {
                    count++;
             }
             if (a[i + 1][j] == '*')
             {
                    count++;
             }
             if (a[i][j + 1] == '*')
             {
                    count++;
             }
             if (a[i][j - 1] == '*')
             {
                    count++;
             }
             if (a[i + 1][j + 1] == '*')
             {
                 count++;
             }
             if (a[i - 1][j + 1] == '*')
             {
                 count++;
             }
             if (a[i - 1 ][j - 1] == '*')
             {
                 count++;
             }
             if (a[i + 1][j - 1] == '*')
             {
                 count++;
             }

             if (count == 0 || count == 1)//if the count is 0 or 1 then the cell dies
             {
               a[i][j] = ' ';
             }
             else if (count == 2 && (a[i][j]==' '))//if count is 2 or 3 the cell becomes alive
             {
              a[i][j] = '*';
             }
             else if (count == 3 && (a[i][j] == ' '))
             {
                 a[i][j] = '*';
             }
             else if (count > 3)//if count is greater than 3 it dies from overpopulation
             {
               a[i][j] = ' ';
             }

             count = 0;
        }
        count = 0;
    }
}

int main()
{
    //rows and cols for a 30x30 grid
    int const row = 30;
    int const col = 30;

    //dynamically creating array using the new operator
    char** arr = new char* [row];
    for (int i = 0; i < row; i++)
    {
        arr[i] = new char[col];
    }

    intial_values(arr, row, col);
    print_values(arr, row, col);
  
    while (1)
    {
        neighbour_check(arr, row, col);
        print_values(arr, row, col);
    }
    for (int i = 0; i < row; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;

}


