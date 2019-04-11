void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT); //redLight
  pinMode(12, OUTPUT); //yellowLight
  pinMode(11, INPUT); //btn1
  pinMode(10, INPUT); //btn2
  pinMode(9, OUTPUT); //greenLight
  pinMode(2, INPUT);  //sensor
  
}

const int LOCKED = 1;
const int WAIT1 = 2;
const int WAIT2 = 3;
const int CHECKING = 4;
const int UNLOCKED = 5;
int state = LOCKED;

int pushhandled = 0;
int pass1 = 0;
int pass2 = 0;
int sensorState = 0;

void loop() {
  sensorState = digitalRead(2);
  int btn1 = digitalRead(11);
  int btn2 = digitalRead(10);
  
  if ((btn1 == LOW) && (btn2 == LOW))
    pushhandled = 0;
  
  //read sensor
  switch (state) {
    
    case LOCKED:
    	pass1 = 0;
    	pass2 = 0;
    	digitalWrite(13, HIGH);
   		if(sensorState == HIGH){
          state = WAIT1;
    	}
 		digitalWrite(13, LOW);
    	break;
    
    case WAIT1:
    	digitalWrite(12, HIGH);
    	if (((btn1 == HIGH) || (btn2 == HIGH)) && !pushhandled) {
      		pushhandled = 1;
          	digitalWrite(12, LOW);
          	delay(200);
      		state = WAIT2;
          	if(btn2 == HIGH)
              pass2 = 1;
        }
    	break;
    
    case WAIT2:
		
    	digitalWrite(12, HIGH);
    	if(((btn1 == HIGH) || (btn2 == HIGH)) && !pushhandled) {
          pushhandled = 1;
          digitalWrite(12, LOW);
          delay(200);
          digitalWrite(12, HIGH);
          state = CHECKING;
          if(btn1 == HIGH) {
            pass1 = 1;
          }
          digitalWrite(12, LOW);
    	}
          
    	break;
    
    case CHECKING:  
    	if((pass1 && pass2) == 1) {
          state = UNLOCKED;
        } else {
          digitalWrite(13, HIGH);
    	  delay(250);
    	  digitalWrite(13, LOW);
          delay(250);
          digitalWrite(13, HIGH);
    	  delay(250);
    	  digitalWrite(13, LOW);
          delay(250);
          digitalWrite(13, HIGH);
    	  delay(250);
    	  digitalWrite(13, LOW);
          state = LOCKED;
        }
    	break;
    
    case UNLOCKED:
    	digitalWrite(9, HIGH);
        delay(5000);
        digitalWrite(9, LOW);
        state = LOCKED;
    	break;
  }
}