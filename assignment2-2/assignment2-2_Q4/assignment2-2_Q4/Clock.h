#pragma once

class Clock {
public:
	Clock();
	~Clock();
	
	void increaseHour();
	void increaseMinute();
	void increaseSecond();

	void setTime(int second);

	void printTime();

private:
	void setHour(int hour);
	void setMinute(int minute);
	void setSecond(int second);

	int hour;
	int minute;
	int second;
};