#include <sink.h>
#include <stdlib.h>
Sink::Sink(void){
	input1 = NULL;
	input2 = NULL;
}

void Sink::SetInput(Image* img){
	input1 = img;
}
void Sink::SetInput2(Image* img){
	input2 = img;
}

const Image* Sink::GetInput()const{
	return input1;
}
const Image* Sink::GetInput2()const{
	return input2;
}