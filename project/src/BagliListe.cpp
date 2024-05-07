/**
* @file BagliListe.cpp
* @description Bağlı liste sınıfı
* @course 1-A
* @assignment 2
* @date 05/12/2023
* @author Enise Bihter Sari - enise.sari@ogr.sakarya.edu.tr
*/
#include "BagliListe.hpp"
#include <iostream>
#include<iomanip>
BagliListe::BagliListe()
{
    ilk=0;
    boyut=0;
}
BagliListe::~BagliListe()
{
    ListeDugum* gecici = ilk;
    while(gecici!=0)
    {
        ListeDugum* silinecek = gecici;
        gecici= gecici->sonraki;
        delete silinecek->tree;
        delete silinecek;
    }
}
void BagliListe::ekle(AVLAgaci* tree)
{
    ListeDugum* yeni = new ListeDugum(tree);
    if(ilk==0)
    {
        ilk = yeni;
        boyut++;
        return;
    }
   
    ListeDugum* gecici = ilk;
    while(gecici->sonraki!=0)
        gecici= gecici->sonraki;
    gecici->sonraki = yeni;
    boyut++;
}
void BagliListe::cikar(AVLAgaci* tree)
{
    if(ilk==0)  return;

    if(ilk->tree == tree)
    {
        ListeDugum* silinecek = ilk;
        ilk = ilk->sonraki;
        delete silinecek;
        boyut--;
    }
    else
    {
        ListeDugum* gecici = ilk;
        while(gecici->sonraki->tree != tree)
        {
            gecici=gecici->sonraki;
        }
        ListeDugum* silinecek = gecici->sonraki;
        gecici->sonraki = silinecek->sonraki;
        delete silinecek;
        boyut--;
    }
}
AVLAgaci* BagliListe::getir(int i)
{
    ListeDugum* gecici = ilk;
    for(int j=0; j<i; j++)
    {
        gecici = gecici->sonraki;
    }
    return gecici->tree;
}
void BagliListe::don()
{
    if(boyut > 1)
    {
        yaz();
        system("cls");
        do
        {
            AVLAgaci* gecici = getir(0);
            for(int i=0; i<boyut-1; i++)
            {
                if(getir(i+1)->ekYigit->getir() < gecici->ekYigit->getir())
                {
                    gecici = getir(i+1);
                }
            }
            gecici->ekYigit->pop();
            if(gecici->ekYigit->isEmpty() == true)
            {
                cikar(gecici);
                yigitlaraDon();
                yaz();
                system("cls");
                continue;
            }
            gecici = getir(0);
            for(int i=0; i<boyut-1; i++)
            {
                if(gecici->ekYigit->getir() < getir(i+1)->ekYigit->getir())
                {
                    gecici = getir(i+1);
                }
            }
            gecici->ekYigit->pop();
            if(gecici->ekYigit->isEmpty() == true)
            {
                cikar(gecici);
                yigitlaraDon();
                yaz();
                system("cls");
                continue;
            }
        }while(boyut != 1);
        
        for(int i=0; i<30; i++)
        {
            cout << "=";
        }
        cout << endl << "|";
        for(int i=0; i<28; i++)
        {
            cout << " ";
        }
        cout << "|" << endl << "|";
        for(int i=0; i<28; i++)
        {
            cout << " ";
        }
        cout << "|" << endl;
        cout << "|" << "     " << "Son Karakter: " << setw(3) << getir(0)->ascii << "      |" << endl;
        cout << "|" << "     " << "AVL NO      : " << setw(3) << getir(0)->sira << "      |" << endl;
        cout << "|";
        for(int i=0; i<28; i++)
        {
            cout << " ";
        }
        cout << "|" << endl << "|";
        for(int i=0; i<28; i++)
        {
            cout << " ";
        }
        cout << "|" << endl;
        for(int i=0; i<30; i++)
        {
            cout << "=";
        }
        cout << endl;
    }
}
void BagliListe::yaz()
{
    for(int i=0; i<boyut; i++)
    {
        cout << getir(i)->ascii;
    }
    cout << endl;
}
void BagliListe::yigitlaraDon()
{
    ListeDugum* gecici = ilk;
    for(int i=0; i<boyut; i++)
    {
        delete[] gecici->tree->ekYigit->stack;
        int maxSize = gecici->tree->yigit->maxSize;
        int top = gecici->tree->yigit->top;
        gecici->tree->ekYigit->maxSize = maxSize;
        gecici->tree->ekYigit->top = top;
        gecici->tree->ekYigit->stack = new int[maxSize];
        for(int j=0; j<top; j++)
        {
            gecici->tree->ekYigit->stack[j] = gecici->tree->yigit->stack[j];
        }
        gecici = gecici->sonraki;
    }
}