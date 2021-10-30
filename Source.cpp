#include <iostream>
#include <array>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <conio.h>
#include<cstring>
using namespace std;

#define keyLenght 20
#define arrayLenght 100
#define firstNameLenght 20
#define lastNameLenght 30

typedef struct Object{
	char * firstName;
	char * lastName;
	int age;
}Object;

typedef struct element{
	char * key;
	Object person;
}element;


class persistentStorage{

private:

	element HashMap[arrayLenght];
	int lastElement;

public:

	//constructor
	persistentStorage(){
		lastElement = 0;
		for (int i = 0; i < arrayLenght; i++){
			HashMap[i].key = (char *)malloc(sizeof(char)*keyLenght);
			HashMap[i].person.firstName = (char *)malloc(sizeof(char)*firstNameLenght);
			HashMap[i].person.lastName = (char *)malloc(sizeof(char)*lastNameLenght);
		}
	}

	//check if there is info in the hashmap
	int checkmap(){
		if (HashMap[1].key == ""){
			std::ifstream myFile("persistentStorage.txt");
			
			std::string Text = ""; 
			std::string Text2 = "";
			std::string Text3 = "";
			std::string::size_type sz;
			std::getline(myFile, Text);
			if (Text.compare("") == 0)
				return -1;
			lastElement = std::stoi(Text, &sz);
			for (int i = 0; i<lastElement; i++){

				std::getline(myFile,Text);
				HashMap[i].key = strdup(Text.c_str());
				std::getline(myFile, Text);
				HashMap[i].person.firstName = strdup(Text.c_str());
				std::getline(myFile, Text);
				HashMap[i].person.lastName = strdup(Text.c_str());
				getline(myFile, Text);
				HashMap[i].person.age=std::stoi(Text);
			}

			myFile.close();
			return 1;
		}
	}

	void deleteElements(){
		
		for (int i = 0; i < lastElement; i++){
			HashMap[i].key = "";
			HashMap[i].person.firstName = "";
			HashMap[i].person.lastName = "";
			HashMap[i].person.age = 0;
		}
	}

	int getLastElement(){
		return lastElement;
	}

	//add data to the hashmap
	void put(std::string key, Object value){

		if (checkmap() == -1){
			std::ofstream myFile;
			myFile.open("persistentStorage.txt");

			strcpy(HashMap[lastElement].key, key.c_str());
			strcpy(HashMap[lastElement].person.firstName, value.firstName);
			strcpy(HashMap[lastElement].person.lastName, value.lastName);
			HashMap[lastElement].person.age = value.age;
			lastElement += 1;

			myFile << lastElement << endl;
			for (int i = 0; i<lastElement; i++){
				myFile << HashMap[i].key << endl;
				myFile << HashMap[i].person.firstName << endl;
				myFile << HashMap[i].person.lastName << endl;
				myFile << HashMap[i].person.age << endl;
			}

			myFile.close();
			return;
		}
			
		for (int i = 0; i<arrayLenght; i++)
		if (strcmp(HashMap[i].key, key.c_str()) == 0){
			printf("The key already exists!. \n");
			return;
		}
		if (remove("myFile.txt") != 0);

		if (lastElement == 100)
			printf("No free space on the storage. \n");
		else {
			std::ofstream myFile;
			myFile.open("persistentStorage.txt");

			auto length = key.copy(HashMap[lastElement].key, sizeof(key));
			HashMap[lastElement].key[length] = '\0';
			strcpy(HashMap[lastElement].person.firstName, value.firstName);
			strcpy(HashMap[lastElement].person.lastName, value.lastName);
			HashMap[lastElement].person.age = value.age;
			lastElement += 1;

			myFile << lastElement << endl;
			for (int i = 0; i<lastElement; i++){
				myFile << HashMap[i].key << endl;
				myFile << HashMap[i].person.firstName << endl;
				myFile << HashMap[i].person.lastName << endl;
				myFile << HashMap[i].person.age << endl;
			}

			myFile.close();
		}
	}

	Object get(std::string key){

		if(checkmap()==-1);
		for (int i = 0; i<lastElement; i++)
		if (strcmp(HashMap[i].key,key.c_str()) == 0)
			return 	HashMap[i].person;
	}

	bool contains(std::string key){

		if(checkmap()==-1);
		for (int i = 0; i<lastElement; i++)
		if (strcmp(HashMap[i].key,key.c_str()) == 0)
			return true;
		return false;
	}

