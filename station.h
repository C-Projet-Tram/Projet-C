#ifndef STATION_H
#define STATION_H

class Station
{
	public:
		Station();
		Station(int X,int Y);
		double distance(const Station &S2) const;
	private:
		int posX,posY;
};

#endif
