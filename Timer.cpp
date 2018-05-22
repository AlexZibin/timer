#include "Timer.h"

// Здесь читать про "фокусы" с unsigned long: google search "60 * 1000 = 4294961760"

Timer::Timer (void) {
	setInterval ("ms", 1000);
	switchOff ();
}

Timer::Timer (unsigned long intervalMillis, const char *_timerName) {
	setInterval (_timerName, intervalMillis);
	if (switch_on) 
		switchOn ();
	else 
		switchOff ();
}

Timer::Timer (unsigned long hours, unsigned long minutes, unsigned long seconds) {	
	setInterval ("ms", seconds*1000ul+minutes*1000ul*60ul+ hours*1000ul*60ul*60ul);
	if (switch_on) 
		switchOn ();
	else 
		switchOff ();
}

unsigned long Timer::setInterval (const char *_timerName, unsigned long intervalMillis){
	_intervalMillis = intervalMillis>10ul?intervalMillis:10ul;
    _timerName = timerName;
    
    // Info for debugging:
    if (strlen (_timerName) > 2) {
        Serial.print ("Timer::setInterval ("); Serial.print (_timerName); Serial.print (", "); Serial.println (_intervalMillis);
    }
	  
	//  Serial.print("\n Timer.cpp \n New timer interval: ");
//      Serial.println(intervalMillis);

	return _intervalMillis;
}

unsigned long Timer::getInterval (void) {
	return _intervalMillis;
}

unsigned long Timer::remainingTime (void) {
	unsigned long timePassed = millis()-_previousMillis;
	return _intervalMillis-timePassed;
}

void Timer::switchOn () {
    _isOn = true;
    _previousMillis = millis();
}

void Timer::switchOff (){
	_isOn = false;
}

bool Timer::isOn (){
	return _isOn;
}

bool Timer::needToTrigger(){
  if (!isOn()) return false;
  
  unsigned long timePassed = millis()-_previousMillis;
  if (timePassed > _intervalMillis ) {
	  
	/*Serial.println(_intervalMillis); 
	Serial.println(_previousMillis); 
	Serial.println(timePassed); delay (1000); */

	
    _previousMillis = millis();
	return true;
  }
  else return false;
}

void Timer::prepareToTrigger(){
	_previousMillis = millis() - 1 - _intervalMillis;
}


