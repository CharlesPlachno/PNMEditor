#ifndef FILTERS_H
#define FILTERS_H
#include <sink.h>
#include <source.h>

class Filter : public Sink, public Source{
	
};

class Shrinker : public Filter{
	public:
		virtual void Execute();
		virtual void Update();
};

class LRConcat : public Filter{
	public:
		virtual void Execute();
		virtual void Update();
};

class TBConcat : public Filter{
	public:
		virtual void Execute();
		virtual void Update();
};

class Blender : public Filter{
	float factor;
	public:
		virtual void Execute();
		virtual void Update();
		void SetFactor(float);
		float GetFactor();
};
class Mirror : public Filter{
	public:
	virtual void Execute() ;
	virtual void Update() ;
};

class Rotate : public Filter{
	public:
	virtual void Execute() ;
	virtual void Update() ;

};

class Subtract : public Filter{
	public:
	virtual void Execute() ;
	virtual void Update() ;
};

class Grayscale : public Filter{
	public:
	virtual void Execute() ;
	virtual void Update() ;
};

class Blur : public Filter{
	public:
	virtual void Execute() ;
	virtual void Update() ;
};

class Color: public Source{
	int width, height;
	unsigned char red, green, blue;
	public:
	Color(int, int, unsigned char, unsigned char, unsigned char);
	virtual void Execute() ;
	virtual void Update() ;
};

class CheckSum: public Sink{
	unsigned char redsum, greensum, bluesum;
	public:
	CheckSum();
	void Execute() ;
	void OutputCheckSum(char*);
};




#endif