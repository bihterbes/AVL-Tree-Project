/**
* @file AVLAgaci.hpp
* @description Avl ağacı sınıfı
* @course 1-A
* @assignment 2
* @date 05/12/2023
* @author Enise Bihter Sari - enise.sari@ogr.sakarya.edu.tr
*/
#ifndef AVLAgaci_hpp
#define AVLAgaci_hpp
#include<iostream>
#include "AVLDugum.hpp"
#include "Yigit.hpp"
using namespace std;

class AVLAgaci
{
public:
    int sira;
    Yigit* yigit;
    Yigit* ekYigit;
    int AVLToplamDugumDeger;
    char ascii;
    AVLAgaci();
    ~AVLAgaci();
    AVLDugum* kokGetir();
    Yigit* yigitGetir();
    void SetIndex(int i);
    bool varmi(int veri);
    void ekle(int veri);
    bool sil(AVLDugum *&aktif);
    int yukseklik();
    void preOrder();
    void postOrder();
    void inOrder();
private:
    int dengesizlikYonu(AVLDugum* aktif);
    AVLDugum* solaDondur(AVLDugum* dugum);
    AVLDugum* sagaDondur(AVLDugum* dugum);
    int minDeger(AVLDugum* aktif);
    void preOrder(AVLDugum* aktif);
    void postOrder(AVLDugum* index);
    void inOrder(AVLDugum* index);
    int yukseklik(AVLDugum* aktifDugum);
    AVLDugum* ekle(int veri,AVLDugum* aktifDugum);
    bool varmi(int aranan,AVLDugum* aktif);
    AVLDugum* sil(int veri,AVLDugum* aktif);
    int maxDeger(AVLDugum* aktif);
    AVLDugum* kok;
};

#endif