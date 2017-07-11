#ifndef SINK_H
#define SINK_H
#include <image.h>

class Sink {
	protected:
		const Image *input1;
		const Image *input2;
	public:
		Sink(void);
		void SetInput(Image*);
		void SetInput2(Image*);
		const Image* GetInput()const;
		const Image* GetInput2()const;	
};
#endif