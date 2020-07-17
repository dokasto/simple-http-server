#Makefile

build_run:
	g++ -std=c++17 -c *.cpp && g++ -o main *.o && ./main
