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
	int m_key;
	int m_textlength;
public:
	void handleUserInput(string option);
	void encrypt();
	void decrypt();
};

