#pragma once
#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <string.h>
#include <string>
#include <vector>
#include <Windows.h>

#include "../Define/Define.h"
#include "../Model/Player.h"
#include "../Model/Stone.h"
#include "../Model/GameMap.h"
#include "../Model/Gate.h"
#include "../Model/Explode.h"
#include "../Model/Key.h"
#include "../Model/UnableMovingRock.h"
#include "../Model/AbleMovingRock.h"
#include "../Model/TimeBar.h"
#include "../Model/Boom.h"

#include "SFML/Graphics.hpp"
using namespace std;
using namespace sf;

class ResourceManager {
private:
	static ResourceManager* s_Instance;
	string m_dataFolderPath;
	map<int, char[100]> m_Level;//all link to each level
	map<int, char*> m_PlayerImage;
	map<int, char*> m_StoneImage;
	map<int, char[100]> m_UnRockImage;
	map<int, char[100]> m_RockImage;
	map<int, char[100]> m_SupperStoneImage;
	map<int, char[100]> m_Key;
	map<int, char[100]> m_Gate;
	map<int, char[100]> m_TimeBar;
	map<int, char[100]> m_Explode;
	map<int, char[100]> m_boom;
	static ResourceManager* s_instance;

public:
	~ResourceManager() {
		for (map<int, char*>::iterator it = m_PlayerImage.begin(); it != m_PlayerImage.end(); it++) {
			delete it->second;
		}

		for (map<int, char*>::iterator it = m_StoneImage.begin(); it != m_StoneImage.end(); it++) {
			delete it->second;
		}

		delete s_instance;
	}
	static ResourceManager* getInstance();
	void Init();
	void loadData();
	void loadLevel(vector<Stone> &stone, vector<UnableMovingRock> &unRock, vector<AbleMovingRock> &Rock, Player &player,Gate &gate,TimeBar &timebar, vector<Boom> &boom, int levelID = 1);
	char* getPlayerImage(int ID);
	char* getStoneImage(int ID);
	char* getUnRockImage(int ID);
	char* getRockImage(int ID);
	char* getSupperStoneImage(int ID);

	char* getLevelID(int ID);
	char* getGateImage(int ID);
	char* getKeyImage(int ID);
	char* getTimeBarImage(int ID);
	char* getExplodeImage(int ID);
	char* getBoomImage(int ID);
	int getMaxLevel();
};

ResourceManager* ResourceManager::s_Instance = NULL;

ResourceManager* ResourceManager::getInstance() {
	if (s_Instance == NULL)
		s_Instance = new ResourceManager();
	return s_Instance;
}

void ResourceManager::Init() {
	m_dataFolderPath = ROOTFOLDER;
	//get size of map
	
}

