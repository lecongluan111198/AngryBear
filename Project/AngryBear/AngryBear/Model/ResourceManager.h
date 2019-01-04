#pragma once
#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <string.h>
#include <vector>
#include <Windows.h>


#include "../Define/Define.h"
#include "UnableMovingRock.h"
#include "AbleMovingRock.h"
#include "Stone.h"
#include "Player.h"
#include "SFML/Graphics.hpp"
using namespace std;
using namespace sf;

class ResourceManager {
private:
	static ResourceManager* s_Instance;
	string m_dataFolderPath;
	map<int, char[100]> m_Level;//all link to each level
	map<int, char[100]> m_PlayerImage;
	map<int, char[100]> m_StoneImage;
	map<int, char[100]> m_UnRockImage;
	map<int, char[100]> m_RockImage;
	map<int, char[100]> m_SupperStoneImage;
	static ResourceManager* s_instance;

public:
	static ResourceManager* getInstance();
	void Init();
	void loadData(const char *dataPath = ROOTFOLDER);
	void loadLevel(vector<Stone> &stone, vector<UnableMovingRock> &unRock, vector<AbleMovingRock> &Rock, Player &player, int levelID = 0);
	char* getImageID(int ID);
	char* getLevelID(int ID);
};

ResourceManager* ResourceManager::s_Instance = NULL;

ResourceManager* ResourceManager::getInstance() {
	if (s_Instance == NULL)
		s_Instance = new ResourceManager();
	return s_Instance;
}

void ResourceManager::Init() {
	m_dataFolderPath = ROOTFOLDER;
}

void ResourceManager::loadData(const char *dataPath = ROOTFOLDER) {
	LPSTR Path = NULL;
	Path = new CHAR[255];
	GetCurrentDirectory(255, Path);

	strcat(Path, "\\");
	strcat(Path, "FileResource.ini");

	const int BUFFERSIZE = 255;
	char tempPath[BUFFERSIZE] = "";
	char K[3] = "K1";

	//get level
	int nLevel = GetPrivateProfileInt("LEVEL", "Quantity", 0, Path);
	for (int i = 0; i < nLevel; i++) {
		K[1] = i + 1 + 48;
		GetPrivateProfileStringA("LEVEL", K, "", tempPath, BUFFERSIZE, Path);
		if (strcmp(tempPath, "") != 0) {
			strcpy(m_Level[i], tempPath);
			strcpy(tempPath, "");
		}
	}
	//get player
	int nLevel = GetPrivateProfileInt("PLAYER", "Quantity", 0, Path);
	for (int i = 0; i < nLevel; i++) {
		K[1] = i + 1 + 48;
		GetPrivateProfileStringA("PLAYER", K, "", tempPath, BUFFERSIZE, Path);
		if (strcmp(tempPath, "") != 0) {
			strcpy(m_PlayerImage[i], tempPath);
			strcpy(tempPath, "");
		}
	}
	//get stone
	int nLevel = GetPrivateProfileInt("STONE", "Quantity", 0, Path);
	for (int i = 0; i < nLevel; i++) {
		K[1] = i + 1 + 48;
		GetPrivateProfileStringA("STONE", K, "", tempPath, BUFFERSIZE, Path);
		if (strcmp(tempPath, "") != 0) {
			strcpy(m_StoneImage[i], tempPath);
			strcpy(tempPath, "");
		}
	}
	//get unablemovingrock
	int nLevel = GetPrivateProfileInt("UNABLEMOVINGROCK", "Quantity", 0, Path);
	for (int i = 0; i < nLevel; i++) {
		K[1] = i + 1 + 48;
		GetPrivateProfileStringA("UNABLEMOVINGROCK", K, "", tempPath, BUFFERSIZE, Path);
		if (strcmp(tempPath, "") != 0) {
			strcpy(m_UnRockImage[i], tempPath);
			strcpy(tempPath, "");
		}
	}
	//get ablemovingrock
	int nLevel = GetPrivateProfileInt("ABLEMOVINGROCK", "Quantity", 0, Path);
	for (int i = 0; i < nLevel; i++) {
		K[1] = i + 1 + 48;
		GetPrivateProfileStringA("ABLEMOVINGROCK", K, "", tempPath, BUFFERSIZE, Path);
		if (strcmp(tempPath, "") != 0) {
			strcpy(m_RockImage[i], tempPath);
			strcpy(tempPath, "");
		}
	}
	//get supperstone
	int nLevel = GetPrivateProfileInt("SUPPERSTONE", "Quantity", 0, Path);
	for (int i = 0; i < nLevel; i++) {
		K[1] = i + 1 + 48;
		GetPrivateProfileStringA("SUPPERSTONE", K, "", tempPath, BUFFERSIZE, Path);
		if (strcmp(tempPath, "") != 0) {
			strcpy(m_SupperStoneImage[i], tempPath);
			strcpy(tempPath, "");
		}
	}

}

