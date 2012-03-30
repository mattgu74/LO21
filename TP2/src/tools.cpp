#include "tools.h"

using std::string;

string & tolower(string &s) {
	for (int i=0; i<s.size(); ++i) {
		s[i] = tolower(s[i]);
	}

	return s;
}

string & toupper(string &s) {
	for (int i=0; i<s.size(); ++i) {
		s[i] = toupper(s[i]);
	}

	return s;
}

string & firstUpper(string &s) {
	tolower(s);
	if (s.size() > 0) {
		s[0] = toupper(s[0]);
	}

	return s;
}

string & tolower(const string &s) {
	string * pt_s = new string();
	*(pt_s) = s;

	return tolower(*pt_s);
}
	
string & toupper(const string &s) {
	string * pt_s = new string();
	*(pt_s) = s;

	return toupper(*pt_s);
}


string & firstUpper(const string &s) {
	string * pt_s = new string();
	*(pt_s) = s;

	return firstUpper(*pt_s);
}

string & time_tToString(time_t & t) {
	struct tm * timeinfo = localtime ( &(t) );
	char * buffer = new char[80];
	
	strftime (buffer,80,"%d/%M/%Y",timeinfo);

	string * s = new string(buffer);
	return *s;
}

