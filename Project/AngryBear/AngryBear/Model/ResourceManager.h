#pragma once
#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <string.h>
#include <vector>


#include "../Define/Define.h"
#include "UnableMovingRock.h"
#include "AbleMovingRock.h"
#include "Stone.h"
#include "SFML/Graphics.hpp"
using namespace std;
using namespace sf;

class ResourceManager {
private:
	static ResourceManager* s_Instance;
	string m_dataFolderPath;
	map<int, char*> m_Level;//all link to each level
	map<int, char*> m_Image;//all link to each image
	static ResourceManager* s_instance;

public:
	static ResourceManager* getInstance();
	void Init();
	void loadData(const char *dataPath = ROOTFOLDER);
	void loadLevel(vector<Stone*> &stone, vector<UnableMovingRock*> &unRock, vector<AbleMovingRock*> &Rock, int levelID = 0);
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
	fstream f;
	f.open(dataPath, ios::in, ios::binary);
	char datatType[20];
	char type[20];
	int quantity;
	char ID[10];
	int id;
	char PATH[50];
	if (f) {
		for (int i = 0; i < 2; i++) {
			f.read(datatType, sizeof(datatType));
			sscanf(datatType, "%s %d", type, &quantity);

			if (strcmp(type, "#LEVEL") == 0) {
				for (int j = 0; j < quantity; j++) {
					f.read(ID, sizeof(ID));
					sscanf(ID, "%s %d", type, &id);
					f.read(PATH, sizeof(PATH));
					m_Level[id] = PATH;
				}
			}
			else if (strcmp(type, "#IMAGE") == 0) {
				for (int j = 0; j < quantity; j++) {
					f.read(ID, sizeof(ID));
					sscanf(ID, "%s %d", type, &id);
					f.read(PATH, sizeof(PATH));
					sscanf(ID, "%s %s", type, PATH);
					m_Image[id] = PATH;
				}
			}
		}
	}
	f.close();
}

void ResourceManager::loadLevel(vector<Stone*> &stone, vector<UnableMovingRock*> &unRock, vector<AbleMovingRock*> &Rock, int levelID = 0) {
	if (m_Level.find(levelID) != m_Level.end())
	{
		fstream f;
		f.open(m_Level[levelID], ios::in, ios::binary);
		int typeQuantity;
		int quantity;
		int id;
		int color;
		int x, y;

		char Input[60];
		char typeName[20];
		//char ID[10];
		if (f) {
			f.read(Input, 20);
			sscanf(Input, "%s %d", typeName, &typeQuantity);
			for (int i = 0; i < typeQuantity; i++) {
				f.read(Input, 50);
				sscanf(Input, "%s %d", typeName, &quantity);

				if (strcmp(typeName, "#STONE") == 0) {
					Stone *s;
					for (int i = 0; i < quantity; i++) {
						s = new Stone();
						f.read(Input, 10);
						sscanf(Input, "%s %d", typeName, &id);
						f.read(Input, 20);
						sscanf(Input, "%d %d %d", &color, &x, &y);
						s->setColor(color);
						s->setPosx(x);
						s->setPosy(y);
						stone.push_back(s);
					}
				}
				else if (strcmp(typeName, "#UNABLEMOVINGROCK") == 0) {
					UnableMovingRock* r;
					for (int i = 0; i < quantity; i++) {
						r = new UnableMovingRock();
						f.read(Input, 10);
						sscanf(Input, "%s %d", typeName, &id);
						f.read(Input, 20);
						sscanf(Input, "%d %d", &x, &y);
						r->setPosx(x);
						r->setPosy(y);
						unRock.push_back(r);
					}
				}
				else if (strcmp(typeName, "#ABLEMOVINGROCK") == 0) {
					AbleMovingRock* r;
					for (int i = 0; i < quantity; i++) {
						r = new AbleMovingRock();
						f.read(Input, 10);
						sscanf(Input, "%s %d", typeName, &id);
						f.read(Input, 20);
						sscanf(Input, "%d %d", &x, &y);
						r->setPosx(x);
						r->setPosy(y);
						Rock.push_back(r);
					}
				}
			}
			f.read(Input, 10);
			if (strcmp(Input, "#KEY") == 0)
			{
				f.read(Input, 20);
				sscanf(Input, "%s %d", typeName, &id);
				stone[id]->setIsKey(true);
			}

		}

		f.close();
	}
}

char* ResourceManager::getImageID(int ID) {
	if (m_Image.find(ID) != m_Image.end())
	{
		return m_Image[ID];
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