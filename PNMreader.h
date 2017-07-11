#ifndef PNM_R
#define PNM_R
#include <source.h>
class PNMreader: public Source{
	char* filename;
	public:
		PNMreader(char*);
		~PNMreader();
		virtual void Execute();
		virtual void Update();
};
#endif
