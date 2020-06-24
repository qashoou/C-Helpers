#ifndef __HELPER_H__
#define __HELPER_H__
# if _WIN32 
#define _CRT_SECURE_NO_WARNINGS 1
#endif

#include <vector>


#include <map>
#include <string>


//**************************************************
// Helper class to perform single simple operations
//**************************************************
class Helper
{

public:



#pragma region STRiNG HELPERS
	static std::string implode(std::vector<std::string> vec, const char deli);
	static std::vector<std::string> explode(std::string str, std::string token);


	static void toUpper(std::string & str);

	static void findAndReplaceAll(std::string & data, std::string toSearch, std::string replaceStr);

	static std::wstring s2ws(const std::string& str);
	static std::string ws2s(const std::wstring& wstr);

#pragma endregion

	static char getHexCharFromInt(int number);
#pragma region DATE/TIME HELPERS
	static std::string getCurrentTimeStamp();
	static long long timeStampDifference(std::string dateNow, std::string dateOld);

#pragma endregion


};
#endif //__HELPER_H__

