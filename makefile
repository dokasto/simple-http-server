#Makefile

build_run:
	g++ -std=c++17 -c *.cpp -pthread && g++ -o main *.o && ./main
