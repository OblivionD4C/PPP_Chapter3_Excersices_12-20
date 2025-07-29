// read and write a first name
#include "PPP.h"
int main()
{
	cout << "Please enter first name of a person you want to write a letter to:\n";
	string first_name; // first_name is a variable of type string
	cin >> first_name; // read characters into first_name
	cout << "Dear " << first_name << "\n";
	cout << " how are you? I miss you" << "\n" << "I wanted to let you know i bought a national park.\nisnt that amazing?\n";
	cout << "enter first name of another friend:\n";
	string friend_name;
	cin >> friend_name;
	cout << " have you seen " << friend_name << "?\n im worried i didnt see them for a while \n";
	cout << "enter age of recpient:\n ";
	int age;
	cin >> age;
	if (age <= 0 || age >= 110) // my mistake here was using && for and and not || for or , the code simply didnt recognise thee mistake in the age
	{
		simple_error("youre kidding!");
	}
	cout << " i hear you jusr had a bd and you are " << age << "years old \n";
	if (age <= 12)
	{
		cout << " next year you will be" << age + 1 << "\n";

	}
	if (age == 17)
	{
		cout << "next year you can vote uau\n";
	}
	if (age >= 70)
	{
		cout << " are you retired ? \n";
	}
}