#include <filters.h>
#include <PNMreader.h>
#include <logging.h>

void Shrinker:: Execute(){

	int i, j;
	GetOutput()->ResetSize(GetInput()->GetHeight()/2, GetInput()->GetWidth()/2);
	for(i=0; i< GetOutput()->GetWidth(); i++){
		for(j=0; j<GetOutput()->GetHeight(); j++){
			GetOutput()->GetPixels()[i + (j*GetOutput()->GetWidth())].red = GetInput()->GetPixels()[(2*i)+(j*2*GetInput()->GetWidth())].red;
			GetOutput()->GetPixels()[i + (j*GetOutput()->GetWidth())].green = GetInput()->GetPixels()[(2*i)+(j*2*GetInput()->GetWidth())].green;
			GetOutput()->GetPixels()[i + (j*GetOutput()->GetWidth())].blue = GetInput()->GetPixels()[(2*i)+(j*2*GetInput()->GetWidth())].blue;
		}
	}
}
void Shrinker::Update(){
	//fprintf(stderr, "updating shrinker\n");///
	char msg[128];
	sprintf(msg, "Shrinker: about to Update");
	Logger::LogEvent(msg);
		if(input1 == NULL){
		char msg[1024];
		sprintf(msg, "Shrinker: no input1");
		DataFlowException e("Shrinker", msg);
		throw e;
	}
	 input1->Update();
	sprintf(msg, "Shrinker: about to execute");
	Logger::LogEvent(msg);
	 this->Execute();
	sprintf(msg, "Shrinker: done executing");
	Logger::LogEvent(msg);
	sprintf(msg, "Shrinker: done updating");
	Logger::LogEvent(msg);
	//fprintf(stderr, "Done updating shrinker\n");///
}

void LRConcat:: Execute(){
	if(input1 == NULL){
		char msg[1024];
		sprintf(msg, "LRConcat: no input1");
		DataFlowException e("LRConcat", msg);
		throw e;
	}
	if(input2 == NULL){
		char msg[1024];
		sprintf(msg, "LRConcat: no input2");
		DataFlowException e("LRConcat", msg);
		throw e;
	}
	if(input1->GetHeight() != input2->GetHeight()){
		char msg[1024];
		sprintf(msg, "LRConcat: widths must match: %d, %d",input1->GetHeight(), input2->GetHeight());
		DataFlowException e("LRConcat", msg);
		throw e;
	}
	GetOutput()->ResetSize(GetInput()->GetHeight(), GetInput()->GetWidth()+GetInput2()->GetWidth());
	int i, j, k, x;
	for(i =0; i<GetOutput()->GetHeight(); i++){
		x=0;
		for(j=0; j<GetInput()->GetWidth(); j++){
			GetOutput()->GetPixels()[j + (i * GetOutput()->GetWidth())].red = GetInput()->GetPixels()[j+ (i * GetInput()->GetWidth())].red;
			GetOutput()->GetPixels()[j + (i * GetOutput()->GetWidth())].green = GetInput()->GetPixels()[j+ (i * GetInput()->GetWidth())].green;
			GetOutput()->GetPixels()[j + (i * GetOutput()->GetWidth())].blue = GetInput()->GetPixels()[j+ (i * GetInput()->GetWidth())].blue;
			x++;
		}
		for(k=0; k<GetInput2()->GetWidth(); k++){
			GetOutput()->GetPixels()[x+k+ (i * GetOutput()->GetWidth())].red = GetInput2()->GetPixels()[k+ (i * GetInput2()->GetWidth())].red;
			GetOutput()->GetPixels()[x+k+ (i * GetOutput()->GetWidth())].green = GetInput2()->GetPixels()[k+ (i * GetInput2()->GetWidth())].green;
			GetOutput()->GetPixels()[x+k+ (i * GetOutput()->GetWidth())].blue = GetInput2()->GetPixels()[k+ (i * GetInput2()->GetWidth())].blue;
		}
	}
}
void LRConcat::Update(){
	//fprintf(stderr, "updating LRConcat\n");///
	char msg[128];
	sprintf(msg, "LRConcat: about to update input1");
	Logger::LogEvent(msg);
	if(input1 == NULL){
		char msg[1024];
		sprintf(msg, "LRConcat: no input1");
		DataFlowException e("LRConcat", msg);
		throw e;
	}
	 input1->Update();
	sprintf(msg, "LRConcat: done updating input1");
	Logger::LogEvent(msg);
	sprintf(msg, "LRConcat: about to update input2");
	Logger::LogEvent(msg);
	if(input2 == NULL){
		char msg[1024];
		sprintf(msg, "LRConcat: no input2");
		DataFlowException e("LRConcat", msg);
		throw e;
	}
	 input2->Update();
	sprintf(msg, "LRConcat: done updating input2");
	Logger::LogEvent(msg);
	sprintf(msg, "LRConcat: about to execute");
	Logger::LogEvent(msg);
	 this->Execute();
	sprintf(msg, "LRConcat: done executing");
	Logger::LogEvent(msg);
	//fprintf(stderr, "Done updating LRConcat\n");///
}

