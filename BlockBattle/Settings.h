#pragma once

#include "Header.h"

enum PieceType
{
	NoPiece,
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
	static int TimeRemaining;
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
	static vector<vector<char>> HeroField;

	// Villain state
	static int VillainPoints;
	static int VillainCombo;
	static vector<vector<char>> VillainField;

	static void ParseSetting (string setting, string value);
	static void ParseUpdate (string updateable, string setting, string value);
	static void ParseAction (string setting, string value);

protected:
	static PieceType ParsePieceType (string pieceType);
	static Position ParsePiecePosition (string piecePosition);
	static vector<vector<char>> ParseField (string fieldString);

private:
	Settings ();
	~Settings ();
};

