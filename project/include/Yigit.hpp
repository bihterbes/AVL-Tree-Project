/**
* @file Yigit.hpp
* @description Yığıt sınıfı
* @course 1-A
* @assignment 2
* @date 05/12/2023
* @author Enise Bihter Sari - enise.sari@ogr.sakarya.edu.tr
*/
#ifndef Yigit_hpp
#define Yigit_hpp
#include <iostream>
using namespace std;

class Yigit{
public:
    int* stack;
    int top, maxSize;
    Yigit();
    ~Yigit();
    void push(int item);
    int getir();
    int pop();
    void resize(int newSize);
    bool isEmpty();
    int size();
};

#endif