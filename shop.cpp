#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <exception>

using namespace std;


//// ROBOT PART ////
class Robot_Part
{
protected:
	Robot_Part(string name, int model_number, double cost, string description, string image_filename)
		: name(name), model_number(model_number), description(description), image_filename(image_filename) { }

	string name;
	int model_number;
	double cost;
	string description;
	string image_filename;

public:
	virtual string to_string();
};

string Robot_Part::to_string()
{
	stringstream part_stream;
	part_stream << "Name: " << name << "\nModel Number: " << model_number << "\nCost: " << cost << "\nDescription: " << description;
	string part_string = part_stream.str();
	part_stream.str("");
	part_stream.clear();
	return part_string;
}


//// HEAD ////
class Head : public Robot_Part
{
private:

	double power;

public:
	Head(string name, int model_number, double cost, string description, string image_filename, double power)
		: Robot_Part(name, model_number, cost, description, image_filename),
		power(power) {}

	string to_string();
};

string Head::to_string()
{
	stringstream head_stream;
	head_stream << Robot_Part::to_string() << "\nPower: " << power;
	string head_string = head_stream.str();
	head_stream.str("");
	head_stream.clear();
	return head_string;
}

//// LOCOMOTOR ////
class Locomotor : public Robot_Part
{
private:

	double max_power;

public:
	Locomotor(string name, int model_number, double cost, string description, string image_filename, double max_power)
		: Robot_Part(name, model_number, cost, description, image_filename),
		max_power(max_power) {}
	string to_string();
};

string Locomotor::to_string()
{
	stringstream locomotor_stream;
	locomotor_stream << Robot_Part::to_string() << "\nMax Power: " << max_power;
	string locomotor_string = locomotor_stream.str();
	locomotor_stream.str("");
	locomotor_stream.clear();
	return locomotor_string;
}

//// ARM ////
class Arm : public Robot_Part
{
private:

	double max_power;

public:
	Arm(string name, int model_number, double cost, string description, string image_filename, double max_power)
		: Robot_Part(name, model_number, cost, description, image_filename),
		max_power(max_power) {}

	string to_string();
};

string Arm::to_string()
{
	stringstream arm_stream;
	arm_stream << Robot_Part::to_string() << "\nMax Power: " << max_power;
	string arm_string = arm_stream.str();
	arm_stream.str("");
	arm_stream.clear();
	return arm_string;
}

//// BATTERY ////
class Battery : public Robot_Part
{
private:

	double power_available;
	double max_energy;

public:
	Battery(string name, int model_number, double cost, string description, string image_filename, double power_available, double max_energy)
		: Robot_Part(name, model_number, cost, description, image_filename),
		power_available(power_available), max_energy(max_energy) {}

	string to_string();
};

string Battery::to_string()
{
	stringstream battery_stream;
	battery_stream << Robot_Part::to_string() << "\nPower Available: " << power_available << "\nMax Energy: " << max_energy;
	string battery_string = battery_stream.str();
	battery_stream.str("");
	battery_stream.clear();
	return battery_string;
}

//// TORSO ////
class Torso : public Robot_Part
{
private:

	double battery_compartments;
	double max_arms;

public:
	Torso(string name, int model_number, double cost, string description, string image_filename, int battery_compartments, int max_arms)
		: Robot_Part(name, model_number, cost, description, image_filename),
		battery_compartments(battery_compartments), max_arms(max_arms) {}


	string to_string();
};

string Torso::to_string()
{
	stringstream torso_stream;
	torso_stream << Robot_Part::to_string() << "\nBattery Compartments: " << battery_compartments << "\nMax Arms: " << max_arms;
	string torso_string = torso_stream.str();
	torso_stream.str("");
	torso_stream.clear();
	return torso_string;
}

//// SHOP ////
class Shop
{
public:
	void create_new_head(Head head);
	void create_new_locomotor(Locomotor locomotor);
	void create_new_arm(Arm arm);
	void create_new_torso(Torso torso);
	void create_new_battery(Battery battery);

	int number_of_heads();
	int number_of_locomotors();
	int number_of_arms();
	int number_of_torsos();
	int number_of_batteries();

	string heads_to_string(int part_index);
	string locomotors_to_string(int part_index);
	string arms_to_string(int part_index);
	string torsos_to_string(int part_index);
	string batteries_to_string(int part_index);

private:
	vector<Head> heads;
	vector<Locomotor> locomotors;
	vector<Arm> arms;
	vector<Torso> torsos;
	vector<Battery> batteries;

};


void Shop::create_new_head(Head head) {
	heads.push_back(head);
}

void Shop::create_new_locomotor(Locomotor locomotor) {
	locomotors.push_back(locomotor);
}

void Shop::create_new_arm(Arm arm) {
	arms.push_back(arm);
}

void Shop::create_new_torso(Torso torso) {
	torsos.push_back(torso);
}

void Shop::create_new_battery(Battery battery) {
	batteries.push_back(battery);
}

int Shop::number_of_heads() {
	return heads.size();
}

int Shop::number_of_locomotors() {
	return locomotors.size();
}

int Shop::number_of_arms() {
	return arms.size();
}

int Shop::number_of_torsos() {
	return torsos.size();
}

int Shop::number_of_batteries() {
	return batteries.size();
}

string Shop::heads_to_string(int part_index) {
	return heads[part_index].to_string();
}

string Shop::locomotors_to_string(int part_index) {
	return locomotors[part_index].to_string();
}

string Shop::arms_to_string(int part_index) {
	return arms[part_index].to_string();
}

string Shop::torsos_to_string(int part_index) {
	return torsos[part_index].to_string();
}

string Shop::batteries_to_string(int part_index) {
	return batteries[part_index].to_string();
}





