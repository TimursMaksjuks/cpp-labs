#include <iostream>
#include <fstream>
using namespace std;


struct Person{
int key;
char name[31];
};


int main(){

Person person1 = {1, "Timurs"};
Person person2 = {2, "Leo"};
Person person3 = {3, "Aleksandra"};
Person person4 = {4, "Balotelli"};
Person person5 = {5, "Mārija"};

ofstream file("main.bin", ios::binary);

if (!file){
    cout << "File 'main.bin' was not created!" << endl;
    return 1;
}


file.write((char*)&person1, sizeof(person1));
file.write((char*)&person4, sizeof(person4));
file.write((char*)&person5, sizeof(person5));
file.write((char*)&person2, sizeof(person2));
file.write((char*)&person3, sizeof(person3));

cout << "File 'main.bin' was created!" << endl;
file.close();

return 0;
}
