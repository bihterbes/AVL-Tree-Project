/**
* @file Yigit.cpp
* @description Yığıt sınıfı
* @course 1-A
* @assignment 2
* @date 05/12/2023
* @author Enise Bihter Sari - enise.sari@ogr.sakarya.edu.tr
*/
#include "Yigit.hpp"

Yigit::Yigit()
{
    maxSize = 8;
    stack = new int[maxSize];
    top = 0;
}
Yigit::~Yigit()
{
    delete[] stack;
}
void Yigit::push(int item)
{
    if (top > maxSize - 1)
    {
        resize(maxSize * 2);
    }
    stack[top] = item;
    top++;
}
int Yigit::getir()
{
    if(top > 0)
    {
        return stack[top-1];
    }
    cout << "Stack empty" << endl;
    return 0;
}
int Yigit::pop()
{
    if (top > 0) // 0 1 2 top 3 son eleman 2de 
    {
        top--;
        int temp = stack[top];
        stack[top] = 0;
        if (top == maxSize / 4)
        {
            resize(maxSize / 2);
        }
        return temp;
    }
    else
    {
        cout << "Stack empty" << endl;
        return 0;
    }
}
void Yigit::resize(int newSize)
{
    maxSize = newSize;
    int * temp = new int[maxSize];
    for (int i = 0; i < top; i++)
    {
        temp[i] = stack[i];
    }
    delete[] stack;
    stack = temp;
}
bool Yigit::isEmpty()
{
    return top == 0;
}
int Yigit::size()
{
    return top;
}