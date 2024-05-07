/**
* @file Fonksiyonlar.cpp
* @description Fonksiyonlarda kapsamlı işlemler yapılır
* @course 1-A
* @assignment 2
* @date 05/12/2023
* @author Enise Bihter Sari - enise.sari@ogr.sakarya.edu.tr
*/
#include <iostream>
#include "AVLAgaci.hpp"
#include "Yigit.hpp"
using namespace std;

int toplam = 0;

void AddLeafToStack(AVLDugum* tree, Yigit* yigit)
{
    if(tree != NULL)
    {
        if (tree->sol == NULL && tree->sag == NULL)
            yigit->push(tree->veri);
        else
            toplam += tree->veri;
        if (tree->sol != NULL)
            AddLeafToStack(tree->sol, yigit);
        if (tree->sag != NULL)
            AddLeafToStack(tree->sag, yigit);
    }
}

void Process(AVLAgaci* tree){
    Yigit* yigit = new Yigit();
    AddLeafToStack(tree->kokGetir(), yigit);
    tree->yigit = yigit;
    tree->ekYigit = new Yigit();
    for(int i=0; i<yigit->size(); i++)
    {
        tree->ekYigit->push(yigit->stack[i]);
    }
    tree->AVLToplamDugumDeger = toplam;
    toplam = 0;
    tree->ascii = tree->AVLToplamDugumDeger%(90-65 + 1) + 65;
}

