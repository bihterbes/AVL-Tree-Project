/**
* @file AVLDugum.cpp
* @description Avl ağacı düğüm sınıfı
* @course 1-A
* @assignment 2
* @date 05/12/2023
* @author Enise Bihter Sari - enise.sari@ogr.sakarya.edu.tr
*/
#include "AVLDugum.hpp"

AVLDugum::AVLDugum(int veri)
{
    this->veri = veri;
    sol=sag=0;
}