#pragma once
#include <vector>



using namespace std;


#define NULLCORD 0xffff
#define LISTMAX 10

enum PushMode {
	Front,
	Back
};
typedef struct Point_ {
	int x = NULLCORD;
	int y = NULLCORD;
	int z = NULLCORD;

}point;


namespace List {
	class PointList {
	private:
		point* list;
		int current = 0;
		
	public:
		PointList() {
			this->list = new point[10];
		}

		class iterator {
		private:
			point* ptr;
		public:
			iterator(point* p) : ptr(p) {}
			
			iterator& operator++() {
				this->ptr += 1;
				return *this;
			}

		};




















		void push(point& data,PushMode pm) {

			// 1. if list has blank in index 0
			if (this->list[0].x == NULLCORD) {
				this->list[0] = data;
				return;
			}

			// 2.if list is full of data 
			if (this->current == LISTMAX) {
				cout << "Invalid Push" << endl;
				return;
			}

			// 3.
			if (pm == PushMode::Front) {
				point* newlist = new point[10];

				


			}


			this->list[this->current++] = data;
			return;

		}



	};








}