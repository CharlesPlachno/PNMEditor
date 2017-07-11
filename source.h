#ifndef SOURCE_H
#define SOURCE_H
#include <image.h>
#include <stdio.h>
#include <stdlib.h>

class Source {
	protected:
		Image* img;
		
	public:
		Source();
		~Source();
		virtual void Execute()= 0;
		virtual void Update() = 0;
		Image* GetOutput();
		
};
#endif