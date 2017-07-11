#ifndef IMG_H
#define IMG_H

class Source;

struct Pixel{
	unsigned char red, green, blue;
	Pixel(void);
};
class Image{
	int width, height, maxVal;
	Pixel* pixels;
	Source* sourcep;
	
	public:
		Image(void);
		~Image();
		void ResetSize(int, int);
		int GetWidth()const;
		int GetHeight()const;
		Pixel* GetPixels()const;
		void SetPixels(Pixel*);
		void ClearPixels();
		
		void Update()const;//
		Source* GetSource()const;
		void SetSource(Source*);
		Pixel GetPixel(int,int)const;
};

#endif