void ResourceManager::loadLevel(vector<Stone> &stone, vector<UnableMovingRock> &unRock, vector<AbleMovingRock> &Rock, Player &player,int levelID = 0) {
	LPSTR Path = NULL;
	Path = new CHAR[255];
	GetCurrentDirectory(255, Path);

	strcat(Path, "\\");
	strcat(Path, m_Level[levelID]);

	const int BUFFERSIZE = 255;
	char tempPath[BUFFERSIZE] = "";
	int quantity;
	char K[3] = "K1";
	int posx, posy;
	int color;

	//get player
	posx = GetPrivateProfileInt("PLAYER", "PosX", 0, Path);
	posy = GetPrivateProfileInt("PLAYER", "PosY", 0, Path);
	color = GetPrivateProfileInt("PLAYER", "Color", 1, Path);
	player.setPosx(posx);
	player.setPosy(posy);
	player.setColor(color);

	//get stone
	quantity = GetPrivateProfileInt("STONE", "Quantity", 0, Path);
	Stone tempStone;
	char POSXK[6] = "PosX1";
	char POSYK[6] = "PosY1";
	char COLORK[7] = "Color1";
	for (int i = 0; i < quantity; i++) {
		POSXK[4] = i + 1 + 48;
		POSYK[4] = i + 1 + 48;
		COLORK[5] = i + 1 + 48;
		posx = GetPrivateProfileInt("STONE", POSXK, 0, Path);
		posy = GetPrivateProfileInt("STONE", POSYK, 0, Path);
		color = GetPrivateProfileInt("STONE", COLORK, 1, Path);
		tempStone.setPosx(posx);
		tempStone.setPosy(posy);
		tempStone.setColor(color);
		stone.push_back(tempStone);
	}

	//get unablemovingrock
	quantity = GetPrivateProfileInt("UNABLEMOVINGROCK", "Quantity", 0, Path);
	UnableMovingRock tempUnRock;
	for (int i = 0; i < quantity; i++) {
		POSXK[4] = i + 1 + 48;
		POSYK[4] = i + 1 + 48;
		posx = GetPrivateProfileInt("UNABLEMOVINGROCK", POSXK, 0, Path);
		posy = GetPrivateProfileInt("UNABLEMOVINGROCK", POSYK, 0, Path);
	
		tempUnRock.setPosx(posx);
		tempUnRock.setPosy(posy);
		unRock.push_back(tempUnRock);
	}

	//get stone
	quantity = GetPrivateProfileInt("ABLEMOVINGROCK", "Quantity", 0, Path);
	AbleMovingRock tempRock;
	for (int i = 0; i < quantity; i++) {
		POSXK[4] = i + 1 + 48;
		POSYK[4] = i + 1 + 48;
		posx = GetPrivateProfileInt("ABLEMOVINGROCK", POSXK, 0, Path);
		posy = GetPrivateProfileInt("ABLEMOVINGROCK", POSYK, 0, Path);

		tempRock.setPosx(posx);
		tempRock.setPosy(posy);
		Rock.push_back(tempRock);
	}

	//get key
	int key = GetPrivateProfileInt("KEY", "STONEID", 0, Path);
	stone[key - 1].setIsKey(true);
}


char* ResourceManager::getLevelID(int ID) {
	if (m_Level.find(ID) != m_Level.end())
	{
		return m_Level[ID];
	}
	return NULL;
}