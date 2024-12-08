#pragma once
#include "Node.h"

class Bullet : public Node
{
private:
	char Avatar = '|';
	int PosX, PosY;
	int Direction; //1 is up -1 is down
public:
	bool bDestroy = false;
	Bullet(int iPosX, int iPosY, int iDirection);

	void Tick();

	Bullet* GetBullet();
	char GetAvatar();
	int GetPosX();
	int GetPosY();

	void Destroy();
};