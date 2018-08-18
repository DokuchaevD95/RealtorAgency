#pragma once

#include <iostream>

#include "dequeInstance.h"
#include "Human.h"

using namespace std;


class Realtor: public dequeInstance
{
private:
	static int id;
	static char _fileName[];

	int _myId;
	Human _name;
	float _percent;
public:
	Realtor();
	Realtor(const Realtor& obj);
	Realtor(Human& name, float percent, int myId = 0);
	static Realtor* create();
	bool operator<(Realtor& obj);
	friend ostream& operator<<(ostream& out, Realtor& obj);
	int getId();
	void exportToFile();
	static char* getFileName();
	static Realtor* importFromFile(ifstream& file);
	~Realtor();
};