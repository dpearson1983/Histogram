#ifndef _FILE_IO_H_
#define _FILE_IO_H_

#include <vector>
#include <string>

int get_column(std::string file, std::string col_name, std::vector<double> &data, int extNum = 1);

void output_histogram(std::string file, std::vector<double> &bins, std::vector<int> &hist);

#endif
