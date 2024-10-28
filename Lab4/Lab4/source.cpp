#include<iostream>
using namespace std;

struct Student
{
private:
	int id = -1;
	char* name = nullptr;
	char* address = nullptr;
	char* phone = nullptr;
	char* email = nullptr;

public:
	void display_name()
	{
		cout << endl << "The name is: " << name << endl;
	}
	
	void set_id(int id)
	{
		this->id = id;
	}

	int get_id()
	{
		return this->id; //this=a pointer to an objects in that struct
	}

	void set_name(char* _name)
	{
		this->name = _name; //NO!! - shallow copy (we copy the address and not the value)//

		this->name = new char[strlen(_name) + 1];
		strcpy_s(this->name, strlen(_name) + 1, _name); //deep copy (i get the value, i allocate the new addres, i copy to the new address)
	}

	char* get_name()
	{
		return this->name; //NO!//
	}
};

int main()
{
	Student a;
	a.display_name();

	Student* b;
	b->display_name();

	Student first_student;

	first_student.set_id(12);

	char my_name[32] = "Lates Ionut";
	first_student.set_name((char*)my_name);

	my_name[0] = '#';

	////when we deal w pointers, 1st step => allocaate pointers
	//first_student.name = new char[32];
	//strcpy_s(first_student.name, strlen("Popescu Ionut") + 1, "Popescu Ionut"); //we can use strlen for copy functions even if its hardcoded

	//first_student.address = new char[12];
	//strcpy_s(first_student.email, 10, "Bucuresti");

	//first_student.email = new char[32];
	//strcpy_s(first_student.email, 19, "popescu@gmail.com");

	//first_student.phone = new char[32];
	//strcpy_s(first_student.email, 13, "+487222222111");

	//first_student.display_name();

	//Student s2;

	//char tmp[128]; //we use this tmp bc we use it for everything; just 1 variable bc we wil override it

	//cout << "Type the name:";
	//cin.getline(tmp, 128);
	////cin >> tmp;

	//s2.name = new char[strlen(tmp) + 1];
	//strcpy_s(s2.name, strlen(tmp) + 1, tmp);

	////finish create obj s2

	//cout << "Type the address:";
	//cin.getline(tmp, 128);

	//s2.address = new char[strlen(tmp) + 1];
	//strcpy_s(s2.address, strlen(tmp) + 1, tmp);
	//

	return 0;
}