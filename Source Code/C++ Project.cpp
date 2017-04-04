#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <fstream>
#include <ctime>
#include <sstream>
#include <cstdlib>

using namespace std;

void cover() //Cover page of the system
{
	system("color f");
	cout << "**********  Study and learning system   ************" << endl;
	cout << "****************************************************" << endl;
	cout << "* Function            Content                      *" << endl;
	cout << "* ------------------------------------------------ *" << endl;
	cout << "*                                                  *" << endl;
	cout << "*   1          Mechanics Calculation               *" << endl;
	cout << "*                                                  *" << endl;
	cout << "*   2      Read notes and write vocabulary         *" << endl;
	cout << "*                                                  *" << endl;
	cout << "*   3            Mini game (bingo)                 *" << endl;
	cout << "*                                                  *" << endl;
	cout << "*   0                 EXIT                         *" << endl;
	cout << "*                                                  *" << endl;
	cout << "* ------------------------------------------------ *" << endl;
	cout << "*                                                  *" << endl;
	cout << "****************************************************" << endl;
	cout << endl;
	cout << " Please choose a function by entering the number" << endl;
}


void HK_ID() //HKID verify function
{
	system("color F0");
	cout << "Input your hkid number (Please include the last digit in the bracket)" << endl;
	string hkid;
	cin >> hkid;

	istringstream buffer(hkid.substr(0, 1));
	char hkid1;
	buffer >> hkid1;

	(int)hkid1; // We are using the Ascii table for the conversion of Letter to integer
	int a;

	if (hkid1<91 && hkid1>64)
	{
		a = hkid1 - 64;

	}

	else if (hkid1<123 && hkid1>96)
	{
		a = hkid1 - 96;

	}

	else
	{
		cout << "Error please input a letter for the first character" << endl;
		return HK_ID();
	}


	string hkid2 = hkid.substr(1, 1);
	int b = atoi(hkid2.c_str());

	string hkid3 = hkid.substr(2, 1);
	int c = atoi(hkid3.c_str());

	string hkid4 = hkid.substr(3, 1);
	int d = atoi(hkid4.c_str());

	string hkid5 = hkid.substr(4, 1);
	int e = atoi(hkid5.c_str());

	string hkid6 = hkid.substr(5, 1);
	int f = atoi(hkid6.c_str());

	string hkid7 = hkid.substr(6, 1);
	int g = atoi(hkid7.c_str());

	string hkid8 = hkid.substr(7, 1);
	int h = atoi(hkid8.c_str());

	int sum = (a * 8 + b * 7 + c * 6 + d * 5 + e * 4 + f * 3 + g * 2 + h) % 11;





	if (sum == 0)
	{
		system("CLS");
		cout << "You are Confirmed" << endl;
		system("Pause");
	}

	else
	{
		system("CLS");
		cout << "Your HKID is wrong" << endl;
		cout << "Please try again" << endl;
		return HK_ID();
	}

}

