#ifndef _DIG7x4_h_
#define _DIG7x4_h_

#include <Arduino.h>
#include <dig7.h>

/**
7-segment arduino library by AsGreyWolf
TODO: reverse support (+5v GND)
**/

class dig7x4{
	public:
		dig7x4(int top,int leftTop,int leftBottom,int bottom,int rightBottom,int rightTop,int middle,int point,int n0,int n1,int n2,int n3);
		~dig7x4();
		void setup();
		void render();
		void push(int id,unsigned char data);
		void pushInt(int num);
		void pushFloat(float num,int afterPoint);
	private:
		int pinsNum[4];
		dig7** digs;
};

#endif
