/**
* @file BagliListe.hpp
* @description Bağlı liste sınıfı
* @course 1-A
* @assignment 2
* @date 05/12/2023
* @author Enise Bihter Sari - enise.sari@ogr.sakarya.edu.tr
*/
#ifndef BagliListe_hpp
#define BagliListe_hpp
#include "ListeDugum.hpp"
class BagliListe
{
public:
    int boyut;
    BagliListe();
    ~BagliListe();
    void ekle(AVLAgaci* tree);
    void cikar(AVLAgaci* tree);
    AVLAgaci* getir(int i);
    void don();
    void yaz();
    void yigitlaraDon();
private:
    ListeDugum* ilk;
};

#endif