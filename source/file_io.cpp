#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <CCfits/CCfits>
#include "../include/file_io.h"

int get_column(std::string file, std::string col_name, std::vector<double> &data, int extNum) {
    std::unique_ptr<CCfits::FITS> pInfile(new CCfits::FITS(file, CCfits::Read, false));
    
    CCfits::ExtHDU &table = pInfile->extension(extNum);
    long start = 1L;
    long end = table.rows();
    
    table.column(col_name).read(data, start, end);
    
    return data.size();
}

void output_histogram(std::string file, std::vector<double> &bins, std::vector<int> &hist) {
    double bin_width = bins[1] - bins[0];
    double sum = 0;
    for (int i = 0; i < bins.size(); ++i)
        sum += bin_width*hist[i];
    
    std::cout << "Normalization factor: " << sum << std::endl;
    
    std::ofstream fout(file);
    fout.precision(15);
    for (size_t i = 0; i < bins.size(); ++i)
        fout << bins[i] << " " << hist[i] << " " << hist[i]/sum << "\n";
    fout.close();
}
