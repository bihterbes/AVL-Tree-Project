/**
* @file AVLAgaci.cpp
* @description Avl ağacı sınıfı
* @course 1-A
* @assignment 2
* @date 05/12/2023
* @author Enise Bihter Sari - enise.sari@ogr.sakarya.edu.tr
*/
#include "AVLAgaci.hpp"
#include <cmath>
#include <iomanip>
#include<iostream>
using namespace std;
AVLAgaci::AVLAgaci()
{
    kok = 0;
    yigit = 0;
    ekYigit = 0;
    AVLToplamDugumDeger = 0;
    ascii = 0;
}
AVLAgaci::~AVLAgaci()
{
    while(kok != 0)
    {
        sil(kok);
    }
    delete yigit;
    delete ekYigit;
}
AVLDugum* AVLAgaci::AVLAgaci::kokGetir(){
    return kok;
}
Yigit* AVLAgaci::yigitGetir(){
    return yigit;
}
void AVLAgaci::SetIndex(int i){
    sira = i;
}
bool AVLAgaci::varmi(int veri) 
{
    return varmi(veri,kok);
}
void AVLAgaci::ekle(int eklenecek)
{
    kok = ekle(eklenecek,kok);
}
int AVLAgaci::yukseklik() 
{
    return yukseklik(kok);
}
void AVLAgaci::preOrder() {
    preOrder(kok);
    cout<<endl;
}
void AVLAgaci::postOrder() {
    postOrder(0);
}
void AVLAgaci::inOrder() {
    inOrder(0);
}
void AVLAgaci::preOrder(AVLDugum* aktif) 
{
    if(aktif)
    {
        cout<<aktif->veri<<"  ";
        preOrder(aktif->sol);
        preOrder(aktif->sag);
    }
}
void AVLAgaci::postOrder(AVLDugum* aktif) 
{
    if(aktif)
    {
        postOrder(aktif->sol);
        postOrder(aktif->sag);
        cout<<aktif->veri<<"  ";
    }
}
void AVLAgaci::inOrder(AVLDugum* aktif) 
{
    if(aktif)
    {
        inOrder(aktif->sol);
        cout<<aktif->veri<<"  ";        
        inOrder(aktif->sag);
    }
}
int AVLAgaci::yukseklik(AVLDugum* aktifDugum) 
{
    if(aktifDugum)
    {
        return 1+max(   yukseklik(aktifDugum->sol),
                        yukseklik(aktifDugum->sag));
    }
    return -1;
}
AVLDugum* AVLAgaci::ekle(int veri,AVLDugum* aktifDugum) 
{
    if(aktifDugum==0)
        return new AVLDugum(veri);

    else if(aktifDugum->veri<veri)
    {
        aktifDugum->sag=ekle(veri,aktifDugum->sag);
        if(yukseklik(aktifDugum->sag)-yukseklik(aktifDugum->sol)>1)
        {   
            if(veri>aktifDugum->sag->veri)
                aktifDugum = solaDondur(aktifDugum);
                
            else
            {
                aktifDugum->sag = sagaDondur(aktifDugum->sag);
                aktifDugum =solaDondur(aktifDugum);
            }
        }
    }
    else if(aktifDugum->veri>veri)
    {
        aktifDugum->sol = ekle(veri,aktifDugum->sol);
        if(yukseklik(aktifDugum->sol)-yukseklik(aktifDugum->sag)>1)
        {

            if(veri<aktifDugum->sol->veri)
                aktifDugum = sagaDondur(aktifDugum);
            else
            {
                aktifDugum->sol = solaDondur(aktifDugum->sol);
                aktifDugum =sagaDondur(aktifDugum);
            }
        }

    }
    return aktifDugum;
}
AVLDugum* AVLAgaci::solaDondur(AVLDugum* buyukEbeveyn) 
{
    AVLDugum* sagCocuk = buyukEbeveyn->sag;
    buyukEbeveyn->sag = sagCocuk->sol;
    sagCocuk->sol = buyukEbeveyn;
    return sagCocuk;
}
AVLDugum* AVLAgaci::sagaDondur(AVLDugum* buyukEbeveyn) 
{
    AVLDugum* solCocuk = buyukEbeveyn->sol;
    buyukEbeveyn->sol = solCocuk->sag;
    solCocuk->sag = buyukEbeveyn;
    return solCocuk;
}
int AVLAgaci::maxDeger(AVLDugum* aktif) 
{
    if(aktif->sag)
        return maxDeger(aktif->sag);
    
    return aktif->veri;
}
bool AVLAgaci::varmi(int aranan,AVLDugum* aktif)
{
    if(aktif->veri<aranan)
    {
        if(aktif->sag)
            return varmi(aranan,aktif->sag);
        else
            return 0;
    }
    else if(aktif->veri>aranan)
    {
        if(aktif->sol)
            return varmi(aranan,aktif->sol);
        return 0;
    }
    else
    {
        return aktif;
    }
}
bool AVLAgaci::sil(AVLDugum *&aktif) 
{
    AVLDugum *silinecekDugum = aktif;
    
    if(aktif->sag == NULL) aktif = aktif->sol;
    else if(aktif->sol == NULL) aktif = aktif->sag;
    else{
        silinecekDugum = aktif->sol;
        AVLDugum *ebeveynDugum = aktif;
        while(silinecekDugum->sag != NULL){
            ebeveynDugum = silinecekDugum;
            silinecekDugum = silinecekDugum->sag;
        }
        aktif->veri = silinecekDugum->veri;
        if(ebeveynDugum == aktif) aktif->sol = silinecekDugum->sol;
        else ebeveynDugum->sag = silinecekDugum->sol;
    }
    delete silinecekDugum;
    return true;
}
int AVLAgaci::minDeger(AVLDugum* aktif) 
{
    if(aktif->sol)
        return maxDeger(aktif->sol);
    
    return aktif->veri;
}
int AVLAgaci::dengesizlikYonu(AVLDugum* aktif) 
{
    if(aktif==0)
        return 0;
    return yukseklik(aktif->sol)- yukseklik(aktif->sag);
}