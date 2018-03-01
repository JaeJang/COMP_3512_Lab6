#pragma once

class City {
private:
	char name;
	int x_coordinate;
	int y_coordinate;

public:
	City(char name, int x, int y)
		:name(name), x_coordinate(x), y_coordinate(y)
	{

	}
	City(const City & rhs) {
		name = rhs.name;
		x_coordinate = rhs.x_coordinate;
		y_coordinate = rhs.y_coordinate;
	}

	char getName() { return name;  }
	int getX_coordinate() { return x_coordinate; }
	int getY_coordinate() { return y_coordinate; }
	friend void swap(City& lsh, City &rhs);
	City & operator=(City lhs);



};
