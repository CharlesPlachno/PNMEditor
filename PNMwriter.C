#include <PNMwriter.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void PNMwriter::Write(char* fname){
	FILE *f_out = fopen(fname, "wb");
	fprintf(f_out, "%s\n%d %d\n%d\n", "P6", GetInput()->GetWidth(), GetInput()->GetHeight(), 255);
	unsigned char* data = new unsigned char[GetInput()->GetWidth()*GetInput()->GetHeight()*3];
	
	int i, dcount;
	dcount = 0;

	for(i =0; i<(GetInput()->GetWidth()*GetInput()->GetHeight()); i++){
		data[dcount] = GetInput()->GetPixels()[i].red;
		dcount++;
		data[dcount] = GetInput()->GetPixels()[i].green;
		dcount++;
		data[dcount] = GetInput()->GetPixels()[i].blue;
		dcount++;
	}

	fwrite(data, sizeof(unsigned char), (GetInput()->GetWidth()*GetInput()->GetHeight()*3), f_out);
	fclose(f_out);
	delete[] data;
}

