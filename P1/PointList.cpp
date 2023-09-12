#pragma once
#include "PointList.h"


using namespace std;


void PointListrun::Run() {
	List::PointList points;
	
	Point::point p = Point::NewPoint(1, 1, 1);
	points.push(p, Front);
	points.print();

	p = Point::NewPoint(2, 2, 2);
	points.push(p, Front);
	points.print();

	p = Point::NewPoint(5, 2, 3);
	points.push(p, Back);
	points.print();

	points.pop(Front);
	points.print();


	p = Point::NewPoint(10, 19, 14);
	points.push(p, Back);
	points.print();

	p = Point::NewPoint(20, 19, 14);
	points.push(p, Back);
	points.print();

	p = Point::NewPoint(1, 0, 0);
	points.push(p, Back);
	points.print();



	Point::print(points.furthest());
	Point::print(points.nearest());


	points.clear();




	p = Point::NewPoint(20, 19, 14);
	points.push(p, Back);
	points.print();

	p = Point::NewPoint(1, 0, 0);
	points.push(p, Back);
	points.print();


	List::PointList newlist(points);

	newlist.print();



}


