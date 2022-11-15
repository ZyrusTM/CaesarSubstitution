#pragma once
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class CaesarSubstitution
{
private:
	string m_inputText;
	vector<char> m_textArr;
	string m_sKey;
	int m_key;
public:
	void handleUserInput(string option);
	void encrypt();
	void decrypt();
};

