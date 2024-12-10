#ifndef GAME_HPP
#define GAME_HPP
#include "player.hpp"
#include "enemy.hpp"
#include "projectile.hpp"

enum gameState {
	titleScreen, paused, gameOver, shop, deleteData, editor, niveau1A, niveau1B, niveau1C, niveau2A, niveau2B, niveau2C, niveau3A, niveau3B, niveau3C, finalBoss
};

class Game {
public:
	gameState state = niveau1A;
	bool Univeau1A, loadLevel = true;
	bool Univeau2A, Univeau3A, Univeau1B, Univeau2B, Univeau3B, Univeau1C, Univeau2C, Univeau3C, UfinalBoss, isFightingBoss = false;
	int toKill = 0;
	void level1A(EnemyManager& eManager, ProjectileManager& pManager);
	void level1B(EnemyManager& eManager, ProjectileManager& pManager);
	void level1C(EnemyManager& eManager, ProjectileManager& pManager);
	void level2A(EnemyManager& eManager, ProjectileManager& pManager);
	void level2B(EnemyManager& eManager, ProjectileManager& pManager);
	void level2C(EnemyManager& eManager, ProjectileManager& pManager);
	void level3A(EnemyManager& eManager, ProjectileManager& pManager);
	void level3B(EnemyManager& eManager, ProjectileManager& pManager);
	void level3C(EnemyManager& eManager, ProjectileManager& pManager);
};

#endif
