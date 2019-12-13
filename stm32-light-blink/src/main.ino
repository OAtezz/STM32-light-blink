
#include <Arduino.h>
//#ifndef
#define COMMON_ANODE
//#define Max 255

#define RED 19
#define GREEN 18
#define BLUE 17
//#endif

int Max = 255;
//int RED, GREEN, BLUE;
int setColor(RED, GREEN, BLUE);

void setup(){
	//Serial.begin(115200);
	pinMode(RED, OUTPUT);
	pinMode(GREEN, OUTPUT);
	pinMode(BLUE, OUTPUT);

	//pinMode(LED_BUILIN, OUTPUT);
	//analogWrite(LED_BUILIN, LOW);
	//setLed(RED,GREEN,BLUE);
	//setColor(RED,GREEN,BLUE);
}

void loop(){
	// RGB fade red to green
	for(int i=0; i<Max; i++){
		setColor(Max-i, i, 0);
	}

	// RGB fade green to blue
	for(int i=0; i<Max; i++){
		setColor(0, Max-i, i);
	}

	// RGB fade blue to red
	for(int i=0; i<Max; i++){
		setColor(i, 0, Max-i);
	}
	//RGB_FADE(100);
}

/*void RGB_FADE(){ 
	// RGB fade red to green
	for(int i=0; i<Max; i++){
		setColor(Max-i, i, 0);
	}

	// RGB fade green to blue
	for(int i=0; i<Max; i++){
		setColor(0, Max-i, i);
	}

	// RGB fade blue to red
	for(int i=0; i<Max; i++){
		setColor(i, 0, Max-i);
	}

}*/

void setLed(int R, int G, int B){
	#ifdef COMMON_ANODE
		R = Max - R;
		G = Max - G;
		B = Max - B;
	#endif

	analogWrite(RED, R);
	delay(10);
	analogWrite(GREEN, G);
	delay(10);
	analogWrite(BLUE, B);
	delay(10);
}
