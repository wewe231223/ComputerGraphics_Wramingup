#include "PointList.h"


using namespace std;
using namespace List;





template <typename T>
class Data {

private:
	T** List;

public:

	Data(int a) {

	}


	Data(const Data& other) {
		this->List = other.List;
	}


};