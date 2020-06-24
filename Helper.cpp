
#include "Helper.h"
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <math.h>
#include <time.h>
#include <locale> 
#include <codecvt>
const char* s_empty = "";




std::wstring Helper::s2ws(const std::string& str)
{
	using convert_typeX = std::codecvt_utf8<wchar_t>;
	std::wstring_convert<convert_typeX, wchar_t> converterX;

	return converterX.from_bytes(str);
}


std::string Helper::ws2s(const std::wstring& wstr)
{
	using convert_typeX = std::codecvt_utf8<wchar_t>;
	std::wstring_convert<convert_typeX, wchar_t> converterX;

	return converterX.to_bytes(wstr);
}




std::vector<std::string> Helper::explode(std::string str, std::string token) {
	std::vector<std::string> result;
	while (str.size()) {
		int index = str.find(token);
		if (index != std::string::npos) {
			result.push_back(str.substr(0, index));
			str = str.substr(index + token.size());
			if (str.size() == 0)result.push_back(str);
		}
		else {
			result.push_back(str);
			str = "";
		}
	}
	return result;
}



std::string Helper::implode(std::vector<std::string> vec, const char deli)
{
	std::string returnString = s_empty;

	for (unsigned int i = 0; i < vec.size(); i++)
	{
		returnString += vec[i];
		if (i < vec.size() - 1)
		{
			returnString += deli;
		}
	}
	return returnString;

	//std::wstringstream oss;

	//if (!vec.empty())
	//{
	//	// Convert all but the last element to avoid a trailing ","
	//	std::copy(vec.begin(), vec.end() - 1, std::wst ostream_iterator<std::string>(oss, deli));

	//	// Now add the last element with no delimiter
	//	oss << vec.back();
	//}


}


std::string Helper::getCurrentTimeStamp()
{
	time_t rawtime;
	struct tm * timeinfo;
	char buffer[80];

	time(&rawtime);
	timeinfo = localtime(&rawtime);

	strftime(buffer, sizeof(buffer), "%Y/%m/%d %H:%M:%S", timeinfo);
	std::string buf(buffer);

	return buf;
}

time_t strToTime(std::string str)
{

	

	time_t d1;
	int yy, month, dd, hh, mm, ss;
	struct tm whenStart;
	const char *zStart = str.c_str();

	sscanf(zStart, "%d/%d/%d %d:%d:%d", &yy, &month, &dd, &hh, &mm, &ss);
	whenStart.tm_year = yy - 1900;
	whenStart.tm_mon = month - 1;
	whenStart.tm_mday = dd;
	whenStart.tm_hour = hh;
	whenStart.tm_min = mm;
	whenStart.tm_sec = ss;
	whenStart.tm_isdst = -1;

	d1 = mktime(&whenStart);
	return d1;
}

long long Helper::timeStampDifference(std::string dateNow, std::string dateOld)
{
	time_t d1 = strToTime(dateNow);
	time_t d2 = strToTime(dateOld);

	int ret = d1 - d2;
	return ret;
}
void Helper::toUpper(std::string & str)
{
	std::for_each(str.begin(), str.end(), [](char & c) {
		c = ::toupper(c);
	});
}


//Converts 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 to ascii char: 0,1,2,3,4,5,6,7,8,9,A,B,C,D,E,F
char Helper::getHexCharFromInt(int number)
{
	char c = '\0';

	if (number > 9)
	{
		if (number == 10)
		{
			c = 'A';
		}
		else if (number == 11)
		{
			c = 'B';
		}
		else if (number == 12)
		{
			c = 'C';
		}
		else if (number == 13)
		{
			c = 'D';
		}
		else if (number == 14)
		{
			c = 'E';
		}
		else if (number == 15)
		{
			c = 'F';
		}
	}
	else
	{
		std::string s = std::to_string(number);
		c = s[0];
	}
	return c;
}

void Helper::findAndReplaceAll(std::string & data, std::string toSearch, std::string replaceStr)
{
	// Get the first occurrence
	size_t pos = data.find(toSearch);

	// Repeat till end is reached
	while (pos != std::string::npos)
	{
		// Replace this occurrence of Sub String
		data.replace(pos, toSearch.size(), replaceStr);
		// Get the next occurrence from the current position
		pos = data.find(toSearch, pos + replaceStr.size());
	}
}
