#pragma once



typedef struct Point_ {
	int x;
	int y;
	int z;
}point;


/*
•+ x y z: 리스트의 맨 위에 입력 (x, y, z: 숫자
•
•--: 리스트의 맨 위에서 삭제한다
•
e x y z: 리스트의 맨 아래에 입력 명령어 와 반대의 위치 , 리스트에 저장된 데이터값이 위로 올라간다
•
d: 리스트의 맨 아래에서 삭제한다 . 리스트에서 삭제된 칸이 비어있다
•
l: 리스트에 저장된 점의 개수를 출력한다
•
c: 리스트를 비운다 . 리스트를 비운 후 다시 입력하면 0 번부터 저장된다
•
m: 원점에서 가장 먼 거리에 있는 점의 좌표값을 출력한다
•
n: 원점에서 가장 가까운 거리에 있는 점의 좌표값을 출력한다
•
a: 원점과의 거리를 정렬하여 오름차순으로 정렬하여 출력한다 . 인덱스 0 번부터 빈 칸없이 저장하여 출력한다 .
•
s: 원점과의 거리를 정렬하여 내림차순으로 정렬하여 출력한다 . 다시 a 또는 s 를 누르면 원래의 인덱스 위치에 출력한다
•
q: 프로그램을 종료한다

*/
namespace List{

	template<typename T = point>
	class Node {
		T data;
		Node<T>* next;
		Node(const T& d, Node* ptr) : data(d), next(ptr) {
		

		
		};







	};






	template<typename T>
	class Myiterator {
	private:
		T* cur;
	public:
		Myiterator(Node<T>* p = nullptr) : cur(p) {};

		Myiterator& operator++() {
			this->cur = this->cur->next();
			return *this;
		}

		T& operator*() {
			return cur->data;
		}

		bool operator == (const Myiterator& other) {
			return cur == other.cur;
		}

		bool operator != (const Myiterator& other) {
			return cur != other.cur;
		}


	};

	

	template <typename T = point>
	class Data {

	private:
		Node<T>* head;


	public:

		Data() : head(nullptr) {};

		void push_front(const T& d) {
			head = new Node<T>(d, this->head);
		}


		typedef Myiterator<T> iterator;

		iterator begin() {
			
		}





	};










}