void TBConcat :: Execute(){
	if(input1 == NULL){
		char msg[1024];
		sprintf(msg, "TBConcat: no input1");
		DataFlowException e("TBConcat", msg);
		throw e;
	}
	if(input2 == NULL){
		char msg[1024];
		sprintf(msg, "TBConcat: no input2");
		DataFlowException e("TBConcat", msg);
		throw e;
	}
	if(input1->GetWidth() != input2->GetWidth()){
		char msg[1024];
		sprintf(msg, "TBConcat: Heights must match: %d, %d",input1->GetWidth(), input2->GetWidth());
		DataFlowException e("TBConcat", msg);
		throw e;
	}
	GetOutput()->ResetSize(GetInput()->GetHeight()+GetInput2()->GetHeight(), GetInput()->GetWidth());
	int i, j, k, x;
	for(i =0; i<GetOutput()->GetWidth(); i++){
		x=0;
		for(j=0; j<GetInput()->GetHeight(); j++){
			GetOutput()->GetPixels()[i + (j * GetOutput()->GetWidth())].red = GetInput()->GetPixels()[i+ (j * GetOutput()->GetWidth())].red;
			GetOutput()->GetPixels()[i + (j * GetOutput()->GetWidth())].green = GetInput()->GetPixels()[i+ (j * GetOutput()->GetWidth())].green;
			GetOutput()->GetPixels()[i + (j * GetOutput()->GetWidth())].blue = GetInput()->GetPixels()[i+ (j * GetOutput()->GetWidth())].blue;
			x++;
		}
		for(k=0; k<GetInput2()->GetHeight(); k++){
			GetOutput()->GetPixels()[i+((x+k) * GetOutput()->GetWidth())].red = GetInput2()->GetPixels()[i+ (k * GetOutput()->GetWidth())].red;
			GetOutput()->GetPixels()[i+((x+k) * GetOutput()->GetWidth())].green = GetInput2()->GetPixels()[i+ (k * GetOutput()->GetWidth())].green;
			GetOutput()->GetPixels()[i+((x+k) * GetOutput()->GetWidth())].blue = GetInput2()->GetPixels()[i+ (k * GetOutput()->GetWidth())].blue;
		}
	}
}
void TBConcat :: Update(){
	//fprintf(stderr, "updating TBConcat\n");///
	char msg[128];
	sprintf(msg, "TBConcat: about to update input1");
	Logger::LogEvent(msg);
	if(input1 == NULL){
		char msg[1024];
		sprintf(msg, "TBConcat: no input1");
		DataFlowException e("TBConcat", msg);
		throw e;
	}
	input1->Update();
	sprintf(msg, "TBConcat: done updating input1");
	Logger::LogEvent(msg);
	sprintf(msg, "TBConcat: about to update input2");
	Logger::LogEvent(msg);
	if(input2 == NULL){
		char msg[1024];
		sprintf(msg, "TBConcat: no input2");
		DataFlowException e("TBConcat", msg);
		throw e;
	}
	input2->Update();
	sprintf(msg, "TBConcat: done updating input2");
	Logger::LogEvent(msg);
	sprintf(msg, "TBConcat: about to execute");
	Logger::LogEvent(msg);
	this->Execute();
	sprintf(msg, "TBConcat: done executing");
	Logger::LogEvent(msg);
	//fprintf(stderr, "Done updating TBConcat\n");///
}

