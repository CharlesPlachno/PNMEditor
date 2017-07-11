#include <source.h>
#include <stdio.h>
#include <stdlib.h>

Source:: Source(){
	img = new Image();
	img->SetSource(this);
	
}

Source:: ~Source(){
	delete img;
}

Image* Source::GetOutput(){
	return img;
}
