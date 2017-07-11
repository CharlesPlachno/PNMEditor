#include <image.h>
#include <stdlib.h>
#include <Source.h>

Pixel::Pixel(void){
	red = (unsigned)255;
	green = (unsigned)255;
	blue = (unsigned)255;
}

Image::Image(void){
	width = 1786;
	height = 1344;
	maxVal = 255;
	pixels = new Pixel[width * height];

	sourcep = NULL;
}
Image::~Image(){
	delete[] pixels;
}

void Image::ResetSize(int h, int w){
	width = w;
	height = h;
	ClearPixels();
	pixels = new Pixel[width * height];
}
int Image::GetWidth()const{
	return width;
}
int Image::GetHeight()const{
	return height;
}
Pixel* Image::GetPixels()const{
	return pixels;
}
void Image::ClearPixels(){
	delete[] pixels;
}
void Image::SetPixels(Pixel* newpix){
	pixels = newpix;
}

void Image:: Update()const{
	sourcep->Update();
}
Source* Image::GetSource()const{
	return sourcep;
}
void Image::SetSource(Source* newsource){
	sourcep = newsource;
}
Pixel Image::GetPixel(int row, int column)const{
	return(pixels[row + (column * width)]);
}

