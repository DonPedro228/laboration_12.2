#include <iostream>
using namespace std;


typedef int Info;
struct Elem
{
	Elem* link;
	Info info;
};

void push(Elem*& top, Info value);
Info pop(Elem*& top);
void Add(Elem*& top);
bool Not_Nezrustania(Elem* top);

int main() {
	Elem* top = NULL;

	cout << "Enter elements of the list in non-descending order (or -1 to end input):\n";
	Add(top);

	cout << "List elements: ";
	Elem* current = top;
	while (current != nullptr) {
		cout << current->info << " ";
		current = current->link;
	}
	cout << endl;

	if (Not_Nezrustania(top))
		cout << "The list is sorted in non-descending order.\n";
	else
		cout << "The list is not sorted in non-descending order.\n";


	return 0;
}

void Add(Elem*& top) {
	int value;
	while (true) {
		cout << "Enter element (or -1 to end input): ";
		cin >> value;
		if (value == -1)
			break;
		push(top, value);
	}
}


void push(Elem*& top, Info value)
{
	Elem* tmp = new Elem; 
	tmp->info = value; 
	tmp->link = top; 
	top = tmp; 
}

Info pop(Elem*& top)
{
	Elem* tmp = top->link;
	Info value = top->info; 
	delete top; 
	top = tmp; 
	return value; 
}

bool Not_Nezrustania(Elem* top) {
	if (top == nullptr || top->link == nullptr) {
		return true; 
	}

	Elem* current = top;
	while (current->link != nullptr) {
		if (current->info > current->link->info) {
			return false; 
		}
		current = current->link;
	}
	return true; 
}