double Pyth_thm(double x, double y, double z)
{
	double length = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
	if (length == 0)//for origin,length=0,but it is undefined for x/0,when finding ratio
		length = 1;//So it is needed to set length as some value,it wont matter because for origin,x also =0
	return length;
}
double cross_product_i(double force_vector[3], double position_vector[3])
{
	double cross_product_i = (position_vector[1] * force_vector[2] - force_vector[1] * position_vector[2]);
	return cross_product_i;
}
double cross_product_j(double force_vector[3], double position_vector[3])
{
	double cross_product_j = (force_vector[0] * position_vector[2] - position_vector[0] * force_vector[2]);
	return cross_product_j;
}
double cross_product_k(double force_vector[3], double position_vector[3])
{
	double cross_product_k = (position_vector[0] * force_vector[1] - force_vector[0] * position_vector[1]);
	return cross_product_k;
}
double SM_force_magnitude(double &force_vector_i, double &force_vector_j, double &force_vector_k)
{
	double magnitude = sqrt(pow(force_vector_i, 2) + pow(force_vector_j, 2) + pow(force_vector_k, 2));
	return magnitude;
}
void SM_force_vector_component(double &force_vector_i, double &force_vector_j, double &force_vector_k)
{

	cout << "please input the i component" << endl;
	cin >> force_vector_i;
	cout << "please input the j component" << endl;
	cin >> force_vector_j;
	cout << "please input the k component" << endl;
	cin >> force_vector_k;
}
void SM_force_vector_ratio(double &force_vector_i, double &force_vector_j, double &force_vector_k)
{
	double force_magnitude, force_Xaxis_length, force_Yaxis_length, force_Zaxis_length, force_length;
	cout << "please input the force magnitude" << endl;
	cin >> force_magnitude;
	cout << "please input the force x-axis length" << endl;
	cin >> force_Xaxis_length;
	cout << "please input the force y-axis length" << endl;
	cin >> force_Yaxis_length;
	cout << "please input the force z-axis length" << endl;
	cin >> force_Zaxis_length;
	force_length = Pyth_thm(force_Xaxis_length, force_Yaxis_length, force_Zaxis_length);
	force_vector_i = force_magnitude*(force_Xaxis_length / force_length);
	force_vector_j = force_magnitude*(force_Yaxis_length / force_length);
	force_vector_k = force_magnitude*(force_Zaxis_length / force_length);
}
double SM_force_vector_angle(double &force_vector_i, double &force_vector_j, double &force_vector_k)
{
	double force_magnitude, alpha, beta, gamma;
	cout << "please input the force magnitude" << endl;
	cin >> force_magnitude;
	cout << "please input the force inclined angle with the x-axis" << endl;
	cin >> alpha;
	cout << "please input the force inclined angle with the y-axis" << endl;
	cin >> beta;
	cout << "please input the force inclined angle with the z-axis" << endl;
	cin >> gamma;
	force_vector_i = force_magnitude*cos(alpha);
	force_vector_j = force_magnitude*cos(beta);
	force_vector_k = force_magnitude*cos(gamma);
	return force_vector_i, force_vector_j, force_vector_k;
}
void SM_force_input(double &force_vector_i, double &force_vector_j, double &force_vector_k)
{
	cout << "Which information you have with a force?" << endl;
	cout << "    1.force vector" << endl;
	cout << "    2.magnitude of the force and ratio of the components" << endl;
	cout << "    3.magnitude of the force and the inclinded angles" << endl;
	int anwser_input_method;
	do
	{
		cout << "Please enter the number representing the information you have" << endl;
		cin >> anwser_input_method;
	} while (cin.fail() || anwser_input_method > 3 || anwser_input_method < 1);
	switch (anwser_input_method)
	{
	case 1:SM_force_vector_component(force_vector_i, force_vector_j, force_vector_k); break;
	case 2:SM_force_vector_ratio(force_vector_i, force_vector_j, force_vector_k); break;
	case 3:SM_force_vector_angle(force_vector_i, force_vector_j, force_vector_k); break;
	}
}
void couple_moment(double force_information[6][100], double support[3], int i, double &moment_i, double &moment_j, double &moment_k)
{
	double force_vector[3];
	double position_vector[3];
	for (int k = 0; k < 3; k++)
	{
		position_vector[k] = (force_information[k][i] - support[k]);
		force_vector[k] = (force_information[k + 3][i]);
	}
	moment_i = (moment_i + cross_product_i(force_vector, position_vector));
	moment_j = (moment_j + cross_product_j(force_vector, position_vector));
	moment_k = (moment_k + cross_product_k(force_vector, position_vector));
}
void SM_force_system()
{
	double resultant_force_vector_i = 0, resultant_force_vector_j = 0, resultant_force_vector_k = 0;
	double force_vector_i = 0, force_vector_j = 0, force_vector_k = 0;
	double support[3];
	double moment_i = 0, moment_j = 0, moment_k = 0;
	const int array_capacity = 100;
	double force_information[6][array_capacity];
	int number_force = 0;
	char moment_finding = false;
	cout << "This program help you to simpifly the force system," << endl;
	cout << "to make one resultant force and one moment for a fixed support." << endl;
	cout << "In the program,when you have to anwser a yes no question," << endl;
	cout << "type 'y' for yes,'n' for no." << endl;
	cout << "Do you need to find the moment at the support?" << endl;
	cin >> moment_finding;
	if (moment_finding == 'y')
	{
		moment_finding = true;
		cout << "Where is the support?" << endl;
		cout << "In the case of no support or the support is at the origin, input 0 as the value" << endl;
		cout << "Please input the x-cordinate of the support" << endl;
		cin >> support[0];
		cout << "Please input the y-cordinate of the support" << endl;
		cin >> support[1];
		cout << "Please input the z-cordinate of the support" << endl;
		cin >> support[2];
	}
	cout << "The programe is gathering information of the forces..." << endl;
	char user_anwser = true;
	for (int i = 0; user_anwser == true && i<array_capacity; number_force++, i++)
	{
		user_anwser = false;
		SM_force_input(force_vector_i, force_vector_j, force_vector_k);
		resultant_force_vector_i = resultant_force_vector_i + force_vector_i;
		resultant_force_vector_j = resultant_force_vector_j + force_vector_j;
		resultant_force_vector_k = resultant_force_vector_k + force_vector_k;
		if (moment_finding == true)
		{
			cout << "Finding the distance of the force with the support...";
			cout << "If there is no origin, just take the point of support as it." << endl;
			cout << "Please input the distance of the force and x-axis" << endl;
			cin >> force_information[0][i];
			cout << "Please input the distance of the force and y-axis" << endl;
			cin >> force_information[1][i];
			cout << "Please input the distance of the force and z-axis" << endl;
			cin >> force_information[2][i];
		}
		force_information[3][i] = force_vector_i;
		force_information[4][i] = force_vector_j;
		force_information[5][i] = force_vector_k;
		couple_moment(force_information, support, i, moment_i, moment_j, moment_k);
		cout << "is there another force?" << endl;
		cout << "(y)es or (n)o?" << endl;
		cin >> user_anwser;
		if (user_anwser == 'y')
			user_anwser = true;
	}
	cout << "magnitude of resultant force:" << SM_force_magnitude(resultant_force_vector_i, resultant_force_vector_j, resultant_force_vector_k) << " N " << endl;
	cout << resultant_force_vector_i << "i+" << resultant_force_vector_j << "j+" << resultant_force_vector_k << "k N" << endl;
	if (moment_finding == true)
	{
		cout << "the couple moment= " << endl;
		cout << moment_i << "i+" << moment_j << "j+" << moment_k << "k" << endl;
	}
	cout << "Do you want to see the forces you inputed ?";
	cin >> user_anwser;
	if (user_anwser == 'y')
	{
		for (int i = 0; i < number_force; i++)
		{

			cout << "Force " << i + 1 << endl;
			cout << "cartesian_vector:" << endl;
			cout << force_information[3][i] << "i+" << force_information[4][i] << "j+" << force_information[5][i] << "k" << endl;
			if (moment_finding == true)
			{
				cout << "Position_vector:" << endl;
				cout << force_information[0][i] << "i+" << force_information[1][i] << "j+" << force_information[2][i] << "k" << endl;
			}
			system("Pause");
		}
	}
}


