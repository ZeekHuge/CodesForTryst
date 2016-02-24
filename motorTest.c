
/*
*
* Copy all the code exactly as it is in the arduino and load it to the board
*
*/


/******************************************************************************/
/******************************************************************************/
/* Pin configurations */


#define LS  2
#define LSa 3

#define RS  4
#define RSa 5  

#define CS 10

#define LM1 6
#define LM2 7
#define RM1 8      
#define RM2 9      


/******************************************************************************/
/******************************************************************************/
/* Sensor configurations */

#define _isBlack(pinNumber) !digitalRead(pinNumber)
#define _isWhite(pinNumber) digitalRead(pinNumber)



#define _straightAtBlackLine \
 _isWhite(RS) && _isWhite(RSa)  \
&& _isWhite(LS) && _isWhite(LSa) \
&& _isBlack(CS)



#define _ifBlackLineIsOnRight     \
( _isBlack(RS) || _isBlack(RSa) ) \
&& _isWhite(LS) && _isWhite(LSa) 




#define _ifBlackLineIsOnLeft      \
( _isBlack(LS) || _isBlack(LSa) ) \
&&  _isWhite(RS) && _isWhite(RSa) 



#define _ifDeadEnd \
_isWhite(LS) && _isWhite(LSa) &&  _isWhite(RS) && _isWhite(RSa) && _isWhite(CS)
 


/******************************************************************************/
/******************************************************************************/
/* Motor configurations */


#define _leftMotorForward   digitalWrite(LM1,HIGH);digitalWrite(LM2,LOW)
#define _leftMotorBackward  digitalWrite(LM1,LOW) ;digitalWrite(LM2,HIGH)
#define _leftMotorStop      digitalWrite(LM1,LOW) ;digitalWrite(LM2,LOW)

#define _rightMotorForward   digitalWrite(RM1,LOW);digitalWrite(RM2,HIGH)
#define _rightMotorBackward  digitalWrite(RM1,HIGH);digitalWrite(RM2,LOW)
#define _rightMotorStop      digitalWrite(RM1,LOW);digitalWrite(RM2,LOW)

/******************************************************************************/
/******************************************************************************/



void setup() {
  
  pinMode(LS ,INPUT);
  pinMode(LSa,INPUT);
  pinMode(RS ,INPUT);
  pinMode(RSa,INPUT);
  pinMode(CS ,INPUT);

  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);   
}


void loop(){

	//move stright
	_leftMotorForward;
	_rightMotorForward;

	delay(3000);

	//move back
	_leftMotorBackward;
	_rightMotorBackward;

	delay(3000);

	//move clockwise
	_rightMotorBackward;
	_leftMotorForward;

	delay(3000);

	//move anticlockwise
	_rightMotorForward;
	_leftMotorBackward;

	delay(3000);


	//stop movement
	_leftMotorStop;
	_rightMotorStop;

	delay(3000);

}