/**
* @file main.cpp
* @description Main sınıfı programın tüm akışını içerir
* @course 1-A
* @assignment 2
* @date 05/12/2023
* @author Enise Bihter Sari - enise.sari@ogr.sakarya.edu.tr
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include "AVLAgaci.hpp"
#include "BagliListe.hpp"
#include "Yigit.hpp"
using namespace std;

void Process(AVLAgaci* tree);

int main() {
    string input = "./doc/Veri.txt";
    ifstream file(input);
    
    if (!file.is_open()) {
        cout << "Dosya acilamadi. Lutfen tekrar deneyiniz " << endl;
        return 1;
    }

    string line;
    BagliListe* list = new BagliListe();
    int i=0;
    while (getline(file, line)) {
        istringstream lineStream(line);
        int number;
        AVLAgaci* tree = new AVLAgaci();
        while (lineStream >> number) {
            tree->ekle(number);
        }
        Process(tree);
        tree->SetIndex(i+1);
        i = i + 1;
        list->ekle(tree);
    }
    list->don();
    delete list;
    file.close();

    return 0;
}