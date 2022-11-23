a:main.o BST.o
	wg++ -fno-elide-constructors -std=c++11  BST.o main.o

main.o:main.cpp BST.h
	wg++ -fno-elide-constructors -std=c++11  main.cpp -c

BST.o:BST.cpp BST.h
	wg++ -fno-elide-constructors -std=c++11  BST.cpp -c


