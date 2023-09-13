#include "CardFlip.h"


using namespace std;

void CardFliprun::Run() {

	CardFlip::CardFlip* Cards = new CardFlip::CardFlip;
	

	char i;
	int x;
	int y;

	while (true) {
		int x{};
		int y{};
		char i = NULL;

		Cards->print();


		cin >> i;


		if (i == 'r') {
			Cards = new CardFlip::CardFlip{ };
			Cards->print(); 
			continue;
		}



		cin >> y;
		x = (int)(i - '0');


		

		if (Cards->times == 20) {
			Cards = new CardFlip::CardFlip;
			continue;
		}






		if (x >= 4 || y >= 4) {
			continue;
		}
		else {
			Cards->CardSelect(x, y);
		}




	}

}