//// VIEW ////
class View {
public:
	View(Shop& shop) : shop(shop) { }
	string get_menu();
	string get_head_list();
	string get_locomotor_list();
	string get_arm_list();
	string get_torso_list();
	string get_battery_list();

private:
	Shop& shop;
};

string View::get_menu() {
	string menu = R"(
===============================
  Domo Arigato Shop O' Roboto
===============================

(1) Create Robot Part
(2) List Robot Parts


(0) Exit 
)";
	return menu;
}


string View::get_head_list() {
	string list = R"(
-------------------
List of Robot Heads
-------------------
)";
	for (int i = 0; i<shop.number_of_heads(); ++i) {
		list += std::to_string(i) + ") " + shop.heads_to_string(i) + '\n';
	}
	return list;
}

string View::get_locomotor_list() {
	string list = R"(
------------------------
List of Robot Locomotors
------------------------
)";
	for (int i = 0; i<shop.number_of_locomotors(); ++i) {
		list += std::to_string(i) + ") " + shop.locomotors_to_string(i) + '\n';
	}
	return list;
}

string View::get_arm_list() {
	string list = R"(
------------------
List of Robot Arms
------------------
)";
	for (int i = 0; i<shop.number_of_arms(); ++i) {
		list += std::to_string(i) + ") " + shop.arms_to_string(i) + '\n';
	}
	return list;
}

string View::get_torso_list() {
	string list = R"(
--------------------
List of Robot Torsos
--------------------
)";
	for (int i = 0; i<shop.number_of_torsos(); ++i) {
		list += std::to_string(i) + ") " + shop.torsos_to_string(i) + '\n';
	}
	return list;
}

string View::get_battery_list() {
	string list = R"(
-----------------------
List of Robot Batteries
-----------------------
)";
	for (int i = 0; i<shop.number_of_batteries(); ++i) {
		list += std::to_string(i) + ") " + shop.batteries_to_string(i) + '\n';
	}
	return list;
}




//// CONTROLLER ////
class Controller {
public:
	Controller(Shop& shop, View& view) : shop(shop), view(view) { }
	void cli();
	void execute_cmd(int cmd);
private:
	int get_int(string prompt, int max_int);
	Shop& shop;
	View& view;
};

void Controller::cli() {
	int cmd = -1;
	while (cmd != 0) {
		cout << view.get_menu() << endl;
		cout << "Command? ";
		cin >> cmd;
		cin.ignore(); // consume \n
		execute_cmd(cmd);
	}
}

int Controller::get_int(string prompt, int max_int) {
	int result;
	while (true) {
		cout << prompt;
		cin >> result;
		cin.ignore(); // consume \n
		if (0 <= result && result <= max_int) break;
		cout << "Please enter an integer between 0 and " << max_int << endl;
	}
	return result;
}

void Controller::execute_cmd(int cmd)
{
	if (cmd == 1)
	{
		string name, description;
		int model_number;
		double cost;

		cout << "Part Type? " << endl;
		cout << "0) Head" << endl;
		cout << "1) Locomotor" << endl;
		cout << "2) Arm" << endl;
		cout << "3) Torso" << endl;
		cout << "4) Battery" << endl;

		int type = get_int("Selection: ", 5);


		cout << "Name? ";
		getline(cin, name);

		cout << "Model Number? ";
		model_number = get_int("", 999999999);

		cout << "Description? ";
		getline(cin, description);

		cout << "Cost? ";
		cin.clear();
		cin >> cost;

		switch (type) {
		case 0:
		{
			double power;
			cout << "Power? ";
			cin.clear();
			cin >> power;
			shop.create_new_head(Head(name, model_number, cost, description, "", power));
			break;
		}
		case 1:
		{
			double max_power;
			cout << "Max Power? ";
			cin.clear();
			cin >> max_power;
			shop.create_new_locomotor(Locomotor(name, model_number, cost, description, "", max_power));
			break;
		}
		case 2:
		{
			double max_power;
			cout << "Max Power? ";
			cin.clear();
			cin >> max_power;
			shop.create_new_arm(Arm(name, model_number, cost, description, "", max_power));
			break;
		}
		case 3:
		{
			int battery_compartments;
			int max_arms;
			cout << "Battery Compartments? ";
			battery_compartments = get_int("", 10);
			cout << "Max Arms? ";
			max_arms = get_int("", 10);
			shop.create_new_torso(Torso(name, model_number, cost, description, "", battery_compartments, max_arms));
			break;
		}
		case 4:
		{
			double power_available;
			double max_energy;
			cout << "Power Available? ";
			cin.clear();
			cin >> power_available;
			cout << "Max Energy? ";
			cin.clear();
			cin >> max_energy;
			shop.create_new_battery(Battery(name, model_number, cost, description, "", power_available, max_energy));
			break;
		}
		}

	}

	else if (cmd == 2) {
		cout << "Part Type? " << endl;
		cout << "0) Head" << endl;
		cout << "1) Locomotor" << endl;
		cout << "2) Arm" << endl;
		cout << "3) Torso" << endl;
		cout << "4) Battery" << endl;

		int type = get_int("Selection: ", 5);

		switch (type)
		{
		case 0:
			cout << view.get_head_list();
			break;
		case 1:
			cout << view.get_locomotor_list();
			break;
		case 2:
			cout << view.get_arm_list();
			break;
		case 3:
			cout << view.get_torso_list();
			break;
		case 4:
			cout << view.get_battery_list();
			break;
		}

	}
	else if (cmd == 0)
	{
		exit(0);
	}
	else
	{
		cerr << "**** Invalid command! ****" << endl << endl;
	}
}


int main()
{
	Shop shop;
	View view{ shop };
	Controller controller(shop, view);
	controller.cli();
}