#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "include/harppi.h"
#include "include/file_io.h"
#include "include/histogram.h"

int main(int argc, char *argv[]) {
    parameters p(argv[1]);
    p.print();
    
    std::cout << "Getting data..." << std::endl;
    std::vector<double> data;
    int num_data = get_column(p.gets("in_file"), p.gets("col_name"), data);
    std::cout << "    Read in " << num_data << "  points of data." << std::endl;
    
    std::cout << "Performing histogram..." << std::endl;
    std::vector<double> bins;
    std::vector<int> hist;
    histogram(bins, hist, data);
    
    std::cout << "Outputting data..." << std::endl;
    output_histogram(p.gets("out_file"), bins, hist);
    
    return 0;
}
