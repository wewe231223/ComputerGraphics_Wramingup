#pragma once
#include "PointList.h"


using namespace std;


void PointListrun::Run() {


	List::PointList points;


	char com;
	
	bool isAranged = false;


	Point::point pp;


	pp = Point::NewPoint(2, 2, 2);
	points.push(pp, Back);

	pp = Point::NewPoint(10, 2, 2);
	points.push(pp, Back);


	pp = Point::NewPoint(2, 10, 20);
	points.push(pp, Back);


	pp = Point::NewPoint(12, 2, 25);
	points.push(pp, Back);

	pp = Point::NewPoint(0, 18, 1);
	points.push(pp, Back);

	pp = Point::NewPoint(17, 29, 1);
	points.push(pp, Back);

	pp = Point::NewPoint(58, 0, 0);
	points.push(pp, Back);

	pp = Point::NewPoint(0, 1, 45);
	points.push(pp, Back);

	pp = Point::NewPoint(12, 12, 12);
	points.push(pp, Front);


	pp = Point::NewPoint(22, 22, 22);
	points.push(pp, Back);


	int x = 0; 
	int y = 0;
	int z = 0;



	while (true) {
		Point::point p;
		cin >> com;

		if (com == '+' || com == 'e') {
			cin >> x >> y >> z;

			if (com == '+') {
				p = Point::NewPoint(x, y, z);
				points.push(p, Back);
			}
			else {
				cout << "Selected List has " << points.size() << " of elements." << endl << endl << endl << endl << endl;
				// memory error 
				
				p = Point::NewPoint(x,y,z);
				points.push(p, Front);
			}



			points.print();
			continue;
		}
		else {
			switch (com)
			{
			case '-':
				points.pop(Back);
				points.print();
				break;
			case 'd':
				points.pop(Front);
				points.print();
				break;
			case 'i':
				cout << "Selected List has " << points.size() << " of elements." << endl << endl << endl << endl << endl;
				break;
			case 'c':
				points.clear();
				cout << "List Cleared" << endl;
				break;
			case 'm':
				Point::print(points.furthest());
				break;
			case 'n':
				Point::print(points.nearest());
				break;
			case 'a':
				if (!points.isSorted) {
					points.ArrangeByDistance(Ascending);
					points.isSorted = true;
					points.print();
					break;
				} 
				points.isSorted = false;
				points.print();
				break;

			case 's':
				if (!points.isSorted) {
					points.ArrangeByDistance(Decending);
					points.isSorted = true;
					points.print();
					break;
				}
				points.isSorted = false;
				points.print();
				break;
			
			case 'q':
				return;


			default:
				break;
			}




		}





	}


































	
	points.push(pp, Front);
	points.print();

	pp = Point::NewPoint(2, 2, 2);
	points.push(pp, Front);
	points.print();

	pp = Point::NewPoint(5, 2, 3);
	points.push(pp, Back);
	points.print();

	points.pop(Front);
	points.print();


	//p = Point::NewPoint(10, 19, 14);
	//points.push(p, Back);
	//points.print();

	//p = Point::NewPoint(20, 19, 14);
	//points.push(p, Back);
	//points.print();

	//p = Point::NewPoint(1, 0, 0);
	//points.push(p, Back);
	//points.print();

	cout << "Arranged" << endl;
	points.ArrangeByDistance(Ascending);

	


	cout << "Arranged" << endl;
	points.ArrangeByDistance(Decending);






}