void ResourceManager::loadData() {
	LPSTR Path = NULL;
	Path = new CHAR[255];
	GetCurrentDirectory(255, Path);

	strcat(Path, "\\resources\\");
	strcat(Path, m_dataFolderPath.c_str());

	const int BUFFERSIZE = 255;
	char tempPath[BUFFERSIZE] = "";
	char K[3] = "K1";
	
	//get level
	int quantity = GetPrivateProfileInt("LEVEL", "Quantity", 0, Path);
	for (int i = 0; i < quantity; i++) {
		K[1] = i + 1 + 48;
		GetPrivateProfileStringA("LEVEL", K, "", tempPath, BUFFERSIZE, Path);
		if (strcmp(tempPath, "") != 0) {
			strcpy(m_Level[i], tempPath);
			strcpy(tempPath, "");
		}
	}
	//get player
	quantity = GetPrivateProfileInt("PLAYER", "Quantity", 0, Path);
	for (int i = 0; i < quantity; i++) {
		K[1] = i + 1 + 48;
		GetPrivateProfileStringA("PLAYER", K, "", tempPath, BUFFERSIZE, Path);
		if (strcmp(tempPath, "") != 0) {
			m_PlayerImage[i] = new char[100];
			strcpy(m_PlayerImage[i], tempPath);
			strcpy(tempPath, "");
		}
	}
	//get stone
	quantity = GetPrivateProfileInt("STONE", "Quantity", 0, Path);
	for (int i = 0; i < quantity; i++) {
		K[1] = i + 1 + 48;
		GetPrivateProfileStringA("STONE", K, "", tempPath, BUFFERSIZE, Path);
		if (strcmp(tempPath, "") != 0) {
			m_StoneImage[i] = new char[100];
			strcpy(m_StoneImage[i], tempPath);
			strcpy(tempPath, "");
		}
	}
	//get unablemovingrock
	quantity = GetPrivateProfileInt("UNABLEMOVINGROCK", "Quantity", 0, Path);
	for (int i = 0; i < quantity; i++) {
		K[1] = i + 1 + 48;
		GetPrivateProfileStringA("UNABLEMOVINGROCK", K, "", tempPath, BUFFERSIZE, Path);
		if (strcmp(tempPath, "") != 0) {
			strcpy(m_UnRockImage[i], tempPath);
			strcpy(tempPath, "");
		}
	}
	//get ablemovingrock
	quantity = GetPrivateProfileInt("ABLEMOVINGROCK", "Quantity", 0, Path);
	for (int i = 0; i < quantity; i++) {
		K[1] = i + 1 + 48;
		GetPrivateProfileStringA("ABLEMOVINGROCK", K, "", tempPath, BUFFERSIZE, Path);
		if (strcmp(tempPath, "") != 0) {
			strcpy(m_RockImage[i], tempPath);
			strcpy(tempPath, "");
		}
	}
	//get supperstone
	quantity = GetPrivateProfileInt("SUPPERSTONE", "Quantity", 0, Path);
	for (int i = 0; i < quantity; i++) {
		K[1] = i + 1 + 48;
		GetPrivateProfileStringA("SUPPERSTONE", K, "", tempPath, BUFFERSIZE, Path);
		if (strcmp(tempPath, "") != 0) {
			strcpy(m_SupperStoneImage[i], tempPath);
			strcpy(tempPath, "");
		}
	}

	//get key
	quantity = GetPrivateProfileInt("KEY", "Quantity", 0, Path);
	for (int i = 0; i < quantity; i++) {
		K[1] = i + 1 + 48;
		GetPrivateProfileStringA("KEY", K, "", tempPath, BUFFERSIZE, Path);
		if (strcmp(tempPath, "") != 0) {
			strcpy(m_Key[i], tempPath);
			strcpy(tempPath, "");
		}
	}

	//get gate
	quantity = GetPrivateProfileInt("GATE", "Quantity", 0, Path);
	for (int i = 0; i < quantity; i++) {
		K[1] = i + 1 + 48;
		GetPrivateProfileStringA("GATE", K, "", tempPath, BUFFERSIZE, Path);
		if (strcmp(tempPath, "") != 0) {
			strcpy(m_Gate[i], tempPath);
			strcpy(tempPath, "");
		}
	}

	//get TimeBar
	quantity = GetPrivateProfileInt("TIMEBAR", "Quantity", 0, Path);
	for (int i = 0; i < quantity; i++) {
		K[1] = i + 1 + 48;
		GetPrivateProfileStringA("TIMEBAR", K, "", tempPath, BUFFERSIZE, Path);
		if (strcmp(tempPath, "") != 0) {
			strcpy(m_TimeBar[i], tempPath);
			strcpy(tempPath, "");
		}
	}

	//get Explode
	quantity = GetPrivateProfileInt("EXPLODE", "Quantity", 0, Path);
	for (int i = 0; i < quantity; i++) {
		K[1] = i + 1 + 48;
		GetPrivateProfileStringA("EXPLODE", K, "", tempPath, BUFFERSIZE, Path);
		if (strcmp(tempPath, "") != 0) {
			strcpy(m_Explode[i], tempPath);
			strcpy(tempPath, "");
		}
	}

	//get boom
	quantity = GetPrivateProfileInt("BOOM", "Quantity", 0, Path);
	for (int i = 0; i < quantity; i++) {
		K[1] = i + 1 + 48;
		GetPrivateProfileStringA("BOOM", K, "", tempPath, BUFFERSIZE, Path);
		if (strcmp(tempPath, "") != 0) {
			strcpy(m_boom[i], tempPath);
			strcpy(tempPath, "");
		}
	}
}

