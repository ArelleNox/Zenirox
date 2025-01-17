#include "score.hpp"
#include "player.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <fstream>

using namespace std;
using namespace sf;

int setCurrentScoreText(Player player, Font &scoreFont, Text &scoreText)
{
	scoreText.setString("Score: " + to_string(player.currentScore));
	scoreText.setFillColor(Color::White);
	scoreText.setOutlineColor(Color::Black);
	scoreText.setOutlineThickness(4);
	scoreText.setPosition(0, 50);

	if (!scoreFont.loadFromFile("font.otf")) { cout << "Erreur lors du chargement de la police d'ecriture" << endl; return -1; }
	scoreText.setFont(scoreFont);
}
int setTotalScoreText(Player player, Font& scoreFont, Text& scoreText)
{
	scoreText.setString("       " + to_string(player.totalScore));
	scoreText.setFillColor(Color::White);
	scoreText.setOutlineColor(Color::Black);
	scoreText.setOutlineThickness(4);
	scoreText.setCharacterSize(60);
	scoreText.setPosition(800, 700);

	if (!scoreFont.loadFromFile("font.otf")) { cout << "Erreur lors du chargement de la police d'ecriture" << endl; return -1; }
	scoreText.setFont(scoreFont);
}
void updateScoreText(Player player, Text& scoreText)
{
	scoreText.setString("       " + to_string(player.currentScore));
}
void openData(Player &player, Game &game) {
	ifstream scoreFile("score.txt");
	int totalScore;
	bool nv1B, nv1C, nv2A, nv2B, nv2C, nv3A, nv3B, nv3C, FB, HW;
	scoreFile >> totalScore >> boolalpha >> nv1B >> nv1C >> nv2A >> nv2B >> nv2C >> nv3A >> nv3B >> nv3C >> FB >> HW;
	player.totalScore = totalScore;
	game.Univeau1B = nv1B;
	game.Univeau1C = nv1C;
	game.Univeau2A = nv2A;
	game.Univeau2B = nv2B;
	game.Univeau2C = nv2C;
	game.Univeau3A = nv3A;
	game.Univeau3B = nv3B;
	game.Univeau3C = nv3C;
	game.UfinalBoss = FB;
	game.hasWon = HW;
	scoreFile.close();
	ifstream inventoryFile("inventory.txt");
	bool U1, U2, U3;
	inventoryFile >> boolalpha >> U1 >> U2 >> U3;
	player.UShip1 = U1;
	player.UShip2 = U2;
	player.UShip3 = U3;
	inventoryFile.close();
}
void saveData(Player player, Game &game)
{
	ofstream scoreFile("score.txt");
	if (game.state == niveau1A)
		scoreFile << player.totalScore << ' ' << boolalpha << false << ' ' << false << ' ' << false << ' ' << false << ' ' << false << ' ' << false << ' ' << false << ' ' << false << ' ' << false << ' ' << false << ' ';
	else if (game.state == niveau1B)
	{
		scoreFile << player.totalScore << ' ' << boolalpha << true << ' ' << false << ' ' << false << ' ' << false << ' ' << false << ' ' << false << ' ' << false << ' ' << false << ' ' << false << ' ' << false << ' ';
	}
	else if (game.state == niveau1C)
	{
		scoreFile << player.totalScore << ' ' << boolalpha << true << ' ' << true << ' ' << false << ' ' << false << ' ' << false << ' ' << false << ' ' << false << ' ' << false << ' ' << false << ' ' << false << ' ';
	}
	else if (game.state == niveau2A)
	{
		scoreFile << player.totalScore << ' ' << boolalpha << true << ' ' << true << ' ' << true << ' ' << false << ' ' << false << ' ' << false << ' ' << false << ' ' << false << ' ' << false << ' ' << false << ' ';
	}
	else if (game.state == niveau2B)
	{
		scoreFile << player.totalScore << ' ' << boolalpha << true << ' ' << true << ' ' << true << ' ' << true << ' ' << false << ' ' << false << ' ' << false << ' ' << false << ' ' << false << ' ' << false << ' ';
	}
	else if (game.state == niveau2C)
	{
		scoreFile << player.totalScore << ' ' << boolalpha << true << ' ' << true << ' ' << true << ' ' << true << ' ' << true << ' ' << false << ' ' << false << ' ' << false << ' ' << false << ' ' << false << ' ';
	}
	else if (game.state == niveau3A)
	{
		scoreFile << player.totalScore << ' ' << boolalpha << true << ' ' << true << ' ' << true << ' ' << true << ' ' << true << ' ' << true << ' ' << false << ' ' << false << ' ' << false << ' ' << false << ' ';
	}
	else if (game.state == niveau3B)
	{
		scoreFile << player.totalScore << ' ' << boolalpha << true << ' ' << true << ' ' << true << ' ' << true << ' ' << true << ' ' << true << ' ' << true << ' ' << false << ' ' << false << ' ' << false << ' ';
	}
	else if (game.state == niveau3C)
	{
		scoreFile << player.totalScore << ' ' << boolalpha << true << ' ' << true << ' ' << true << ' ' << true << ' ' << true << ' ' << true << ' ' << true << ' ' << true << ' ' << false << ' ' << false << ' ';
	}
	else if (game.state == finalBoss)
	{
		scoreFile << player.totalScore << ' ' << boolalpha << true << ' ' << true << ' ' << true << ' ' << true << ' ' << true << ' ' << true << ' ' << true << ' ' << true << ' ' << true << ' ' << game.hasWon << ' ';
	}
	scoreFile.close();
	ofstream inventoryFile("inventory.txt");
	inventoryFile << boolalpha << player.UShip1 << ' ' << player.UShip2 << ' ' << player.UShip3;
	inventoryFile.close();
}
void saveCurrentScore(Player& player)
{
	player.totalScore += player.currentScore;
}
void removeData(Player& player, Game &game)
{
	ofstream scoreFile("score.txt");
	scoreFile << 0 << boolalpha << false << ' ' << false << ' ' << false << ' ' << false << ' ' << false << ' ' << false << ' ' << false << ' ' << false << ' ' << false << ' ' << false;
	player.currentScore = 0;
	player.totalScore = 0;
	game.Univeau1B = false;
	game.Univeau1C = false;
	game.Univeau2A = false;
	game.Univeau2B = false;
	game.Univeau2C = false;
	game.Univeau3A = false;
	game.Univeau3B = false;
	game.Univeau3C = false;
	game.UfinalBoss = false;
	game.hasWon = false;
	game.state = niveau1A;
	scoreFile.close();
	ofstream inventoryFile("inventory.txt");
	inventoryFile << boolalpha << false << ' ' << false << ' ' << false;
	player.UShip1 = false;
	player.UShip2 = false;
	player.UShip3 = false;
	inventoryFile.close();
}
void resetQuest(Player &player, Game& game)
{
	ofstream scoreFile("score.txt");
	scoreFile << player.totalScore << boolalpha << false << ' ' << false << ' ' << false << ' ' << false << ' ' << false << ' ' << false << ' ' << false << ' ' << false << ' ' << false << ' ' << false;
	game.Univeau1B = false;
	game.Univeau1C = false;
	game.Univeau2A = false;
	game.Univeau2B = false;
	game.Univeau2C = false;
	game.Univeau3A = false;
	game.Univeau3B = false;
	game.Univeau3C = false;
	game.UfinalBoss = false;
	game.hasWon = false;
}