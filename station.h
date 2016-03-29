#ifndef STATION_H
#define STATION_H

class Station
{
	public:
		Station();
		Station(int X,int Y);
		double distance(const Station &S) const;
		bool operator!=(const Station &S) const;
		bool operator==(const Station &S) const;
	private:
		int posX,posY;
		int tempsArret;
};

#endif
