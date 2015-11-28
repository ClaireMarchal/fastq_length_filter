# fastq_length_filter


**************************************************************
Created by Claire Marchal at Universite Paris Diderot (FRANCE)
**************************************************************

The aim of this tool is to extract reads of specified length of a fastq, and 
to generate a new fastq with the reads of specified length on stdout.
Be aware that this tool doesn't check the format nor the integrity of the input 
file.

It takes a read length and a fastq file as input, and prints the reads of the 
specified length on stdout.

# Installation

*** download the folder fastq_length_filter:

git clone [public gitHub address when program will be online]

*** go into the folder:

cd fastq_length_filter

*** compile program:

make


# How to use

fastq_length_filter [expected read length] [path to your fastq file] > output.fastq


