#include "Gps.h"

Gps::Gps()
{
	//system("/usr/local/bin/rtkrcv -s -o /home/pi/rtklib/data/rtkpi.conf");
	wiringPiSetupGpio();
	fd = serialOpen("/dev/ttyS0", 9600);
}

Gps::~Gps()
{
}

gpsData Gps::acquition_Gps()
{
	char c;
	while (fd != -1) {
		c = serialGetchar(fd);
		line = line + c;
		if (c == '\n') {
			trameLine.push_back(line);
			for (size_t i = 0; i < trameLine.size(); i++) {
				string trameDebut = trameLine[i].substr(0, 6);
				if (trameDebut == "$GPGGA") {
					coordonne.latitude = trameLine[i].substr(17, 14);
					coordonne.longitude = trameLine[i].substr(32, 15);
					//coordonne.latitude.replace(12, 1, "");
					//coordonne.longitude.replace(13, 1, "");
					cout << coordonne.latitude << endl;
					cout << coordonne.longitude << endl;
					return coordonne;
				}
			}
			line = "";
		}
	}
}
