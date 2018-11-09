# Histogram
This code will read a specific column from a fits file table and then output a histogram of the data. It automatically calculates the bin size which should be optimal for the data itself with

<i>h</i> = 2 IQR/<i>N<i><sup>-1/3</sup>

where IQR is the interquartile range, and <i>N</i> is the number of data values.

# Dependencies
This code leverages 
* CCfits
* cfitsio

Additionally, compilation has only been tested with the GNU Compiler Collection's g++.
