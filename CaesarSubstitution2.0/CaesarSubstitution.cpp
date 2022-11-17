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

	m_textlength = text.length();

	for (auto c : text) {
		m_textArr.push_back(c);
	}
	string sKey;
	cout << "Please enter a key: ";
	cin >> sKey;

	if (sKey == "exit") exit(0);
	m_key = stoi(sKey);
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
	string encText(m_textArr.begin(), m_textArr.end());

	cout << "Encrypted: " << m_inputText << endl;
	cout << "To: " << encText << endl;
	cout << "Using key: " << m_key << endl;
}

void CaesarSubstitution::decrypt()
{
	for (char& c : m_textArr) {
		int ascii = (int)c;
		ascii -= 65; 
		int decAscii = (ascii - m_key) % 26;
		if (decAscii < 0) {
			decAscii += 26;
		}

		decAscii += 65; 
		c = (char)decAscii;
	}
	string decText;

	for (int i = 0;i < m_textlength;i++) {
		decText += m_textArr[i];
	}

	cout << "Decrypted: " << m_inputText << endl;
	cout << "To: " << decText << endl;
	cout << "Using key: " << m_key << endl;
}
