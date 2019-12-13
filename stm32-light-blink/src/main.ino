
#include <Arduino.h>

#define COMMON_ANODE
#define RED 19
#define GREEN 18
#define BLUE 17

int Max = 255;

void setup(){
	
	pinMode(RED, OUTPUT);
	pinMode(GREEN, OUTPUT);
	pinMode(BLUE, OUTPUT);

	setLed(RED,GREEN,BLUE);
	
}

void loop(){
	
	for(int i=0; i<Max; i++){
		setLed(Max-i, i, 0);
	}

	for(int i=0; i<Max; i++){
		setLed(0, Max-i, i);
	}

	for(int i=0; i<Max; i++){
		setLed(i, 0, Max-i);
	}
	
}

/*void RGB_FADE(){ 
	// RGB fade red to green
	for(int i=0; i<Max; i++){
		setLed(Max-i, i, 0);
	}

	// RGB fade green to blue
	for(int i=0; i<Max; i++){
		setLed(0, Max-i, i);
	}

	// RGB fade blue to red
	for(int i=0; i<Max; i++){
		setLed(i, 0, Max-i);
	}

}*/

void setLed(int R, int G, int B){
	#ifdef COMMON_ANODE
		R = Max - R;
		G = Max - G;
		B = Max - B;
	#endif

	analogWrite(RED, R);
	analogWrite(GREEN, G);
	analogWrite(BLUE, B);
	delay(10);
}
