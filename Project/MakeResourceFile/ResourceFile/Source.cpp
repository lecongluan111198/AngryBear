#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <string>
#include <Windows.h>
#include <map>
using namespace std;

struct stone {
public:
	int color;
	char path[50];
};
struct pointforstone {
	int color;
	int x, y;
};
struct point {
	int x, y;
};


void WriteResourceFile() {
	LPSTR Path = NULL;
	Path = new CHAR[255];
	GetCurrentDirectory(255, Path);

	strcat(Path, "\\");
	strcat(Path, "FileResource.ini");
	vector<string> levelpath;
	levelpath.push_back("..\\level1.ini");
	levelpath.push_back("..\\level2.ini");
	char K[3] = "K1";

	WritePrivateProfileString("LEVEL", "Quantity", std::to_string(levelpath.size()).c_str(), Path);
	for (int i = 0; i < levelpath.size(); i++)
	{
		K[1] = i + 1 + 48;
		WritePrivateProfileString("LEVEL", K, levelpath[i].c_str(), Path);
	}

	//Player
	vector<string> playerpath;
	playerpath.push_back("..\\level1.ini");

	WritePrivateProfileString("PLAYER", "Quantity", std::to_string(playerpath.size()).c_str(), Path);
	for (int i = 0; i < playerpath.size(); i++)
	{
		K[1] = i + 1 + 48;
		WritePrivateProfileString("PLAYER", K, playerpath[i].c_str(), Path);
	}
	
	//Stone
	vector<string> stonepath;
	stonepath.push_back("..\\level1.ini");
	stonepath.push_back("..\\level2.ini");

	WritePrivateProfileString("SRONE", "Quantity", std::to_string(stonepath.size()).c_str(), Path);
	for (int i = 0; i < stonepath.size(); i++)
	{
		K[1] = i + 1 + 48;
		WritePrivateProfileString("SRONE", K, stonepath[i].c_str(), Path);
	}

	//unmovingrock
	vector<string> unrockpath;
	unrockpath.push_back("..\\level1.ini");
	unrockpath.push_back("..\\level2.ini");

	WritePrivateProfileString("UNANBLEMOVINGROCK", "Quantity", std::to_string(unrockpath.size()).c_str(), Path);
	for (int i = 0; i < unrockpath.size(); i++)
	{
		K[1] = i + 1 + 48;
		WritePrivateProfileString("UNANBLEMOVINGROCK", K, unrockpath[i].c_str(), Path);
	}

	//movingrock
	vector<string> rockpath;
	rockpath.push_back("..\\level1.ini");
	rockpath.push_back("..\\level2.ini");

	WritePrivateProfileString("ANBLEMOVINGROCK", "Quantity", std::to_string(rockpath.size()).c_str(), Path);
	for (int i = 0; i < rockpath.size(); i++)
	{
		K[1] = i + 1 + 48;
		WritePrivateProfileString("ANBLEMOVINGROCK", K, rockpath[i].c_str(), Path);
	}

	//super stone
	vector<string> SStonepath;
	SStonepath.push_back("..\\level1.ini");
	SStonepath.push_back("..\\level2.ini");

	WritePrivateProfileString("SUPERSTONE", "Quantity", std::to_string(SStonepath.size()).c_str(), Path);
	for (int i = 0; i < SStonepath.size(); i++)
	{
		K[1] = i + 1 + 48;
		WritePrivateProfileString("SUPERSTONE", K, SStonepath[i].c_str(), Path);
	}



}

void WriteLevelFile() {
	LPSTR Path = NULL;
	Path = new CHAR[255];
	GetCurrentDirectory(255, Path);

	strcat(Path, "\\");
	strcat(Path, "level1.ini");
	vector<string> levelpath;
	char POSXK[6] = "PosX1";
	char POSYK[6] = "PosY1";
	char COLORK[7] = "Color1";

	//player
	char data[10];
	WritePrivateProfileString("PLAYER", "PosX", std::to_string(0).c_str(), Path);
	WritePrivateProfileString("PLAYER", "PosY", std::to_string(0).c_str(), Path);
	WritePrivateProfileString("PLAYER", "Color", std::to_string(1).c_str(), Path);

	//stone
	WritePrivateProfileString("STONE", "Quantity", std::to_string(2).c_str(), Path);
	for (int i = 0; i < 2; i++)
	{
		POSXK[4] = i + 1 + 48;
		POSYK[4] = i + 1 + 48;
		COLORK[5] = i + 1 + 48;
		WritePrivateProfileString("STONE", POSXK, std::to_string((i + 1) * 100).c_str(), Path);
		WritePrivateProfileString("STONE", POSYK, std::to_string((i + 1) * 100).c_str(), Path);
		WritePrivateProfileString("STONE", COLORK, std::to_string(1).c_str(), Path);
	}

	//unablemovingrock
	WritePrivateProfileString("UNABLEMOVINGROCK", "Quantity", std::to_string(0).c_str(), Path);
	for (int i = 0; i < 0; i++)
	{
		POSXK[4] = i + 1 + 48;
		POSYK[4] = i + 1 + 48;
		COLORK[5] = i + 1 + 48;
		WritePrivateProfileString("UNABLEMOVINGROCK", POSXK, std::to_string(100).c_str(), Path);
		WritePrivateProfileString("UNABLEMOVINGROCK", POSYK, std::to_string(100).c_str(), Path);
	}

	//ablemovingrock
	WritePrivateProfileString("ABLEMOVINGROCK", "Quantity", std::to_string(0).c_str(), Path);
	for (int i = 0; i < 0; i++)
	{
		POSXK[4] = i + 1 + 48;
		POSYK[4] = i + 1 + 48;
		COLORK[5] = i + 1 + 48;
		WritePrivateProfileString("ABLEMOVINGROCK", POSXK, std::to_string(100).c_str(), Path);
		WritePrivateProfileString("ABLEMOVINGROCK", POSYK, std::to_string(100).c_str(), Path);
	}

	//key
	WritePrivateProfileString("KEY", "StoneID", std::to_string(0).c_str(), Path);


}
int main() {
	//LPSTR Path = NULL;
	//Path = new CHAR[255];
	//GetCurrentDirectory(255, Path);

	//strcat(Path, "\\");
	//strcat(Path, "FileResource.ini");

	//map<int, char[100]> m_Level;
	////get level
	//int nLevel = GetPrivateProfileInt("LEVEL", "Quantity", 0, Path);
	//const int BUFFERSIZE = 255;
	//char tempPath[BUFFERSIZE] = "";

	//char K[3] = "L1";
	//for (int i = 0; i < nLevel; i++) {
	//	K[1] = i + 1 + 48;
	//	GetPrivateProfileStringA("LEVEL", K, "", tempPath, BUFFERSIZE, Path);
	//	if (strcmp(tempPath, "") != 0) {
	//		strcpy(m_Level[i], tempPath);
	//		strcpy(tempPath, "");
	//	}
	//}
	WriteLevelFile();
	//WriteResourceFile();
	system("pause");
}