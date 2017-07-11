#include <PNMreader.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

PNMreader::PNMreader(char* fname){
	filename = new char[strlen(fname)];
	strcpy(filename, fname);
	img = new Image();
	img->SetSource(this);
}

PNMreader::~PNMreader(){
	delete[] filename;
}

void PNMreader::Execute(){

	FILE *f_in = fopen(filename, "r");
	char magicNum[128];
	int fmaxval, fheight, fwidth, i;
	fscanf(f_in, "%s\n%d %d\n%d\n", magicNum, &fwidth, &fheight, &fmaxval);  
	GetOutput()->ResetSize(fheight, fwidth);
	//printf( "width = %d, height = %d", GetOutput()->GetWidth(), GetOutput()->GetHeight());
	
	for(i =0; i<fwidth*fheight; i++){
		GetOutput()->GetPixels()[i].red = getc(f_in);
		GetOutput()->GetPixels()[i].green = getc(f_in);
		GetOutput()->GetPixels()[i].blue = getc(f_in);
	}
	//fprintf(stderr, "pixel 0 red = %u", GetOutput()->GetPixels()[0].red);
	fclose(f_in);
}
void PNMreader::Update(){
//fprintf(stderr, "updating reader\n");///
	this->Execute();
//	fprintf(stderr, "Done updating reader\n");///
}