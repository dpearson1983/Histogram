CXX = g++
CXXOPTS = -march=native -mtune=native -O3
LIBFITS = -lCCfits -lcfitsio

build: harppi file_io main.cpp
	$(CXX) $(LIBFITS) $(CXXOPTS) -o $(HOME)/bin/histogram main.cpp obj/*.o
	
harppi: source/harppi.cpp
	mkdir -p obj
	$(CXX) $(CXXOPTS) -c -o obj/harppi.o source/harppi.cpp
	
file_io: source/file_io.cpp
	mkdir -p obj
	$(CXX) $(LIBFITS) $(CXXOPTS) -c -o obj/file_io.o source/file_io.cpp