void Blender:: SetFactor(float dec){
	factor = dec;
}
float Blender:: GetFactor(){
	return factor;
}
void Blender:: Execute(){
	if(GetFactor() > 1){
		char msg[1024];
		sprintf(msg, "Blender: invalid factor for Blender");
		DataFlowException e("Blender", msg);
		throw e;
	}
	if(input1 == NULL){
		char msg[1024];
		sprintf(msg, "Blender: no input1");
		DataFlowException e("Blender", msg);
		throw e;
	}
	if(input2 == NULL){
		char msg[1024];
		sprintf(msg, "Blender: no input2");
		DataFlowException e("Blender", msg);
		throw e;
	}
	int i;
	GetOutput()->ResetSize(GetInput()->GetHeight(),GetInput()->GetWidth());
	for (i=0; i<GetOutput()->GetWidth()*GetOutput()->GetHeight(); i++){
		GetOutput()->GetPixels()[i].red = (GetFactor())*GetInput()->GetPixels()[i].red + (1-GetFactor())*GetInput2()->GetPixels()[i].red;
		GetOutput()->GetPixels()[i].green = (GetFactor())*GetInput()->GetPixels()[i].green + (1-GetFactor())*GetInput2()->GetPixels()[i].green;
		GetOutput()->GetPixels()[i].blue = (GetFactor())*GetInput()->GetPixels()[i].blue + (1-GetFactor())*GetInput2()->GetPixels()[i].blue;
	}
}
void Blender:: Update(){
	//fprintf(stderr, "updating Blender\n");///
	char msg[128];
	sprintf(msg, "Blender: about to update input1");
	Logger::LogEvent(msg);
	if(input1 == NULL){
		char msg[1024];
		sprintf(msg, "Blender: no input1");
		DataFlowException e("Blender", msg);
		throw e;
	}
	input1->Update();
	sprintf(msg, "Blender: done updating input1");
	Logger::LogEvent(msg);
	sprintf(msg, "Blender: about to update input2");
	Logger::LogEvent(msg);
	if(input2 == NULL){
		char msg[1024];
		sprintf(msg, "Blender: no input2");
		DataFlowException e("Blender", msg);
		throw e;
	}
	input2->Update();
	sprintf(msg, "Blender: done updating input2");
	Logger::LogEvent(msg);
	sprintf(msg, "Blender: about to execute");
	Logger::LogEvent(msg);
	this->Execute();
	sprintf(msg, "Blender: done executing");
	Logger::LogEvent(msg);
	//fprintf(stderr, "Done updating Blender\n");////
}
void Mirror :: Update() {
	char msg[128];
	sprintf(msg, "Mirror: about to update input1");
	Logger::LogEvent(msg);
	if(input1 == NULL){
		char msg[1024];
		sprintf(msg, "Mirror: no input1");
		DataFlowException e("Mirror", msg);
		throw e;
	}
	input1->Update();
	sprintf(msg, "Mirror: done updating input1");
	Logger::LogEvent(msg);
	sprintf(msg, "Mirror: about to execute");
	Logger::LogEvent(msg);
	this->Execute();
	sprintf(msg, "Mirror: done executing");
	Logger::LogEvent(msg);
}
void Mirror :: Execute() {
	int y, x1;
	GetOutput()->ResetSize(GetInput()->GetHeight(), GetInput()->GetWidth());
	for(y = 0; y<GetInput()->GetHeight(); y++){
		for(x1 = 0; x1<(GetInput()->GetWidth()); x1++){
			GetOutput()->GetPixels()[x1 + (y * GetInput()->GetWidth())].red = input1->GetPixels()[GetInput()->GetWidth()-x1 + (y * GetInput()->GetWidth())].red;
			GetOutput()->GetPixels()[x1 + (y * GetInput()->GetWidth())].green = input1->GetPixels()[GetInput()->GetWidth()-x1 + (y * GetInput()->GetWidth())].green;
			GetOutput()->GetPixels()[x1 + (y * GetInput()->GetWidth())].blue = input1->GetPixels()[GetInput()->GetWidth()-x1 + (y * GetInput()->GetWidth())].blue;
		}
	}
}
void Rotate :: Update() {
	char msg[128];
	sprintf(msg, "Rotate: about to update input1");
	Logger::LogEvent(msg);
	if(input1 == NULL){
		char msg[1024];
		sprintf(msg, "Rotate: no input1");
		DataFlowException e("Rotate", msg);
		throw e;
	}
	input1->Update();
	sprintf(msg, "Rotate: done updating input1");
	Logger::LogEvent(msg);
	sprintf(msg, "Rotate: about to execute");
	Logger::LogEvent(msg);
	this->Execute();
	sprintf(msg, "Rotate: done executing");
	Logger::LogEvent(msg);
}

