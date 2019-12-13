#define RED_PIN PB1
#define GREEN_PIN PB0
#define BLUE_PIN PA7

int RED = 255, GREEN = 255, BLUE = 255;

void setup(){
	Serial.begin(115200);
	pinMode(RED_PIN, OUTPUT);
	pinMode(GREEN_PIN, OUTPUT);
	pinMode(BLUE_PIN, OUTPUT);

	setLed(RED,GREEN,BLUE);
}

void loop(){
	
	REB_FADE(100);
}

void RGB_FADE(){ 
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

}

void setLed(int RED, int GREEN, int BLUE){
	#ifdef COMMON_ANODE
		RED = Max - RED;
		GREEN = Max - GREEN;
		BLUE = Max - BLUE;
	#endif

	analogWrite(RED_PIN, RED);
	analogWrite(GREEN_PIN, GREEN);
	analogWrite(BLUE_PIN, BLUE);
}
