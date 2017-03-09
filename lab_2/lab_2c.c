// Kristina Kolibab
// 3.8.17
// lab 2c

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define BUFF_SIZE 1024

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
	int i = 0;

        char bufferA[ BUFF_SIZE  ];
	char bufferB[ 30 ];

        while( fgets(bufferA, 60, inputFile) != NULL ){
		while(i < 60){
			for(int j = 0; j < 30; j++){
				bufferB[j] = bufferA[j];
			}
		fputs(bufferB, outputFile);
		i = i + 30;
		}
        }
/*

	this is not currently working
	you need to read in an amount into bufferA
	then bring portions of that into bufferB, which gets put into the outputFile
	figure out how to increment both bufferA to say when you have gotten through the first 60
	and when bufferB has gone through all 60 in smaller portions

*/

}






