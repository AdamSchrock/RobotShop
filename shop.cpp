#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <exception>
#include <limits>

using namespace std;


//// ROBOT PART ////
class Robot_Part
{
protected:
	Robot_Part(string name, int model_number, double cost, string description, string image_filename)
		: name(name), model_number(model_number), cost(cost), description(description), image_filename(image_filename) { }

	string name;
	int model_number;
	double cost;
	string description;
	string image_filename;

public:
	virtual string to_string();
	double get_cost();
	string get_name();
	virtual void file_write(string filename);
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

string Robot_Part::get_name()
{
	return name;
}

double Robot_Part::get_cost()
{
	return cost;
}

void Robot_Part::file_write(string filename)
{
	std::ofstream ofs(filename, std::ofstream::app);

	ofs << name << endl;
	ofs << model_number << endl;
	ofs << cost << endl;
	ofs << description << endl;
	ofs << image_filename << endl;

	ofs.close();

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
	void file_write(string filename);
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

void Head::file_write(string filename)
{
	Robot_Part::file_write(filename);

	std::ofstream ofs(filename, std::ofstream::app);

	ofs << power << endl;

	ofs.close();

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
	void file_write(string filename);
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

void Locomotor::file_write(string filename)
{
	Robot_Part::file_write(filename);

	std::ofstream ofs(filename, std::ofstream::app);

	ofs << max_power << endl;

	ofs.close();

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
	void file_write(string filename);
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

void Arm::file_write(string filename)
{
	Robot_Part::file_write(filename);

	std::ofstream ofs(filename, std::ofstream::app);

	ofs << max_power << endl;

	ofs.close();

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
	void file_write(string filename);
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

void Battery::file_write(string filename)
{
	Robot_Part::file_write(filename);

	std::ofstream ofs(filename, std::ofstream::app);

	ofs << power_available << endl;
	ofs << max_energy << endl;

	ofs.close();

}



//// TORSO ////
class Torso : public Robot_Part
{
private:

	int battery_compartments;
	int max_arms;

public:
	Torso(string name, int model_number, double cost, string description, string image_filename, int battery_compartments, int max_arms)
		: Robot_Part(name, model_number, cost, description, image_filename),
		battery_compartments(battery_compartments), max_arms(max_arms) {}


	string to_string();
	void file_write(string filename);

	int get_max_arms();
	int get_battery_compartments();
};

int Torso::get_max_arms()
{
	return max_arms;
}

int Torso::get_battery_compartments()
{
	return battery_compartments;
}

string Torso::to_string()
{
	stringstream torso_stream;
	torso_stream << Robot_Part::to_string() << "\nBattery Compartments: " << battery_compartments << "\nMax Arms: " << max_arms;
	string torso_string = torso_stream.str();
	torso_stream.str("");
	torso_stream.clear();
	return torso_string;
}


void Torso::file_write(string filename)
{
	Robot_Part::file_write(filename);

	std::ofstream ofs(filename, std::ofstream::app);

	ofs << battery_compartments << endl;
	ofs << max_arms << endl;

	ofs.close();

}


//// ROBOT_MODEL ////
class Robot_Model
{
private:
	string name;
	int model_number;
	Head head;
	Locomotor locomotor;
	Torso torso;
	vector<Arm> model_arms;
	vector<Battery> model_batteries;

public:
	Robot_Model(string name, int model_number, Head head, Locomotor locomotor, Torso torso, vector<Arm> model_arms, vector<Battery> model_batteries)
		: name(name), model_number(model_number), head(head), locomotor(locomotor), torso(torso), model_arms(model_arms), model_batteries(model_batteries) {}

	int get_model_max_arms();
	int get_model_battery_comparments();
	double get_cost();
	string to_string();
	string get_model_name();
	void file_write(string filename);
};

void Robot_Model::file_write(string filename)
{
	std::ofstream ofs(filename, std::ofstream::app);

	ofs << name << endl;
	ofs << model_number << endl;
	ofs << head.get_name() << endl;
	ofs << locomotor.get_name() << endl;
	ofs << torso.get_name() << endl;
	ofs << model_arms.size() << endl;
	for (vector<Arm>::iterator i = model_arms.begin(); i != model_arms.end(); ++i)
	{
		ofs << i->get_name() << endl;
	}
	ofs << model_batteries.size() << endl;
	for (vector<Battery>::iterator i = model_batteries.begin(); i != model_batteries.end(); ++i)
	{
		ofs << i->get_name() << endl;
	}

	ofs.close();
}

int Robot_Model::get_model_max_arms()
{
	return torso.get_max_arms();
}

int Robot_Model::get_model_battery_comparments()
{
	return torso.get_battery_compartments();
}

double Robot_Model::get_cost()
{
	double cost = 0.0;
	cost += head.get_cost();
	cost += locomotor.get_cost();
	cost += torso.get_cost();
	for (vector<Arm>::iterator i = model_arms.begin(); i != model_arms.end(); ++i)
	{
		cost += i->get_cost();
	}
	for (vector<Battery>::iterator i = model_batteries.begin(); i != model_batteries.end(); ++i)
	{
		cost += i->get_cost();
	}

	return cost;
}

string Robot_Model::get_model_name()
{
	return name;
}

string Robot_Model::to_string()
{
	int count = 0;
	stringstream model_stream;
	model_stream << "Model Name: " << name << "\nModel Number: " << model_number << "\nHead: " << head.get_name() << "\n" << locomotor.get_name() << "\nTorso: " << torso.get_name() << "\nArms: ";
	for (vector<Arm>::iterator i = model_arms.begin(); i != model_arms.end(); ++i)
	{
		model_stream << "\n" << count << ") " << i->get_name();
		count++;
	}
	model_stream << "\nBatteries: ";
	count = 0;
	for (vector<Battery>::iterator i = model_batteries.begin(); i != model_batteries.end(); ++i)
	{
		model_stream << "\n" << count << ") " << i->get_name();
		count++;
	}
	model_stream << "\nCost: " << get_cost();

	string model_string = model_stream.str();
	return model_string;
}





////CUSTOMER////
class Customer
{
private:
	string name;
	string phone_number;
	string email;

public:
	Customer(string name, string phone_number, string email) : name(name), phone_number(phone_number), email(email) {}
	
	string get_customer_name();
	string get_customer_phone_number();
	string get_customer_email();
	string to_string();
	void file_write(string filename);
};

void Customer::file_write(string filename)
{
	std::ofstream ofs(filename, std::ofstream::app);

	ofs << name << endl;
	ofs << phone_number << endl;
	ofs << email << endl;

	ofs.close();
}

string Customer::get_customer_name()
{
	return name;
}

string Customer::get_customer_phone_number()
{
	return phone_number;
}

string Customer::get_customer_email()
{
	return email;
}

string Customer::to_string()
{
	stringstream customer_stream;
	customer_stream << "Name: " << name << "\nPhone Number: " << phone_number << "\nEmail: " << email;


	string customer_string = customer_stream.str();
	return customer_string;
}




////SALES ASSOCIATE////
class Sales_Associate
{
private:
	string name;
	int employee_number;

public:
	Sales_Associate(string name, int employee_number) : name(name), employee_number(employee_number) {}

	string get_associate_name();
	int get_employee_number();
	string to_string();
	void file_write(string filename);
};


void Sales_Associate::file_write(string filename)
{
	std::ofstream ofs(filename, std::ofstream::app);

	ofs << name << endl;
	ofs << employee_number << endl;

	ofs.close();
}

string Sales_Associate::get_associate_name()
{
	return name;
}

int Sales_Associate::get_employee_number()
{
	return employee_number;
}

string Sales_Associate::to_string()
{
	stringstream associate_stream;
	associate_stream << "Name: " << name << "\nEmployee Number: " << employee_number;


	string associate_string = associate_stream.str();
	return associate_string;
}



////ORDER////
class Order
{
private:
	int order_number;
	string date;
	Customer customer;
	Sales_Associate sales_associate;
	Robot_Model robot_model;
	int status = 0;

public:
	Order(int order_number, string date, Customer customer, Sales_Associate sales_associate, Robot_Model robot_model) :
		order_number(order_number), date(date), customer(customer), sales_associate(sales_associate), robot_model(robot_model) {}

	int get_order_number();
	string get_order_date();
	int get_status();
	string to_string();
	void file_write(string filename);

};

void Order::file_write(string filename)
{
	std::ofstream ofs(filename, std::ofstream::app);

	ofs << order_number << endl;
	ofs << date << endl;
	ofs << customer.get_customer_name() << endl;
	ofs << sales_associate.get_associate_name() << endl;
	ofs << robot_model.get_model_name() << endl;
	ofs << status << endl;

	ofs.close();
}

int Order::get_order_number()
{
	return order_number;
}

string Order::get_order_date()
{
	return date;
}

int Order::get_status()
{
	return status;
}

string Order::to_string()
{
	stringstream order_stream;
	order_stream << "Order Number: " << order_number << "\nOrder Date: " << date << "\nCustomer: " << customer.get_customer_name()
		<< "\nSales Associate: " << sales_associate.get_associate_name() << " (" << sales_associate.get_employee_number() << ")\nModel: "
		<< robot_model.get_model_name() << "\nStatus: ";

	if (status == 0)
	{
		order_stream << "Pending";
	}
	else
	{
		order_stream << "Complete";
	}


	string order_string = order_stream.str();
	return order_string;
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
	void create_new_model(Robot_Model model);
	void create_new_customer(Customer customer);
	void create_new_associate(Sales_Associate sales_associate);
	void create_new_order(Order order);

	void save();
	void load();

	int number_of_heads();
	int number_of_locomotors();
	int number_of_arms();
	int number_of_torsos();
	int number_of_batteries();
	int number_of_models();
	int number_of_customers();
	int number_of_associates();
	int number_of_orders();

	string heads_to_string(int part_index);
	string locomotors_to_string(int part_index);
	string arms_to_string(int part_index);
	string torsos_to_string(int part_index);
	string batteries_to_string(int part_index);
	string models_to_string(int model_index);
	string customers_to_string(int customer_index);
	string associates_to_string(int associate_index);
	string orders_to_string(int order_index);

	vector<Head> heads;
	vector<Locomotor> locomotors;
	vector<Arm> arms;
	vector<Torso> torsos;
	vector<Battery> batteries;
	vector<Robot_Model> models;
	vector<Customer> customers;
	vector<Order> orders;
	vector<Sales_Associate> sales_associates;
};


void Shop::save()
{
	remove("Robot_Parts.txt");

	std::ofstream ofs("Robot_Parts.txt", std::ofstream::app);
	ofs << number_of_heads() << endl;
	ofs.close();
	for (int i = 0; i< number_of_heads(); ++i) {
		heads[i].file_write("Robot_Parts.txt");
	}

	ofs.open("Robot_Parts.txt", ios::out | ios::app);
	ofs << number_of_locomotors() << endl;
	ofs.close();
	for (int i = 0; i< number_of_locomotors(); ++i) {
		locomotors[i].file_write("Robot_Parts.txt");
	}

	ofs.open("Robot_Parts.txt", ios::out | ios::app);
	ofs << number_of_arms() << endl;
	ofs.close();
	for (int i = 0; i< number_of_arms(); ++i) {
		arms[i].file_write("Robot_Parts.txt");
	}

	ofs.open("Robot_Parts.txt", ios::out | ios::app);
	ofs << number_of_batteries() << endl;
	ofs.close();
	for (int i = 0; i< number_of_batteries(); ++i) {
		batteries[i].file_write("Robot_Parts.txt");
	}

	ofs.open("Robot_Parts.txt", ios::out | ios::app);
	ofs << number_of_torsos() << endl;
	ofs.close();
	for (int i = 0; i< number_of_torsos(); ++i) {
		torsos[i].file_write("Robot_Parts.txt");
	}




	remove("Robot_Models.txt");

	ofs.open("Robot_Models.txt", std::ofstream::app);
	ofs << number_of_models() << endl;
	ofs.close();
	for (int i = 0; i< number_of_models(); ++i) {
		models[i].file_write("Robot_Models.txt");
	}



	remove("Customers.txt");

	ofs.open("Customers.txt", std::ofstream::app);
	ofs << number_of_customers() << endl;
	ofs.close();
	for (int i = 0; i< number_of_customers(); ++i) {
		customers[i].file_write("Customers.txt");
	}


	remove("Sales_Associates.txt");

	ofs.open("Sales_Associates.txt", std::ofstream::app);
	ofs << number_of_associates() << endl;
	ofs.close();
	for (int i = 0; i< number_of_associates(); ++i) {
		sales_associates[i].file_write("Sales_Associates.txt");
	}



	remove("Orders.txt");

	ofs.open("Orders.txt", std::ofstream::app);
	ofs << number_of_orders() << endl;
	ofs.close();
	for (int i = 0; i< number_of_orders(); ++i) {
		orders[i].file_write("Orders.txt");
	}
}


void Shop::load()
{
	int part_count, count, model_number, employee_number, max_arms, battery_compartments, order_number, status;
	double cost, power, max_power, power_available, max_energy;
	string name, part_name, description, image_filename, phone_number, email, date;

	std::ifstream ifs("Robot_Parts.txt");
	if (ifs.good())
	{
		ifs >> part_count;
		ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		for (int i = 0; i < part_count; i++)
		{
			getline(ifs, name);
			ifs >> model_number;
			ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			ifs >> cost;
			ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			getline(ifs, description);
			getline(ifs, image_filename);
			ifs >> power;
			ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			create_new_head(Head(name, model_number, cost, description, image_filename, power));
		}
		ifs >> part_count;
		ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		for (int i = 0; i < part_count; i++)
		{
			getline(ifs, name);
			ifs >> model_number;
			ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			ifs >> cost;
			ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			getline(ifs, description);
			getline(ifs, image_filename);
			ifs >> power;
			ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			create_new_locomotor(Locomotor(name, model_number, cost, description, image_filename, power));
		}
		ifs >> part_count;
		ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		for (int i = 0; i < part_count; i++)
		{
			getline(ifs, name);
			ifs >> model_number;
			ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			ifs >> cost;
			ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			getline(ifs, description);
			getline(ifs, image_filename);
			ifs >> max_power;
			ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			create_new_arm(Arm(name, model_number, cost, description, image_filename, max_power));
		}
		ifs >> part_count;
		ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		for (int i = 0; i < part_count; i++)
		{
			getline(ifs, name);
			ifs >> model_number;
			ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			ifs >> cost;
			ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			getline(ifs, description);
			getline(ifs, image_filename);
			ifs >> power_available;
			ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			ifs >> max_energy;
			ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			create_new_battery(Battery(name, model_number, cost, description, image_filename, power_available, max_energy));
		}
		ifs >> part_count;
		ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		for (int i = 0; i < part_count; i++)
		{
			getline(ifs, name);
			ifs >> model_number;
			ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			ifs >> cost;
			ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			getline(ifs, description);
			getline(ifs, image_filename);
			ifs >> power_available;
			ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			ifs >> max_arms;
			ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			ifs >> battery_compartments;
			ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			create_new_torso(Torso(name, model_number, cost, description, image_filename, battery_compartments, max_arms));
		}
		ifs.close();
	}


	vector<Arm> model_arms;
	vector<Battery> model_batteries;
	Head *head = NULL;
	Locomotor* locomotor = NULL;
	Torso* torso = NULL;
	ifs.open("Robot_Models.txt");
	if (ifs.good()) {
		ifs >> count;
		ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		for (int i = 0; i < count; i++)
		{
			getline(ifs, name);
			ifs >> model_number;
			ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			getline(ifs, part_name);
			for (vector<Head>::iterator i = heads.begin(); i != heads.end(); ++i)
			{
				if (part_name == i->get_name()) head = &(*i);
			}
			getline(ifs, part_name);
			for (vector<Locomotor>::iterator i = locomotors.begin(); i != locomotors.end(); ++i)
			{
				if (part_name == i->get_name()) locomotor = &(*i);
			}
			getline(ifs, part_name);
			for (vector<Torso>::iterator i = torsos.begin(); i != torsos.end(); ++i)
			{
				if (part_name == i->get_name()) torso = &(*i);
			}
			ifs >> part_count;
			ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			for (int j = 0; j < part_count; j++)
			{
				getline(ifs, part_name);
				for (vector<Arm>::iterator i = arms.begin(); i != arms.end(); ++i)
				{
					if (part_name == i->get_name()) model_arms.push_back(*i);
				}
			}
			ifs >> part_count;
			ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			for (int j = 0; j < part_count; j++)
			{
				getline(ifs, part_name);
				for (vector<Battery>::iterator i = batteries.begin(); i != batteries.end(); ++i)
				{
					if (part_name == i->get_name()) model_batteries.push_back(*i);
				}
			}

			create_new_model(Robot_Model(name, model_number, (*head), (*locomotor), (*torso), model_arms, model_batteries));
		}
	}
	ifs.close();

	ifs.open("Customers.txt");
	if (ifs.good())
	{
		ifs >> count;
		ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		for (int i = 0; i < count; i++)
		{
			getline(ifs, name);
			getline(ifs, phone_number);
			getline(ifs, email);

			create_new_customer(Customer(name, phone_number, email));
		}
	}
	ifs.close();

	ifs.open("Sales_Associates.txt");
	if (ifs.good())
	{
		ifs >> count;
		ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		for (int i = 0; i < count; i++)
		{
			getline(ifs, name);
			ifs >> employee_number;
			ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			create_new_associate(Sales_Associate(name, employee_number));
		}
	}
	ifs.close();




	Customer* customer = NULL;
	Sales_Associate* associate = NULL;
	Robot_Model* model = NULL;

	ifs.open("Orders.txt");
	if (ifs.good()) {
		ifs >> count;
		ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		for (int i = 0; i < count; i++)
		{
			ifs >> order_number;
			ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			getline(ifs, date);

			getline(ifs, name);
			for (vector<Customer>::iterator i = customers.begin(); i != customers.end(); ++i)
			{
				if (name == i->get_customer_name()) customer = &(*i);
			}
			getline(ifs, name);
			for (vector<Sales_Associate>::iterator i = sales_associates.begin(); i != sales_associates.end(); ++i)
			{
				if (name == i->get_associate_name()) associate = &(*i);
			}
			getline(ifs, name);
			for (vector<Robot_Model>::iterator i = models.begin(); i != models.end(); ++i)
			{
				if (name == i->get_model_name()) model = &(*i);
			}

			create_new_order(Order(order_number, date, (*customer), (*associate), (*model)));
		}
	}
	ifs.close();

}


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

void Shop::create_new_model(Robot_Model model) {
	models.push_back(model);
}

void Shop::create_new_customer(Customer customer)
{
	customers.push_back(customer);
}

void Shop::create_new_associate(Sales_Associate sales_associate)
{
	sales_associates.push_back(sales_associate);
}

void Shop::create_new_order(Order order)
{
	orders.push_back(order);
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

int Shop::number_of_models() {
	return models.size();
}

int Shop::number_of_customers() {
	return customers.size();
}

int Shop::number_of_associates() {
	return sales_associates.size();
}

int Shop::number_of_orders() {
	return orders.size();
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

string Shop::models_to_string(int model_index) {
	return models[model_index].to_string();
}

string Shop::customers_to_string(int customer_index) {
	return customers[customer_index].to_string();
}

string Shop::associates_to_string(int associate_index) {
	return sales_associates[associate_index].to_string();
}

string Shop::orders_to_string(int order_index) {
	return orders[order_index].to_string();
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
	string get_model_list();
	string get_customer_list();
	string get_associate_list();
	string get_order_list();

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
(3) Create Robot Model
(4) List Robot Models
(5) Add Customer
(6) List Customers
(7) Add Sales Associate
(8) List Sales Associates
(9) Place Order
(10) List Orders

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


string View::get_model_list() {
	string list = R"(
--------------------
List of Robot Models
--------------------
)";
	for (int i = 0; i<shop.number_of_models(); ++i) {
		list += std::to_string(i) + ") " + shop.models_to_string(i) + '\n';
	}
	return list;
}

string View::get_customer_list() {
	string list = R"(
-----------------
List of Customers
-----------------
)";
	for (int i = 0; i<shop.number_of_customers(); ++i) {
		list += std::to_string(i) + ") " + shop.customers_to_string(i) + '\n';
	}
	return list;
}

string View::get_associate_list() {
	string list = R"(
------------------
List of Associates
------------------
)";
	for (int i = 0; i<shop.number_of_associates(); ++i) {
		list += std::to_string(i) + ") " + shop.associates_to_string(i) + '\n';
	}
	return list;
}

string View::get_order_list() {
	string list = R"(
--------------
List of Orders
--------------
)";
	for (int i = 0; i<shop.number_of_orders(); ++i) {
		list += std::to_string(i) + ") " + shop.orders_to_string(i) + '\n';
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

	else if (cmd == 3) {
		string name;
		int model_number, selection;
		vector<Arm> arms;
		vector<Battery> batteries;

		cout << "Name? ";
		getline(cin, name);

		cout << "Model Number? ";
		model_number = get_int("", 999999999);

		cout << view.get_head_list();
		cout << "\nSelect Head: ";
		selection = get_int("", shop.number_of_heads());
		Head head = shop.heads[selection];

		cout << view.get_locomotor_list();
		cout << "\nSelect Locomotor: ";
		selection = get_int("", shop.number_of_locomotors());
		Locomotor locomotor = shop.locomotors[selection];

		cout << "Torso? " << endl;
		cout << view.get_torso_list();
		cout << "\nSelect Torso: ";
		selection = get_int("", shop.number_of_torsos());
		Torso torso = shop.torsos[selection];

		for (int i = 0; i < torso.get_max_arms(); i++)
		{
			cout << view.get_arm_list();
			cout << "\nSelect Arm " << i << ": ";
			selection = get_int("", shop.number_of_arms());
			arms.push_back(shop.arms[selection]);
		}

		for (int i = 0; i < torso.get_battery_compartments(); i++)
		{
			cout << view.get_battery_list();
			cout << "\nSelect Battery " << i << ": ";
			selection = get_int("", shop.number_of_batteries());
			batteries.push_back(shop.batteries[selection]);
		}
		
		shop.create_new_model(Robot_Model(name, model_number, head, locomotor, torso, arms, batteries));

	}
	else if (cmd == 4)
	{
		cout << view.get_model_list();
	}

	else if (cmd == 5)
	{
		string name, phone_number, email;

		cout << "Name? ";
		getline(cin, name);

		cout << "Phone Number? ";
		getline(cin, phone_number);

		cout << "Email? ";
		getline(cin, email);

		shop.create_new_customer(Customer(name, phone_number, email));
	}

	else if (cmd == 6)
	{
		cout << view.get_customer_list();
	}

	else if (cmd == 7)
	{
		string name;
		int employee_number;

		cout << "Name? ";
		getline(cin, name);

		cout << "Employee Number? ";
		employee_number = get_int("", 999999999);

		shop.create_new_associate(Sales_Associate(name, employee_number));
	}
	 
	else if (cmd == 8)
	{
		cout << view.get_associate_list();
	}

	else if (cmd == 9)
	{
		int order_number;
		string date;
		
		cout << "Order Number?" << endl;
		order_number = get_int("", 9999999);

		cout << "Date?" << endl;
		getline(cin, date);

		cout << "Customer? " << endl;
		cout << view.get_customer_list();
		cout << "\nSelect Customer: ";
		int selection = get_int("", shop.number_of_customers());
		Customer customer = shop.customers[selection];

		cout << "Sales Associate? " << endl;
		cout << view.get_associate_list();
		cout << "\nSelect Associate: ";
		selection = get_int("", shop.number_of_associates());
		Sales_Associate sales_associate = shop.sales_associates[selection];

		cout << "Model? " << endl;
		cout << view.get_model_list();
		cout << "\nSelect Model: ";
		selection = get_int("", shop.number_of_models());
		Robot_Model model = shop.models[selection];

		shop.create_new_order(Order(order_number, date, customer, sales_associate, model));
	}

	else if (cmd == 10)
	{
		cout << view.get_order_list();
	}



	else if (cmd == 0)
	{
		shop.save();
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
	shop.load();
	View view{ shop };
	Controller controller(shop, view);
	controller.cli();
}