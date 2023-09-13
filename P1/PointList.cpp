#pragma once
#include "PointList.h"


using namespace std;


void PointListrun::Run() {


	List::PointList points;


	char com;
	
	bool isAranged = false;



	int x = 0; 
	int y = 0;
	int z = 0;



	//Point::point p;

	//p = Point::NewPoint(0, 1, 0);
	//points.push(p, Back);
	//points.print();


	//p = Point::NewPoint(0, 1, 1);
	//points.push(p, Back);
	//points.print();

	//points.pop(Back);
	//points.print();


	//p = Point::NewPoint(1, 1, 1);
	//points.push(p, Front);
	//points.print();



	//p = Point::NewPoint(1, 0, 1);
	//points.push(p, Front);
	//points.print();



	//p = Point::NewPoint(1, 1, 0);
	//points.push(p, Back);
	//points.print();


	//points.pop(Front);
	//points.print();


	//if (!points.isSorted) {
	//	points.ArrangeByDistance(Decending);
	//	points.isSorted = true;
	//	points.print();
	//}
	//else {
	//	points.isSorted = false;
	//	points.print();
	//}



	//points.isSorted = false;





	//if (!points.isSorted) {
	//	points.ArrangeByDistance(Ascending);
	//	points.isSorted = true;
	//	points.print();	
	//}
	//else {
	//	points.isSorted = false;
	//	points.print();
	//}







	//Point::print(points.furthest());
	//Point::print(points.nearest());

	//cout << "Selected List has " << points.size() << " of elements." << endl << endl << endl << endl << endl;




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


































	

}


