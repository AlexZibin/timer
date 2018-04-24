#ifndef Timer_h
#define Timer_h
#define switch_on 1

#include "Arduino.h"

class Timer {
	public:
//		Timer (unsigned long intervalMillis=1000*30, bool switch_on = true);
		Timer (void);
		Timer (unsigned long intervalMillis, char *dummy);
		Timer (unsigned long hours, unsigned long minutes, unsigned long seconds=0);
		unsigned long setInterval (char *dummy, unsigned long intervalMillis);
		unsigned long getInterval (void);
		unsigned long remainingTime (void);
		void switchOn ();
		void switchOff ();
		bool isOn (); // 1=ВКЛ, 0=ВЫКЛ
		bool needToTrigger ();
	private:
		unsigned long _intervalMillis;
		volatile unsigned long _previousMillis;
		bool _isOn=false;
};


#endif