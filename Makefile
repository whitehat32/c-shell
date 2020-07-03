.PHONY: run clean
EXENAME = main args
run:
	make clean
	make -C src/ all
	g++ -o args args.cpp -std=c++11

