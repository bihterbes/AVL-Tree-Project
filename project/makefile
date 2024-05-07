hepsi:derle calistir
derle:
	g++ -I ./include/ -c ./src/Yigit.cpp -o ./lib/Yigit.o
	g++ -I ./include/ -c ./src/AVLDugum.cpp -o ./lib/AVLDugum.o
	g++ -I ./include/ -c ./src/AVLAgaci.cpp -o ./lib/AVLAgaci.o
	g++ -I ./include/ -c ./src/ListeDugum.cpp -o ./lib/ListeDugum.o
	g++ -I ./include/ -c ./src/BagliListe.cpp -o ./lib/BagliListe.o
	g++ -I ./include/ -c ./src/Fonksiyonlar.cpp -o ./lib/Fonksiyonlar.o
	
	g++ -I ./include/ ./src/main.cpp ./lib/Yigit.o ./lib/AVLDugum.o ./lib/AVLAgaci.o ./lib/ListeDugum.o ./lib/BagliListe.o ./lib/Fonksiyonlar.o -o ./bin/main.exe
calistir:
	./bin/main