void ResourceManager::loadLevel(vector<Stone> &stone, vector<UnableMovingRock> &unRock, vector<AbleMovingRock> &Rock, Player &player, Gate &gate,TimeBar &timebar,vector<Boom> &boom, int levelID ) {
	LPSTR Path = NULL;
	Path = new CHAR[255];
	GetCurrentDirectory(255, Path);

	strcat(Path, "\\resources\\");
	strcat(Path, m_Level[levelID]);

	const int BUFFERSIZE = 255;
	char tempPath[BUFFERSIZE] = "";
	int quantity;
	char K[3] = "K1";
	int posx, posy;
	int color;

	GameMap::resizeMap();//reset game map 

	//get player
	posx = GetPrivateProfileInt("PLAYER", "PosX", 0, Path);
	posy = GetPrivateProfileInt("PLAYER", "PosY", 0, Path);
	color = GetPrivateProfileInt("PLAYER", "Color", 1, Path);
	player.setPosx(posx);
	player.setPosy(posy);
	player.setColor(color);
	player.setM_mapx((posx - MAP_BORDER_X_MIN-P_SIZE+2) / (P_SIZE-2));
	player.setM_mapy((posy - MAP_BORDER_Y_MIN) / P_SIZE);
	GameMap::m_map[(posx - MAP_BORDER_X_MIN - P_SIZE + 2) / (P_SIZE - 2)][(posy - MAP_BORDER_Y_MIN) / P_SIZE] = PLAYER_ID; //update to 2D-array map 

	//get stone
	quantity = GetPrivateProfileInt("STONE", "Quantity", 0, Path);
	Stone tempStone;
	/*char POSXK[6] = "PosX1";
	char POSYK[6] = "PosY1";*/
	char COLORK[7] = "Color1";
	string px, py;

	for (int i = 0; i < quantity; i++) {
		px = "PosX" + to_string(i + 1);
		py = "PosY" + to_string(i + 1);
		COLORK[5] = i + 1 + 48;
		posx = GetPrivateProfileInt("STONE", px.c_str(), 0, Path);
		posy = GetPrivateProfileInt("STONE", py.c_str(), 0, Path);
		color = GetPrivateProfileInt("STONE", COLORK, 1, Path);

		tempStone.setPosx(posx);
		tempStone.setPosy(posy);
		tempStone.setColor(color);
		tempStone.setM_mapx((posx - MAP_BORDER_X_MIN - P_SIZE + 2) / (P_SIZE - 2));
		tempStone.setM_mapy((posy - MAP_BORDER_Y_MIN) / P_SIZE);
		GameMap::m_map[(posx - MAP_BORDER_X_MIN - P_SIZE + 2) / (P_SIZE - 2)][(posy - MAP_BORDER_Y_MIN) / P_SIZE] = color; //update to 2D-array map  color; //color == STONE_ID

		stone.push_back(tempStone);
	}

	//get unablemovingrock
	quantity = GetPrivateProfileInt("UNABLEMOVINGROCK", "Quantity", 0, Path);
	UnableMovingRock tempUnRock;
	
	for (int i = 0; i < quantity; i++) {
		
		px = "PosX"+ to_string(i + 1);
		py = "PosY" + to_string(i + 1);
		posx = GetPrivateProfileInt("UNABLEMOVINGROCK", px.c_str(), 0, Path);
		posy = GetPrivateProfileInt("UNABLEMOVINGROCK", py.c_str(), 0, Path);
	
		tempUnRock.setPosx(posx);
		tempUnRock.setPosy(posy);
		tempUnRock.setM_mapx((posx - MAP_BORDER_X_MIN - P_SIZE + 2) / (P_SIZE - 2));
		tempUnRock.setM_mapy((posy - MAP_BORDER_Y_MIN) / P_SIZE);
		GameMap::m_map[(posx - MAP_BORDER_X_MIN - P_SIZE + 2) / (P_SIZE - 2)][(posy - MAP_BORDER_Y_MIN) / P_SIZE] = UNABLEMOVINGROCK_ID;

		unRock.push_back(tempUnRock);
	}

	//get stone
	quantity = GetPrivateProfileInt("ABLEMOVINGROCK", "Quantity", 0, Path);
	AbleMovingRock tempRock;
	for (int i = 0; i < quantity; i++) {
		px = "PosX" + to_string(i + 1);
		py = "PosY" + to_string(i + 1);
		posx = GetPrivateProfileInt("ABLEMOVINGROCK", px.c_str(), 0, Path);
		posy = GetPrivateProfileInt("ABLEMOVINGROCK", py.c_str(), 0, Path);

		tempRock.setPosx(posx);
		tempRock.setPosy(posy);
		int x = (posx - MAP_BORDER_X_MIN - P_SIZE + 2) / (P_SIZE - 2);
		int y = (posy - MAP_BORDER_Y_MIN) / P_SIZE;
		tempRock.setM_mapx(x);
		tempRock.setM_mapy(y);
		GameMap::m_map[(posx - MAP_BORDER_X_MIN - P_SIZE + 2) / (P_SIZE - 2)][(posy - MAP_BORDER_Y_MIN) / P_SIZE] = ABLEMOVINGROCK_ID;

		Rock.push_back(tempRock);
	}

	//get key
	int key = GetPrivateProfileInt("KEY", "StoneID", 0, Path);
	stone[key].setIsKey(true);

	//gate
	posx = GetPrivateProfileInt("GATE", "PosX", 0, Path);
	posy = GetPrivateProfileInt("GATE", "PosY", 0, Path);
	gate.setPosx(posx);
	gate.setPosy(posy);

	
	//Timebar
	posx = GetPrivateProfileInt("TIMEBAR", "PosX", 0, Path);
	posy = GetPrivateProfileInt("TIMEBAR", "PosY", 0, Path);
	timebar.setPosx(posx);
	timebar.setPosy(posy);

	//Boom
	quantity = GetPrivateProfileInt("BOOM", "Quantity", 0, Path);
	Boom boom1;
	for (int i = 0; i < quantity; i++) {
		px = "PosX" + to_string(i + 1);
		py = "PosY" + to_string(i + 1);
		posx = GetPrivateProfileInt("BOOM", px.c_str(), 0, Path);
		posy = GetPrivateProfileInt("BOOM", py.c_str(), 0, Path);
		
		boom1.setPosx(posx);
		boom1.setPosy(posy);
		int x = (posx - MAP_BORDER_X_MIN - P_SIZE + 2) / (P_SIZE - 2);
		int y = (posy - MAP_BORDER_Y_MIN) / P_SIZE;
		boom1.setM_mapx(x);
		boom1.setM_mapy(y);
		GameMap::m_map[(posx - MAP_BORDER_X_MIN - P_SIZE + 2) / (P_SIZE - 2)][(posy - MAP_BORDER_Y_MIN) / P_SIZE] = BOOM_ID;

		boom.push_back(boom1);
	}
}

