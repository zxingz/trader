// get_data.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm> 
#include <curl/curl.h> 

using namespace std;
//int part = 0;
string data = "";
int code;
string stocks[51] = { "ADANIENT", "ADANIPORTS", "AMBUJACEM", "APOLLOTYRE", "ARVIND", "AXISBANK", "BANKINDIA", "BHARTIARTL", "BHEL", "BIOCON", "CANBK", "COALINDIA", "DABUR", "DLF", "EXIDEIND", "GAIL", "GODREJIND", "HAVELLS", "HEXAWARE", "ICICIBANK", "IDEA", "IDFC", "IGL", "INDIACEM", "IOC", "IRB", "ITC", "JSWENERGY", "KTKBANK", "LICHSGFIN", "M&MFIN", "ONGC", "ORIENTBANK", "PETRONET", "PFC", "POWERGRID", "RECLTD", "RELCAPITAL", "RELINFRA", "SBIN", "SUNTV", "TATACHEM", "TATACOMM", "TATAMOTORS", "TATAMTRDVR", "TATASTEEL", "TITAN", "UNIONBANK", "UPL", "VOLTAS", "ZEEL" };

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
	ofstream myfile;
	string locn = "E:/depth/" + stocks[code] + ".txt";
	myfile.open(locn);
	data = (char*)contents;
	myfile << data.c_str();
	myfile.close();
	data = "";

	return size * nmemb;

}

//int main()
int  WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	cin >> code;
	//code = 3;
	//code = "ACC          ";
	//code.erase(remove_if(code.begin(), code.end(), isspace), code.end());

	CURL *curl;
	curl = curl_easy_init();
	if (curl) {
		curl_easy_setopt(curl, CURLOPT_COOKIEFILE, "E:/COOKIES.txt");
		string link = "https://newtrade.sharekhan.com/rmmweb/mcs.sk?e=450&s=";// ADANIENT&ex = NSE&a = y";
		link = link + stocks[code] + "&ex=NSE&a=y";
		curl_easy_setopt(curl, CURLOPT_URL, link.c_str());
		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
		while (1){
			curl_easy_perform(curl);
		}
		curl_easy_cleanup(curl);
	}
	return 0;
}
