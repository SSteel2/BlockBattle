#pragma once

#include "Header.h"

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
	static Field HeroField;

	// Villain state
	static int VillainPoints;
	static int VillainCombo;
	static Field VillainField;

	static void ParseSetting (string setting, string value);
	static void ParseUpdate (string updateable, string setting, string value);
	static void ParseAction (string setting, string value);

protected:
	static PieceType ParsePieceType (string pieceType);
	static Position ParsePiecePosition (string piecePosition);
	static Field ParseField (string fieldString); // Fix this

private:
	Settings ();
	~Settings ();
};

