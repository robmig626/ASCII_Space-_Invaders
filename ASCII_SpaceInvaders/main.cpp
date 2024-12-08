#include <iostream>
#include "Game.h"

int main(void)
{
	Game SpaceInvaderGame;

	SpaceInvaderGame.BeginPlay();

	while (!SpaceInvaderGame.GetGameOver())
	{
		SpaceInvaderGame.Tick();
	}
	return 0;
}