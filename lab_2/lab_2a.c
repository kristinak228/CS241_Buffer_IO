// Kristina Kolibab
// Lab 2a
// 3.3.17

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void read_write( FILE *, FILE * );

int main( int argc, char *argv[] ){

	FILE *ifp, *ofp;
	clock_t begin_time, end_time;
	double time_used;

	if(argc < 3){
		fprintf(stderr, "Not enough arguments\n");
	} 
	if(!(ifp = fopen(argv[1], "r"))){
		fprintf(stderr, "Cannot open file %s\n", argv[1]);
	}
	if(!(ofp = fopen(argv[2], "w"))){
		fprintf(stderr, "Cannot open file %s\n", argv[2]);
	}

	begin_time = clock();
	read_write(ifp, ofp);
	end_time = clock();
	time_used = (double)(end_time - begin_time)/CLOCKS_PER_SEC;
	fprintf(stderr, "Time usage = %17.13f\n", time_used);

	fclose(ifp);
	fclose(ofp);

	return 0;
}

void read_write( FILE * inputFile, FILE * outputFile ){

	int c = 0;
	while(EOF != (c = fgetc(inputFile))){
		fputc(c, outputFile);
	} 
}