void Rotate :: Execute() {

	int i, j;
	GetOutput()->ResetSize(GetInput()->GetWidth(), GetInput()->GetHeight());
	for(i =0; i<GetInput()->GetHeight(); i++){
		for(j =0; j<GetInput()->GetWidth(); j++){
			GetOutput()->GetPixels()[(GetInput()->GetHeight() - i) + (j * GetInput()->GetHeight())-1].red = GetInput()->GetPixels()[j + (i * GetInput()->GetWidth())].red;
			GetOutput()->GetPixels()[(GetInput()->GetHeight() - i) + (j * GetInput()->GetHeight())-1].green = GetInput()->GetPixels()[j + (i * GetInput()->GetWidth())].green;
			GetOutput()->GetPixels()[(GetInput()->GetHeight() - i) + (j * GetInput()->GetHeight())-1].blue = GetInput()->GetPixels()[j + (i * GetInput()->GetWidth())].blue;
		}
	}
}
void Subtract :: Update() {
	char msg[128];
	sprintf(msg, "Subtract: about to update input1");
	Logger::LogEvent(msg);
	if(input1 == NULL){
		char msg[1024];
		sprintf(msg, "Subtract: no input1");
		DataFlowException e("Subtract", msg);
		throw e;
	}
	input1->Update();
	sprintf(msg, "Subtract: done updating input1");
	Logger::LogEvent(msg);
	sprintf(msg, "Subtract: about to update input2");
	Logger::LogEvent(msg);
	if(input2 == NULL){
		char msg[1024];
		sprintf(msg, "Subtract: no input2");
		DataFlowException e("Subtract", msg);
		throw e;
	}
	input2->Update();
	sprintf(msg, "Subtract: done updating input2");
	Logger::LogEvent(msg);
	sprintf(msg, "Subtract: about to execute");
	Logger::LogEvent(msg);
	this->Execute();
	sprintf(msg, "Subtract: done executing");
	Logger::LogEvent(msg);
}
void Subtract :: Execute() {
	
	if((input1->GetHeight() != input2->GetHeight()) & (input1->GetWidth() != input2->GetWidth())){
		char msg[1024];
		sprintf(msg, "Subtract: inputs do not have matching dimensions");
		DataFlowException e("Subtract", msg);
		throw e;
	}
	int i;
	GetOutput()->ResetSize(GetInput()->GetHeight(),GetInput()->GetWidth());
	for (i=0; i<GetOutput()->GetWidth()*GetOutput()->GetHeight(); i++){
	
		if(GetInput()->GetPixels()[i].red - GetInput2()->GetPixels()[i].red >= 0){
			GetOutput()->GetPixels()[i].red = GetInput()->GetPixels()[i].red - GetInput2()->GetPixels()[i].red;
		}else{
			GetOutput()->GetPixels()[i].red = (unsigned char)0;
		}
		if(GetInput()->GetPixels()[i].green - GetInput2()->GetPixels()[i].green >= 0){
			GetOutput()->GetPixels()[i].green = GetInput()->GetPixels()[i].green - GetInput2()->GetPixels()[i].green;
		}else{
			GetOutput()->GetPixels()[i].green = (unsigned char)0;
		}
		if(GetInput()->GetPixels()[i].blue - GetInput2()->GetPixels()[i].blue >= 0){
			GetOutput()->GetPixels()[i].blue = GetInput()->GetPixels()[i].blue - GetInput2()->GetPixels()[i].blue;
		}else{
			GetOutput()->GetPixels()[i].blue = (unsigned char)0;
		}
	}
}
void Grayscale :: Update() {
	char msg[128];
	sprintf(msg, "Grayscale: about to update input1");
	Logger::LogEvent(msg);
	if(input1 == NULL){
		char msg[1024];
		sprintf(msg, "Grayscale: no input1");
		DataFlowException e("Grayscale", msg);
		throw e;
	}
	input1->Update();
	sprintf(msg, "Grayscale: done updating input1");
	Logger::LogEvent(msg);
	sprintf(msg, "Grayscale: about to execute");
	Logger::LogEvent(msg);
	this->Execute();
	sprintf(msg, "Grayscale: done executing");
	Logger::LogEvent(msg);
}
void Grayscale :: Execute() {
	int i;
	GetOutput()->ResetSize(GetInput()->GetHeight(),GetInput()->GetWidth());
	for (i=0; i<GetOutput()->GetWidth()*GetOutput()->GetHeight(); i++){
		GetOutput()->GetPixels()[i].red = (GetInput()->GetPixels()[i].red/5 +GetInput()->GetPixels()[i].green/2 +GetInput()->GetPixels()[i].blue/4);
		GetOutput()->GetPixels()[i].green = (GetInput()->GetPixels()[i].red/5 +GetInput()->GetPixels()[i].green/2 +GetInput()->GetPixels()[i].blue/4);
		GetOutput()->GetPixels()[i].blue = (GetInput()->GetPixels()[i].red/5 +GetInput()->GetPixels()[i].green/2 +GetInput()->GetPixels()[i].blue/4);
	}
}
void Blur :: Update() {
	char msg[128];
	sprintf(msg, "Blur: about to update input1");
	Logger::LogEvent(msg);
	if(input1 == NULL){
		char msg[1024];
		sprintf(msg, "Blur: no input1");
		DataFlowException e("Blur", msg);
		throw e;
	}
	input1->Update();
	sprintf(msg, "Blur: done updating input1");
	Logger::LogEvent(msg);
	sprintf(msg, "Blur: about to execute");
	Logger::LogEvent(msg);
	this->Execute();
	sprintf(msg, "Blur: done executing");
	Logger::LogEvent(msg);
}
void Blur :: Execute() {
	int i, j;
	GetOutput()->ResetSize(GetInput()->GetHeight(),GetInput()->GetWidth());
	//copy borders//
	//top and bottom
	for(i =0; i<GetInput()->GetWidth(); i++){
		GetOutput()->GetPixels()[i].red = GetInput()->GetPixels()[i].red;
		GetOutput()->GetPixels()[i].green = GetInput()->GetPixels()[i].green;
		GetOutput()->GetPixels()[i].blue = GetInput()->GetPixels()[i].blue;
		GetOutput()->GetPixels()[i+GetInput()->GetWidth()*(GetInput()->GetHeight()-1)].red = GetInput()->GetPixels()[i+GetInput()->GetWidth()*(GetInput()->GetHeight()-1)].red;
		GetOutput()->GetPixels()[i+GetInput()->GetWidth()*(GetInput()->GetHeight()-1)].green = GetInput()->GetPixels()[i+GetInput()->GetWidth()*(GetInput()->GetHeight()-1)].green;
		GetOutput()->GetPixels()[i+GetInput()->GetWidth()*(GetInput()->GetHeight()-1)].blue = GetInput()->GetPixels()[i+GetInput()->GetWidth()*(GetInput()->GetHeight()-1)].blue;
	}
	//left and right
	for(i =0; i<GetInput()->GetHeight(); i++){
		GetOutput()->GetPixels()[i*GetInput()->GetWidth()].red = GetInput()->GetPixels()[i*GetInput()->GetWidth()].red;
		GetOutput()->GetPixels()[i*GetInput()->GetWidth()].green = GetInput()->GetPixels()[i*GetInput()->GetWidth()].green;
		GetOutput()->GetPixels()[i*GetInput()->GetWidth()].blue = GetInput()->GetPixels()[i*GetInput()->GetWidth()].blue;
		GetOutput()->GetPixels()[i*GetInput()->GetWidth()+ GetInput()->GetWidth() -1].red = GetInput()->GetPixels()[i*GetInput()->GetWidth()+ GetInput()->GetWidth() -1].red;
		GetOutput()->GetPixels()[i*GetInput()->GetWidth()+ GetInput()->GetWidth() -1].green = GetInput()->GetPixels()[i*GetInput()->GetWidth()+ GetInput()->GetWidth() -1].green;
		GetOutput()->GetPixels()[i*GetInput()->GetWidth()+ GetInput()->GetWidth() -1].blue = GetInput()->GetPixels()[i*GetInput()->GetWidth()+ GetInput()->GetWidth() -1].blue;
	}
	//blur the rest
	for(i =1; i<GetInput()->GetHeight()-1; i++){
		for(j =1; j<GetInput()->GetWidth()-1; j++){
		GetOutput()->GetPixels()[j+ i*GetInput()->GetWidth()].red = GetInput()->GetPixels()[(j-1)+ (i-1)*GetInput()->GetWidth()].red/8 + GetInput()->GetPixels()[(j)+ (i-1)*GetInput()->GetWidth()].red/8 + GetInput()->GetPixels()[(j+1)+ (i-1)*GetInput()->GetWidth()].red/8
			+ GetInput()->GetPixels()[(j-1)+ (i)*GetInput()->GetWidth()].red/8 + GetInput()->GetPixels()[(j+1)+ (i)*GetInput()->GetWidth()].red/8
			+ GetInput()->GetPixels()[(j-1)+ (i+1)*GetInput()->GetWidth()].red/8 + GetInput()->GetPixels()[(j)+ (i+1)*GetInput()->GetWidth()].red/8 + GetInput()->GetPixels()[(j+1)+ (i+1)*GetInput()->GetWidth()].red/8;
		
		GetOutput()->GetPixels()[j+ i*GetInput()->GetWidth()].green = GetInput()->GetPixels()[(j-1)+ (i-1)*GetInput()->GetWidth()].green/8 + GetInput()->GetPixels()[(j)+ (i-1)*GetInput()->GetWidth()].green/8 + GetInput()->GetPixels()[(j+1)+ (i-1)*GetInput()->GetWidth()].green/8
			+ GetInput()->GetPixels()[(j-1)+ (i)*GetInput()->GetWidth()].green/8 + GetInput()->GetPixels()[(j+1)+ (i)*GetInput()->GetWidth()].green/8
			+ GetInput()->GetPixels()[(j-1)+ (i+1)*GetInput()->GetWidth()].green/8 + GetInput()->GetPixels()[(j)+ (i+1)*GetInput()->GetWidth()].green/8 + GetInput()->GetPixels()[(j+1)+ (i+1)*GetInput()->GetWidth()].green/8;
		
		GetOutput()->GetPixels()[j+ i*GetInput()->GetWidth()].blue = GetInput()->GetPixels()[(j-1)+ (i-1)*GetInput()->GetWidth()].blue/8 + GetInput()->GetPixels()[(j)+ (i-1)*GetInput()->GetWidth()].blue/8 + GetInput()->GetPixels()[(j+1)+ (i-1)*GetInput()->GetWidth()].blue/8
			+ GetInput()->GetPixels()[(j-1)+ (i)*GetInput()->GetWidth()].blue/8 + GetInput()->GetPixels()[(j+1)+ (i)*GetInput()->GetWidth()].blue/8
			+ GetInput()->GetPixels()[(j-1)+ (i+1)*GetInput()->GetWidth()].blue/8 + GetInput()->GetPixels()[(j)+ (i+1)*GetInput()->GetWidth()].blue/8 + GetInput()->GetPixels()[(j+1)+ (i+1)*GetInput()->GetWidth()].blue/8;
		}
	}
}
Color::Color(int inwidth, int inheight, unsigned char inred, unsigned char ingreen, unsigned char inblue ){
	width = inwidth;
	height = inheight;
	red = inred;
	green = ingreen;
	blue = inblue;
	img->ResetSize(height,width);
	
}
void Color:: Execute() {
	int i;
	for(i=0; i<height*width; i++){
		img->GetPixels()[i].red = red;
		img->GetPixels()[i].green = green;
		img->GetPixels()[i].blue = blue;
	}
}
void Color:: Update(){
	char msg[128];
	sprintf(msg, "Color: about to update");
	Logger::LogEvent(msg);
	Execute();
	sprintf(msg, "Color: done updating");
	Logger::LogEvent(msg);
}
CheckSum::CheckSum(){
	redsum =0;
	greensum =0;
	bluesum = 0;
}
void CheckSum::Execute() {
	if(input1 == NULL){
		char msg[1024];
		sprintf(msg, "CheckSum: no input1");
		DataFlowException e("CheckSum", msg);
		throw e;
	}
	int i;
	for(i =0; i< GetInput()->GetHeight() * GetInput()->GetWidth(); i++){
		redsum = redsum + (unsigned char)GetInput()->GetPixels()[i].red;
		greensum = greensum +(unsigned char)GetInput()->GetPixels()[i].green;
		bluesum = bluesum +(unsigned char)GetInput()->GetPixels()[i].blue;
	}
	
}
void CheckSum:: OutputCheckSum(char* fname){
	Execute();
	FILE *f_out = fopen(fname, "w");
	fprintf(f_out, "CHECKSUM: %d, %d, %d\n", redsum, greensum, bluesum);
	fclose(f_out);
}