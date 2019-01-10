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
#include "Background.h"
#include "Gate.h"
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
	void loadLevel(vector<Stone> &stone, vector<UnableMovingRock> &unRock, vector<AbleMovingRock> &Rock, Player &player,Gate &gate, int levelID = 1);
	char* getPlayerImage(int ID);
	char* getStoneImage(int ID);
	char* getUnRockImage(int ID);
	char* getRockImage(int ID);
	char* getSupperStoneImage(int ID);

	char* getLevelID(int ID);
	char* getGateImage(int ID);
	char* getKeyImage(int ID);
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

void ResourceManager::loadData() {
	LPSTR Path = NULL;
	Path = new CHAR[255];
	GetCurrentDirectory(255, Path);

	strcat(Path, "\\resources\\");
	strcat(Path, m_dataFolderPath.c_str());

	const int BUFFERSIZE = 255;
	char tempPath[BUFFERSIZE] = "";
	char K[3] = "K1";
	
	//get size of map

	Background::resizeMap();

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
		/*	Texture t;
			t.loadFromFile(tempPath);
			m_PlayerImage[i] = t;*/
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
			/*Texture t;
			t.loadFromFile(tempPath);
			m_StoneImage[i] = t;*/
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

	//get key
	quantity = GetPrivateProfileInt("GATE", "Quantity", 0, Path);
	for (int i = 0; i < quantity; i++) {
		K[1] = i + 1 + 48;
		GetPrivateProfileStringA("GATE", K, "", tempPath, BUFFERSIZE, Path);
		if (strcmp(tempPath, "") != 0) {
			strcpy(m_Gate[i], tempPath);
			strcpy(tempPath, "");
		}
	}

}

void ResourceManager::loadLevel(vector<Stone> &stone, vector<UnableMovingRock> &unRock, vector<AbleMovingRock> &Rock, Player &player, Gate &gate, int levelID ) {
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

	//get player
	posx = GetPrivateProfileInt("PLAYER", "PosX", 0, Path);
	posy = GetPrivateProfileInt("PLAYER", "PosY", 0, Path);
	color = GetPrivateProfileInt("PLAYER", "Color", 1, Path);
	player.setPosx(posx);
	player.setPosy(posy);
	player.setColor(color);
	player.setM_mapx((posx - MAP_BORDER_X_MIN-P_SIZE+2) / (P_SIZE-2));
	player.setM_mapy((posy - MAP_BORDER_Y_MIN) / P_SIZE);
	Background::m_map[(posx - MAP_BORDER_X_MIN - P_SIZE + 2) / (P_SIZE - 2)][(posy - MAP_BORDER_Y_MIN) / P_SIZE] = PLAYER_ID; //update to 2D-array map 

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
		tempStone.setM_mapx((posx - MAP_BORDER_X_MIN - P_SIZE + 2) / (P_SIZE - 2));
		tempStone.setM_mapy((posy - MAP_BORDER_Y_MIN) / P_SIZE);
		Background::m_map[(posx - MAP_BORDER_X_MIN - P_SIZE + 2) / (P_SIZE - 2)][(posy - MAP_BORDER_Y_MIN) / P_SIZE] = color; //update to 2D-array map  color; //color == STONE_ID

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
		tempUnRock.setM_mapx((posx - MAP_BORDER_X_MIN) / CHARACTER_W);
		tempUnRock.setM_mapy((posy - MAP_BORDER_Y_MIN) / CHARACTER_H);
		Background::m_map[(posx - MAP_BORDER_X_MIN) / CHARACTER_W][(posy - MAP_BORDER_Y_MIN) / CHARACTER_H] = UNABLEMOVINGROCK_ID;

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
		tempRock.setM_mapx(posx / CHARACTER_W);
		tempRock.setM_mapy(posy / CHARACTER_H);
		Background::m_map[posx / CHARACTER_W][posy / CHARACTER_H] = ABLEMOVINGROCK_ID;

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