#include <iostream>
#include <fstream>
#include <string.h>
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

	char LevelPath[][50] = {
	"asdasdasd",
	"adasdasdsa"
	};
	char player[][50] = {
		"asdasda",
		"asdasdasdas"
	};
	stone Stonepath[4];

	char UnrockPath[][50] = {
		"asdasda",
		"asdasdasdas"
	};
	char RockPath[][50] = {
		"asdasda",
		"asdasdasdas"
	};
	char key[50] = "asdasdasd";
	char supperStone[50] = "asdasdadas";

	Stonepath[0].color = 1;
	strcpy(Stonepath[0].path, "asdasda");
	Stonepath[1].color = 1;
	strcpy(Stonepath[1].path, "asdasda");
	Stonepath[2].color = 1;
	strcpy(Stonepath[2].path, "asdasda");
	Stonepath[3].color = 1;
	strcpy(Stonepath[3].path, "asdasda");
	fstream f;
	f.open("FileResource.bin", ios::out, ios::binary);

	//write level path
	f.write("#LEVEL 1", 20);
	f.write((char *)LevelPath, sizeof(LevelPath));

	//write player path
	f.write("#PLAYER 4", 20);
	f.write((char *)player, sizeof(player));

	//write stone path
	f.write("#STONE 4", 20);
	f.write((char *)Stonepath, sizeof(Stonepath));

	//write unrock path
	f.write("#UNROCK 4", 20);
	f.write((char *)UnrockPath, sizeof(UnrockPath));

	//write rock path
	f.write("#ROCK 4", 20);
	f.write((char *)RockPath, sizeof(RockPath));

	//write key path
	f.write("#KEY 1", 20);
	f.write((char *)key, sizeof(key));

	//write supper stone path
	f.write("#SUPPERSTONE 1", 20);
	f.write((char *)supperStone, sizeof(supperStone));

	f.close();
}

void WriteLevelFile() {
	pointforstone StonePoint[4];
	point *player = new point;
	point lava[4];
	point unrock[4];
	point rock[4];
	
	StonePoint[0].color = 1;
	StonePoint[0].x = 10;
	StonePoint[0].y = 10;

	StonePoint[1].color = 2;
	StonePoint[1].x = 10;
	StonePoint[1].y = 10;

	StonePoint[2].color = 3;
	StonePoint[2].x = 10;
	StonePoint[3].y = 10;

	StonePoint[3].color = 4;
	StonePoint[3].x = 10;
	StonePoint[3].y = 10;

	player->x = 10;
	player->y = 10;

	lava[0].x = 10; lava[0].y = 10;
	lava[1].x = 10; lava[1].y = 10;
	lava[2].x = 10; lava[2].y = 10;
	lava[3].x = 10; lava[3].y = 10;

	unrock[0].x = 10; unrock[0].y = 10;
	unrock[1].x = 10; unrock[1].y = 10;
	unrock[2].x = 10; unrock[2].y = 10;
	unrock[3].x = 10; unrock[3].y = 10;

	rock[0].x = 10; rock[0].y = 10;
	rock[1].x = 10; rock[1].y = 10;
	rock[2].x = 10; rock[2].y = 10;
	rock[3].x = 10; rock[3].y = 10;

	fstream f;
	f.open("FileResource.bin", ios::out, ios::binary);

	//write level path
	f.write("#STONE 4", 20);
	f.write((char *)StonePoint, sizeof(StonePoint));

	//write lava path
	f.write("#LAVA 4", 20);
	f.write((char *)lava, sizeof(lava));

	//write unrock path
	f.write("#UNROCK 4", 20);
	f.write((char *)rock, sizeof(rock));

	//write rock path
	f.write("#ROCK 4", 20);
	f.write((char *)StonePoint, sizeof(StonePoint));

	//write player path
	f.write("#PLAYER", 20);
	f.write((char *)player, sizeof(player));

	//write key path
	f.write("#KEY 1", 20);
	char key[20] = "STONEID 1";
	f.write(key, sizeof(key));

	f.close();
}

int main() {
	
	WriteLevelFile();
	//WriteResourceFile();
}