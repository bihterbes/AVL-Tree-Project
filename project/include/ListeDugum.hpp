/**
* @file ListeDugum.hpp
* @description Bağlı iste düğüm sınıfı
* @course 1-A
* @assignment 2
* @date 05/12/2023
* @author Enise Bihter Sari - enise.sari@ogr.sakarya.edu.tr
*/
#ifndef ListeDugum_hpp
#define ListeDugum_hpp
#include "AVLAgaci.hpp"
class ListeDugum
{
public:
    ListeDugum(AVLAgaci* tree);
    AVLAgaci* tree;
    ListeDugum* sonraki;
};

#endif