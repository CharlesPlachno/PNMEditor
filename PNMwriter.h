#ifndef PNM_W
#define PNM_W
#include <sink.h>

class PNMwriter : public Sink{
	public:
		void Write(char*);
};
#endif