#include "CaesarSubstitution.h"

void CaesarSubstitution::handleUserInput(string option)
{
	string text = "";
	cout << "Please enter a " << option << "text: ";
	
	cin.ignore();
	getline(cin, text);

	if (text == "plsexit") exit(0);

	m_inputText = text;
	text.erase(remove_if(text.begin(), text.end(), isspace), text.end());

	for (auto& c : text) {
		c = toupper(c);
	}

	for (auto c : text) {
		m_textArr.push_back(c);
	}

	cout << "Please enter a key: ";
	cin >> m_sKey;

	if (m_sKey == "exit") exit(0);
	m_key = stoi(m_sKey);
	
}

void CaesarSubstitution::encrypt() 
{
	for (char &c : m_textArr) {
		int ascii = (int)c;
		ascii -= 65; //In Ascii, the uppercase alphabet starts at 65, to use %26 you have to subtract 65 from each letter.
		int encAscii = (ascii + m_key) % 26;
		encAscii += 65; //After the operation, you have to add 65, to get back in Ascii's uppercase-alphabet range
		c = (char)encAscii;
	}
	string str(m_textArr.begin(), m_textArr.end());

	cout << "Encrypted: " << m_inputText << endl;
	cout << "To: " << str << endl;
	cout << "Using key: " << m_key << endl;
}

void CaesarSubstitution::decrypt()
{
	for (char& c : m_textArr) {
		int ascii = (int)c;
		ascii -= 65; 
		int encAscii = (ascii - m_key) % 26;
		if (encAscii < 0) {
			encAscii += 26;
		}

		encAscii += 65; 
		c = (char)encAscii;
	}
	string str;

	for (char c : m_textArr) {
		str += c;
	}

	cout << sizeof(m_textArr) << "str: " << sizeof(str) << endl;
	
	cout << "Decrypted: " << m_inputText << endl;
	cout << "To: " << str << endl;
	cout << "Using key: " << m_key << endl;
}
