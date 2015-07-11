#pragma once

#include "Header.h"

enum PieceType
{
	I,
	T,
	J,
	L,
	S,
	Z,
	O
};

struct Position
{
	int X;
	int Y;

	Position (int x, int y)
	{
		X = x;
		Y = y;
	}
};

class Settings
{
public:
	// Global settings
	static int TimeBank;
	static int TimePerMove;
	static string HeroName;
	static string VillainName;
	static int FieldHeight;
	static int FieldWidth;

	// Game state
	static int CurrentRound;
	static PieceType CurrentPiece;
	static PieceType NextPiece;
	static Position PiecePosition;

	// Hero state
	static int HeroPoints;
	static int HeroCombo;
	static vector<vector<int>> HeroField;

	// Villain state
	static int VillainPoints;
	static int VillainCombo;
	static vector<vector<int>> VillainField;

	static void ParseSetting (string setting, string value);
	static void ParseUpdate (string updateable, string setting, string value);

protected:
	static PieceType ParsePieceType (string pieceType);
	static Position ParsePiecePosition (string piecePosition);
	static vector<vector<int>> ParseField (string fieldString);

private:
	Settings ();
	~Settings ();
};