char* ResourceManager::getPlayerImage(int ID) {
	if (m_PlayerImage.find(ID) != m_PlayerImage.end())
	{
		return m_PlayerImage[ID];
	}
	return NULL;
}

char* ResourceManager::getStoneImage(int ID) {
	if (m_StoneImage.find(ID) != m_StoneImage.end())
	{
		return m_StoneImage[ID];
	}
	return NULL;
}

char* ResourceManager::getUnRockImage(int ID) {
	if (m_UnRockImage.find(ID) != m_UnRockImage.end())
	{
		return m_UnRockImage[ID];
	}
	return NULL;
}

char* ResourceManager::getRockImage(int ID) {
	if (m_RockImage.find(ID) != m_RockImage.end())
	{
		return m_RockImage[ID];
	}
	return NULL;
}

char* ResourceManager::getSupperStoneImage(int ID) {
	if (m_SupperStoneImage.find(ID) != m_SupperStoneImage.end())
	{
		return m_SupperStoneImage[ID];
	}
	return NULL;
}

char* ResourceManager::getLevelID(int ID) {
	if (m_Level.find(ID) != m_Level.end())
	{
		return m_Level[ID];
	}
	return NULL;
}
char* ResourceManager::getGateImage(int ID) {
	if (m_Gate.find(ID) != m_Gate.end())
	{
		return m_Gate[ID];
	}
	return NULL;
}
char* ResourceManager::getKeyImage(int ID) {
	if (m_Key.find(ID) != m_Key.end())
	{
		return m_Key[ID];
	}
	return NULL;
}

char* ResourceManager::getTimeBarImage(int ID) {
	if (m_TimeBar.find(ID) != m_TimeBar.end())
	{
		return m_TimeBar[ID];
	}
	return NULL;
}

char* ResourceManager::getExplodeImage(int ID) {
	if (m_Explode.find(ID) != m_Explode.end())
	{
		return m_Explode[ID];
	}
	return NULL;
}
char* ResourceManager::getBoomImage(int ID) {
	if (m_boom.find(ID) != m_boom.end())
	{
		return m_boom[ID];
	}
	return NULL;
}
int ResourceManager::getMaxLevel() {
	return m_Level.size();
}