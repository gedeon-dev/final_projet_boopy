#pragma once
#include <string.h>
#include <iostream>
#include <wiringPi.h>
#include <wiringSerial.h>
#include <cstdlib>
#include <vector>
using namespace std;
struct gpsData {
	string latitude;
	string longitude;
};
using namespace std;
class Gps
{
private:
	int fd;
	string line = "";
	vector <string> trameLine;
	gpsData coordonne;
public:
	Gps();
	~Gps();
	gpsData acquition_Gps();

};

