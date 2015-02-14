#include "dig7x4.h"

void dig7x4::setup(){
	for(int i=0;i<4;i++){
		digs[i]->setup();
		pinMode(pinsNum[i],OUTPUT);
	}
}
/*
        _    _    _    _
      /_ / /_ / /_ / /_ /
     /_ / /_ / /_ / /_ /
	  ^    ^    ^    ^
	  3    2    1    0
	  
	  
               0
	          \/
	     ____________
	   /   ______    /
	1>/  /       /  /<5
	 /  /______ /  /
	/   ______    /
   /  /  /|   /  /
2>/  /___6__ /  /<4 _
 /____________ /   |_|<7
       
       /|
       3
	   
	   0 - top
	   1 - leftTop
	   2 - leftBottom
	   3 - bottom
	   4 - rightBottom
	   5 - rightTop
	   6 - middle
	   7 - point
*/
dig7x4::dig7x4(int top,int leftTop,int leftBottom,int bottom,int rightBottom,int rightTop,int middle,int point,int n0,int n1,int n2,int n3){
	digs = new dig7*[4];
	digs[0]=new dig7(top,leftTop,leftBottom,bottom,rightBottom,rightTop,middle,point);
	digs[1]=new dig7(top,leftTop,leftBottom,bottom,rightBottom,rightTop,middle,point);
	digs[2]=new dig7(top,leftTop,leftBottom,bottom,rightBottom,rightTop,middle,point);
	digs[3]=new dig7(top,leftTop,leftBottom,bottom,rightBottom,rightTop,middle,point);
	pinsNum[0]=n0;
	pinsNum[1]=n1;
	pinsNum[2]=n2;
	pinsNum[3]=n3;
}
dig7x4::~dig7x4(){
	delete digs[0];
	delete digs[1];
	delete digs[2];
	delete digs[3];
	delete[] digs;
}
void dig7x4::render(){
	for(int num=0;num<4;num++)
	{
		digs[num]->render();
		digitalWrite(pinsNum[num],LOW);
		delay(3);
		digitalWrite(pinsNum[num],HIGH);
	}
}
void dig7x4::push(int id,unsigned char data){
	digs[id]->push(data);
}
void dig7x4::pushInt(int num){
	digs[0]->pushInt(num);
	digs[1]->pushInt(num/10);
	digs[2]->pushInt(num/100);
	digs[3]->pushInt(num/1000);
}
void dig7x4::pushFloat(float num1,int afterPoint){
	int num=num1*pow(10.0f,afterPoint);
	digs[0]->pushInt(num);
	digs[1]->pushInt(num/10);
	digs[2]->pushInt(num/100);
	digs[3]->pushInt(num/1000);
	if(afterPoint>0) digs[afterPoint]->pushPoint(true);
}