void write() //write txt file function
{
	system("Color 0");
	system("CLS");
	ofstream file("Word.txt", ios::out | ios::app); //Use ios::out | ios::app to ensure the previous word will not be clear
	string vocab;
	cout << "Write down your word:" << endl;
	cout << "Please write one word only" << endl;
	cout << "If you need to write more than one word, please use symbol _ instead of spacebar and enter" << endl;
	cout << "Otherwise, error will occur" << endl;
	cin >> vocab;
	file << vocab << endl; //save the word in the word.txt file
	system("CLS");
	cout << " The word " << vocab << " is saved the file in Word.txt" << endl;
	file.close();
}

void read() //read txt file function
{
	system("Color 0");
	system("CLS");
	cout << "Enter a file name:" << endl;
	cout << "timetable.txt   is for the time table" << endl;
	cout << "assignment.txt  is for the assignment list" << endl;
	cout << "word.txt        is for the word that you have written down" << endl;
	string name_1;
	cin >> name_1;
	ifstream in_file(name_1);
	while (in_file)
	{
		system("CLS");
		string line;
		while (getline(in_file, line)) //Read all the line in the txt file
		{
			cout << line << endl; //Display the content
		}
	}
}

void sub_2() //combined write & read fuction
{
	system("Color b");
	cout << "Enter 1 is write down the Vocabulary that you learn" << endl;
	cout << "Enter 2 is read the txt file" << endl;
	int choice;
	cin >> choice;
	if (choice == 1)
	{
		write();
		system("Pause");
	}
	else if (choice == 2)
	{
		read();
		system("Pause");
	}
	else if (cin.fail() || choice<1 || choice>2)
	{
		cout << "please input a vaild number!" << endl;
		system("Pause");
		cin.clear();
		cin.sync();
	}
}

