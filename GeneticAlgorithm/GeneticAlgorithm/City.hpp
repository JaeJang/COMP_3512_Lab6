#pragma once

class City {
private:
	char name;
	int x_coordinate;
	int y_coordinate;

public:
	City() {}
	City(char name, int x, int y)
		:name(name), x_coordinate(x), y_coordinate(y) {}

	City(const City & rhs);

	char getName() { return name;  }
	int getX_coordinate() { return x_coordinate; }
	int getY_coordinate() { return y_coordinate; }
	double get_distance_between_cities(City * b);
	friend void swap(City& lsh, City &rhs);
	City & operator=(City lhs);
	friend bool operator==(const City & lhs, const City & rhs);



};
