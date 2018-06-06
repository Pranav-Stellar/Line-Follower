//INTERFACING LINE FOLLOWER
//high1, high 2 and high3 are HIGH for interfacing L293D, enable pins.
// s1 and s3 are two IR Sensors.
#define left 7  //s3[left one]
#define right 8 //s1[right one]
//for turning left, left motor means motor adjacent to s3 should stop and right motor should keep running.
#define motor1 5 //right
#define motor11 6 //right
#define motor2 9  // left
#define motor22 10 //left
#define high1 2
#define high2 3
#define high3 13
int Left=1,Right=1;
void setup() {
  // put your setup code here, to run once:
  pinMode(left,INPUT);
  pinMode(right,INPUT);
   pinMode(high1,INPUT);
  pinMode(high2,INPUT);
  pinMode(high3,INPUT);
  digitalWrite(high1,HIGH);
  digitalWrite(high2,HIGH);
  digitalWrite(high3,HIGH);
  pinMode(motor1, OUTPUT);
  pinMode(motor11, OUTPUT);
  pinMode(motor2, OUTPUT);
  pinMode(motor22, OUTPUT);
  analogWrite(motor1,255);  
    analogWrite(motor11,0);  
    analogWrite(motor2,255);  
    analogWrite(motor22,0);  

}

void loop() {
  // put your main code here, to run repeatedly:
  Left = digitalRead(left);
  Right = digitalRead(right);
  if(Left*Right==1){
    analogWrite(motor1,255);  
    analogWrite(motor11,0);  
    analogWrite(motor2,255);  
    analogWrite(motor22,0);  
    
  }
  //HERE LEFT==0 MEANS s3 is on black line, it means we have to turn left. so for this, keep right motor ON[here motor1] and run MOTOR2 in opposite direction. you can also keep MOTOR2[LEFT] off.
  else if((Left==0 && Right==1)==1){
    analogWrite(motor1,240);  
    analogWrite(motor11,0);  
    analogWrite(motor2,0);  
    analogWrite(motor22,110);  
    
  }
  //just opposite as explained above
  else if((Left==1 && Right==0)==1){
    analogWrite(motor1,0);  
    analogWrite(motor11,110);  
    analogWrite(motor2,240);  
    analogWrite(motor22,0);  
    
  }
  else if((Left==0 && Right==0)==1){
    analogWrite(motor1,0);  
    analogWrite(motor11,0);  
    analogWrite(motor2,0);  
    analogWrite(motor22,0);  
     
    
   }
  
}
