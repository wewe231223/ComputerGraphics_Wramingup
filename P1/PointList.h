﻿#pragma once
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;


#define NULLCORD -0xffff
#define LISTMAX 10

enum Mode {
	Front,
	Back
};

enum Arrange {
	Ascending,
	Decending

};

namespace Point {

	typedef struct Point_ {
		int x = NULLCORD;
		int y = NULLCORD;
		int z = NULLCORD;

	}point;

	inline point NewPoint(int x, int y, int z) {
		point result;
		result.x = x;
		result.y = y;
		result.z = z;
		

		return result;
	}

	inline point Nullpoint() {
		point p;
		return p;
	}

	inline double Distance(const point& p) {
		return sqrt(
			pow(static_cast<double>(p.x), 2.0f) +
			pow(static_cast<double>(p.y), 2.0f) +
			pow(static_cast<double>(p.z), 2.0f)
		);
	}


	inline void print(point p) {
		cout << "Selected Point Coordinate : ( " << p.x << " , " << p.y << " , " << p.z << " )" << endl << endl << endl << endl << endl;
	}


}

namespace Cp {

	inline int compare_Asc(const void* a,const void* b){
		
		int result = 0;


		Point::point* pointA = (Point::point*)a;
		Point::point* pointB = (Point::point*)b;



		Point::Distance(*pointA) < Point::Distance(*pointB) ? result = -1 : result = 1;

		return result;

	}

	inline int compare_Dec(const void* a, const void* b) {

		int result = 0;


		Point::point* pointA = (Point::point*)a;
		Point::point* pointB = (Point::point*)b;



		Point::Distance(*pointA) < Point::Distance(*pointB) ? result = 1 : result = -1;

		return result;

	}




}



namespace List {
	class PointList {
	private:
		Point::point* list;
		List::PointList* Arranged;
		int current = 0;
	public:
		bool isSorted = false;




	public:


		PointList() {
			this->list = new Point::point[10];
			this->Arranged = nullptr;
			for (auto i = 0; i < 10; ++i) {
				Point::point p;
				this->list[i] = p;
			}
		}



		PointList(PointList& other) {
			this->list = new Point::point[10];
			memcpy(this->list, other.list,sizeof(Point::point) * 10);
			this->current = other.current;
		}






		void print() {
			cout << "< Coordinate >" << endl << endl;


			if (this->isSorted) {
				cout << "List is Sorted" << endl;
				for (auto i = 0; i < this->Arranged->current; ++i) {
					cout << i << " :	( " << this->Arranged->list[i].x << " , " << this->Arranged->list[i].y << " , " << this->Arranged->list[i].z << " )" << endl;
				}
			}
			else {
				cout << "List is not Sorted" << endl;
				for (auto i = 0; i < this->current; ++i) {
					if (this->list[i].x == NULLCORD) {
						cout << i << " :	" << "NONE" << endl;
					}
					else {
						cout << i << " :	( " << this->list[i].x << " , " << this->list[i].y << " , " << this->list[i].z << " )" << endl;
					}
				}

			}


			


			cout << endl << endl << endl << endl << endl;
		}



		void push(Point::point& data,Mode pm) {

			// 1. if list has blank in index 0
			if (this->list[0].x == NULLCORD && this->current != 0) {
				this->list[0] = data;

				return;
			}

			// 2.if list is full of data 
			if (this->current == LISTMAX) {
				cout << "Invalid Push" << endl;
				return;
			}

			// 3.
			if (pm == Mode::Front) {
				Point::point* newlist = new Point::point[10];

				for (auto i = 0; i < current; ++i){
					newlist[i + 1] = this->list[i];
				}

				newlist[0] = data;
				this->current += 1;

				//delete[] this->list;
				this->list = newlist;

				return;
			}

			if (pm == Mode::Back) {
				this->list[this->current++] = data;
			}
			return;
		}


		void pop(Mode m) {

		
			if (m == Mode::Back) {
				
				this->list[this->current] = Point::Nullpoint();
				current -= 1;

			}
			if (m == Mode::Front) {
				this->list[0] = Point::Nullpoint();
			}


		}



		int size() {
			int result = 0;

			if (this->list[0].x == NULLCORD) {
				result = this->current - 1;
			}
			else {
				result = this->current;
			}


			return result;

		}


		void clear() {
			Point::point* newList_a = new Point::point[10];

			if (this->Arranged != nullptr) {
				this->Arranged->clear();
			}

			delete[] this->list;
			this->list = newList_a;

			this->current = 0;

		}


		Point::point furthest() {
			Point::point result;
			double dis = 0.0f;
			double disbuffer = 0.0f;
			for (auto i = 0; i < this->current; ++i) {
				disbuffer = 0.0f;
				if (this->list[i].x == NULLCORD) continue;
				if ((disbuffer = Point::Distance(this->list[i])) > dis) {
					dis = disbuffer;
					result = this->list[i];
				}
			}

			return result;
		}

		Point::point nearest() {
			Point::point result;
			double dis = 100000.0f;
			double disbuffer = 0.0f;
			for (auto i = 0; i < this->current; ++i) {
				disbuffer = 0.0f;
				if (this->list[i].x == NULLCORD) continue;
				if ((disbuffer = Point::Distance(this->list[i])) < dis) {
					dis = disbuffer;
					result = this->list[i];
				}
			}

			return result;

		}
	
		
		void ArrangeByDistance(Arrange mode) {

			this->Arranged = new List::PointList(*this);

			if (this->Arranged->list[0].x == NULLCORD && this->Arranged->current != 0) {
				for (auto i = 1; i < this->Arranged->current; ++i) {
					this->Arranged->list[i - 1] = this->Arranged->list[i];
				}

				this->Arranged->current -= 1;
			}


			if (mode == Ascending) {
				qsort(this->Arranged->list, this->Arranged->current, sizeof(Point::point), Cp::compare_Asc);
				
			}



			if (mode == Decending) {
				qsort(this->Arranged->list, this->Arranged->current, sizeof(Point::point), Cp::compare_Dec);
			}


			

	
		}







	};








}


namespace PointListrun {
	// this fuctioning like main
	void Run();


}