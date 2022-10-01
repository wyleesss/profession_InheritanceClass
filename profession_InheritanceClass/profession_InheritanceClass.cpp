#include <iostream>
#include <string>
using namespace std;

class Person {
	string name;
	string surname;
	string mobile_number;
	string birth_data;
	short age;
public:
	Person() :name("unknown"), surname("unknown"), mobile_number("+0"), birth_data("00.00.0000"), age(0) {}
	Person(string name, string surname, string mobile_number, string birth_data, short age) :
		name(name), surname(surname), mobile_number(mobile_number), birth_data(birth_data), age(age) {}
	void setName(string& name) { this->name = name; }
	void setSurname(string& surname) { this->surname = surname; }
	void setMobileNumber(string& mobile_number) { this->mobile_number = mobile_number; }
	void setBirthData(string& day, string& month, string& year) {
		birth_data = day + "." + month + "." + year;
	}
	void setBirthData(short day, short month, short year) {
		birth_data = to_string(day) + "." + to_string(month) + "." + to_string(year);
	}
	void setAge(short age) { this->age = age; }
	string getName() { return name; }
	string getSurname() { return surname; }
	string getMobileNumber() { return mobile_number; }
	string getBirthData() { return birth_data; }
	short getAge() { return age; }
	void info() {
		cout << "\n----------------------------\n|NAME          |" << name
			<< "\n|SURNAME       |" << surname
			<< "\n|BIRTHDAY      |" << birth_data
			<< "\n|AGE           |" << age
			<< "\n|MOBILE_NUMBER |" << mobile_number << "\n----------------------------\n";
	}
};

class ProfActivity {
	string last_work_place;
	string last_work_start_date;
	int hourly_payment;
public:
	ProfActivity() :last_work_place("unknown"), last_work_start_date("00.00.0000"), hourly_payment(0) {}
	ProfActivity(string last_work_place, string last_work_start_date, int hourly_payment) :
		last_work_place(last_work_place), last_work_start_date(last_work_start_date), hourly_payment(hourly_payment) {};
	void setLastWorkPlace(string& last_work_place) { this->last_work_place = last_work_place; }
	void setLastWorkStartDate(string& last_work_start_date) { this->last_work_start_date = last_work_start_date; }
	void setHourlyPayment(int hourly_payment) { this->hourly_payment = hourly_payment; }
	string getLastWorkPlace() { return last_work_place; }
	string getLastWorkStartDate() { return last_work_start_date; }
	int getHourlyPayment() { return hourly_payment; }
	void info() {
		cout << "\n-------------------------------------------------------------------\n|LAST_WORK_PLACE            |" << last_work_place
			<< "\n|LAST_WORK_START_DATE       |" << last_work_start_date
			<< "\n|HOURLY_PAYMENT             |" << hourly_payment << "$\n-------------------------------------------------------------------\n";
	}
};

class ITProfession :public Person, public ProfActivity {
	string qualification;
public:
	ITProfession() :Person(), ProfActivity(), qualification("unknown") {}
	ITProfession(string name, string surname, string mobile_number, string birth_data, short age,
		string last_work_place, string last_work_start_date, int hourly_payment,
		string qualification) :
		Person(name, surname, mobile_number, birth_data, age), ProfActivity(last_work_place, last_work_start_date, hourly_payment),
		qualification(qualification) {};
	void setQualification(string& qualification) { this->qualification = qualification; }
	string getQualification() { return qualification; }
	void info() {
		cout << "\n/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/\nPERSON_INFO'";
		Person::info();
		cout << "\nPROFESSIONAL_ACTIVITY_INFO'";
		ProfActivity::info();
		cout << "\nPROFESSION_ATTRIBUTES'\n-------------------------------------------------------------------\n|QUALIFICATION              |" << 
			qualification << "\n-------------------------------------------------------------------\n" <<
			"/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/\n";
	}
};

int main() {

	Person SMP("Jack", "Rest", "+1467302347", "03.10.1999", 24);
	SMP.info();
	ProfActivity SMPA("USA IT Company Java Senior Programmer", "03.10.2021", 133);
	SMPA.info();
	cout << "\n\n\n";
	ITProfession SM("Jack", "Rest", "+1467302347", "03.10.1999", 24, "USA IT Company Java Senior Programmer", "03.10.2021", 133, "High");
	SM.info();

}