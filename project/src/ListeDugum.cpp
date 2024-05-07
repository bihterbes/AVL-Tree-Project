/**
* @file ListeDugum.cpp
* @description Bağlı iste düğüm sınıfı
* @course 1-A
* @assignment 2
* @date 05/12/2023
* @author Enise Bihter Sari - enise.sari@ogr.sakarya.edu.tr
*/
#include "ListeDugum.hpp"
ListeDugum::ListeDugum(AVLAgaci* tree)
{
    this->tree = tree;
    sonraki = 0;
}