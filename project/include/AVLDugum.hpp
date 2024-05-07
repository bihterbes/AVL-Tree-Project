/**
* @file AVLDugum.hpp
* @description Avl ağacı düğüm sınıfı
* @course 1-A
* @assignment 2
* @date 05/12/2023
* @author Enise Bihter Sari - enise.sari@ogr.sakarya.edu.tr
*/
#ifndef AVLDugum_hpp
#define AVLDugum_hpp

class AVLDugum
{
public:
    AVLDugum(int veri);
    int veri;
    AVLDugum* sol;
    AVLDugum* sag;
};

#endif