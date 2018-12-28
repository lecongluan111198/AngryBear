#pragma once
#include <iostream>
#include <string>
#include <map>

#include "SFML/Graphics.hpp"
using namespace std;
using namespace sf;

class ResourceManager {
private:
	static ResourceManager* s_Instance;
	string m_dataFolderPath;
	map<int, char*> m_Map;//all link to map
	map<int, char*> m_Image;//all link to image
	static ResourceManager* s_instance;

public:
	static ResourceManager* getInstance();
	void Init();
	void loadData(char *dataPath);
	char* getImageID(int ID);
	char* getMapID(int ID);
};

ResourceManager* ResourceManager::s_Instance = NULL;

ResourceManager* ResourceManager::getInstance() {
	if (s_Instance == NULL)
		s_Instance = new ResourceManager();
	return s_Instance;
}

void ResourceManager::Init() {

}