	bool remove(std::string key){

		if (checkmap() == -1);

		for (int i = 0; i < 100; i++){
			if (strcmp(HashMap[i].key, key.c_str()) == 0){

				if (remove("myFile.txt") != 0);

				std::ofstream myFile;
				myFile.open("persistentStorage.txt");

				if (i == lastElement - 1){
					lastElement -= 1;
					HashMap[i].key = "";
					HashMap[i].person.firstName = "";
					HashMap[i].person.lastName = "";
					HashMap[i].person.age = 0;

				}
				else{
					lastElement -= 1;
					strcpy(HashMap[i].key, HashMap[lastElement].key);
					strcpy(HashMap[i].person.firstName, HashMap[lastElement].person.firstName);
					strcpy(HashMap[i].person.lastName, HashMap[lastElement].person.lastName);
					HashMap[i].person.age = HashMap[lastElement].person.age;
				}
				myFile << lastElement << endl;
				for (int j = 0; j < lastElement; j++){
					myFile << HashMap[j].key << endl;
					myFile << HashMap[j].person.firstName << endl;
					myFile << HashMap[j].person.lastName << endl;
					myFile << HashMap[j].person.age << endl;
				}

				myFile.close();
				return true;
			}
		}
			printf("The HashMap does not contain this key. \n");
			return false;
	}

	void print(){
		printf("Print the Storage:\n");
		for (int i = 0; i < lastElement; i++){
			printf("element: %s, %s, %s, %d \n", HashMap[i].key, HashMap[i].person.firstName, HashMap[i].person.lastName, HashMap[i].person.age);
		}
	}
};

int main(){
	class persistentStorage Storage;
	element o,o2,o3,o4;

	printf("\n\n Add Chef key: \n");
	o.key = "Chef";
	o.person.age = 40;
	o.person.firstName = "Ivan";
	o.person.lastName = "Georgiev";
	Storage.put(o.key, o.person);
	Storage.print();

	printf("\n\n Add Trainee key: \n");
	o2.key = "Trainee";
	o2.person.age = 23;
	o2.person.firstName = "Nikola";
	o2.person.lastName = "Bonchev";
	Storage.put(o2.key, o2.person);
	Storage.print();

	printf("\n\n Add Customer key: \n");
	o3.key = "Customer";
	o3.person.age = 31;
	o3.person.firstName = "Maya";
	o3.person.lastName = "Georgieva";
	Storage.put(o3.key, o3.person);
	Storage.print();

	printf("\n\n Add Owner key: \n");
	o4.key = "Owner";
	o4.person.age = 52;
	o4.person.firstName = "Krasimir";
	o4.person.lastName = "Petrov";
	Storage.put(o4.key, o4.person);
	Storage.print();

	printf("\n\n Add another Owner key: \n");
	o4.key = "Owner";
	o4.person.age = 53;
	o4.person.firstName = "Krasimira";
	o4.person.lastName = "Ivanova";
	Storage.put(o4.key, o4.person);
	Storage.print();

	printf("\n\n Remove the Customer key: \n");
	Storage.remove("Customer");
	Storage.print();

	printf("\n\n Remove the Me key: \n");
	Storage.remove("Me");
	Storage.print();

	printf("\n\n Does the storage contain the Owner key? \n");
	if (Storage.contains("Owner"))
		printf("The storage contains the Owner key.\n");
	else
		printf("The storage does not contain the Owner key \n");

	printf("\n\n Does the storage contain the Customer key? \n");
	if (Storage.contains("Customer"))
		printf("The storage contains the Customer key. \n");
	else
		printf("The storage does not contain the Customer key \n");

	printf("\n\n Search for Chef key: \n");
	element myNewElement;
	myNewElement.key = "Example";
	myNewElement.person = Storage.get("Chef");
	printf("The element with the Chef key is %s, %s, %d \n", myNewElement.person.firstName, myNewElement.person.lastName, myNewElement.person.age);


	printf("\n \n Imitate restart: \n");
	Storage.deleteElements();

	printf("\n\n Does the storage contain the Owner key? \n");
	if (Storage.contains("Owner"))
		printf("The storage contains the Owner key.\n");
	else
		printf("The storage does not contain the Owner key \n");
	Storage.print();

	_getch();
	return 0;
}