void sub_3(int number) //mini game function
{
	system("color e");
	srand(time(NULL)); //Randomize
	cout << " Enter a number between * 1-100 *" << endl;
	int ran_num = rand() % 100 + 1; //Random a number between 1 and 100
	for (int top = 100, bottom = 1; number != ran_num;)
	{
		cin >> number;
		if (cin.fail() || number > top || number < bottom)
		{
			cout << "please input a vaild number!" << endl;
			cin.clear();
			cin.sync();
		}

		else if (ran_num > number)
		{
			bottom = number;
			system("CLS");
			cout << "The new range is:   * " << bottom << " to " << top << " *" << endl;
			cout << "Enter a number in this range:";
			if (cin.fail() || number > top || number < bottom)
			{
				cout << "please input a vaild number!" << endl;
				cin.clear();
				cin.sync();
			}

		}
		else if (ran_num < number)
		{
			top = number;
			system("CLS");
			cout << "The new range is:   * " << bottom << " to " << top << " *" << endl;
			cout << "Enter a number in this range:";
			if (cin.fail() || number > top || number < bottom)
			{
				cout << " Wrong value! Please enter again" << endl;
				cin.clear();
				cin.sync();
			}
		}
	}
	system("CLS");
	cout << "Bingo!" << endl;
	system("Pause");
}


int main()
{
	//Call out the sub-program
	//Using loop and system("CLS") to make the program like a system
	HK_ID();
	system("CLS");
	cout << endl;
	int choice, x;
	do //select function using do-while loop
	{
		cover();
		cin >> choice;
		if (cin.fail() || choice < 0 || choice>4)
		{
			cout << " Fail" << endl;
			system("Pause");
			cin.clear();
			cin.sync();
		}
		switch (choice)
		{
		case 1:
			system("CLS");
			system("color a");
			SM_force_system();
			break;

		case 2:
			system("CLS");
			sub_2(); //read&write txt file function
			break;

		case 3:
			system("CLS");
			sub_3(0); //mini game function
			break;
		case 0:
			system("CLS");
			cout << "see you, bye!" << endl;
			return 0;
			break;
		}
		system("CLS");
		//Ask user whether to return menu or not
		cout << "Do you want to return menu?" << endl;
		cout << "You can enter all number except 1 to return menu " << endl;
		cout << " *Enter 1 will exit* " << endl;
		cin >> x;
		if (cin.fail() || choice < 0 || choice>4)
		{
			cin.clear();
			cin.sync();
		}
		system("CLS");

	} while (x != 1);
	//Program end
	system("CLS");
	cout << "Thank you!" << endl;
	cout << "See you!" << endl;

	return 0;

}
