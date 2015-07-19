#include "Settings.h"

// Definition of static variables
int Settings::TimeBank       = 0;
int Settings::TimePerMove    = 0;
int Settings::TimeRemaining  = 0;
string Settings::HeroName    = "Hero";
string Settings::VillainName = "Villain";
int Settings::FieldHeight    = 0;
int Settings::FieldWidth     = 0;

int Settings::CurrentRound       = 0;
PieceType Settings::CurrentPiece = PieceType::NoPiece;
PieceType Settings::NextPiece    = PieceType::NoPiece;
Position Settings::PiecePosition (0, 0);

int Settings::HeroPoints = 0;
int Settings::HeroCombo  = 0;
Field Settings::HeroField (0, vector<char> (0, 0));

int Settings::VillainPoints = 0;
int Settings::VillainCombo  = 0;
Field Settings::VillainField (0, vector<char> (0, 0));


Settings::Settings ()
{
}


Settings::~Settings ()
{
}


void Settings::ParseSetting (string setting, string value)
{
	if (setting == "time_bank")
	{
		Settings::TimeBank = stoi (value);
	}
	else if (setting == "time_per_move")
	{
		Settings::TimePerMove = stoi (value);
	}
	else if (setting == "player_names")
	{
		int delimiterPosition = value.find (',');
		Settings::HeroName = value.substr (0, delimiterPosition);
		Settings::VillainName = value.substr (delimiterPosition + 1, string::npos);
	}
	else if (setting == "your_bot")
	{
		if (HeroName != value)
		{
			string temp = Settings::HeroName;
			Settings::HeroName = Settings::VillainName;
			Settings::VillainName = temp;
		}
	}
	else if (setting == "field_height")
	{
		Settings::FieldHeight = stoi (value);
	}
	else if (setting == "field_width")
	{
		Settings::FieldWidth = stoi (value);
	}
}

void Settings::ParseUpdate (string updateable, string setting, string value)
{
	if (updateable == "game")
	{
		if (setting == "round")
		{
			Settings::CurrentRound = stoi (value);
		}
		else if (setting == "this_piece_type")
		{
			Settings::CurrentPiece = Settings::ParsePieceType (value);
		}
		else if (setting == "next_piece_type")
		{
			Settings::NextPiece = Settings::ParsePieceType (value);
		}
		else if (setting == "this_piece_position")
		{
			Settings::PiecePosition = Settings::ParsePiecePosition (value);
		}
	}
	else if (updateable == Settings::HeroName)
	{
		if (setting == "row_points")
		{
			Settings::HeroPoints = stoi (value);
		}
		else if (setting == "combo")
		{
			Settings::HeroCombo = stoi (value);
		}
		else if (setting == "field")
		{
			Settings::HeroField = Settings::ParseField (value);
		}
	}
	else if (updateable == Settings::VillainName)
	{
		if (setting == "row_points")
		{
			Settings::VillainPoints = stoi (value);
		}
		else if (setting == "combo")
		{
			Settings::VillainCombo = stoi (value);
		}
		else if (setting == "field")
		{
			Settings::VillainField = Settings::ParseField (value);
		}
	}
}

void Settings::ParseAction (string setting, string value)
{
	if (setting == "moves")
	{
		Settings::TimeRemaining = stoi (value);
	}
}

PieceType Settings::ParsePieceType (string pieceType)
{
	switch (pieceType[0])
	{
	case 'I':
		return PieceType::I;
	case 'T':
		return PieceType::T;
	case 'J':
		return PieceType::J;
	case 'L':
		return PieceType::L;
	case 'S':
		return PieceType::S;
	case 'Z':
		return PieceType::Z;
	case 'O':
		return PieceType::O;
	default:
		return PieceType::NoPiece; // this just shouldn't happen
	}
}

Position Settings::ParsePiecePosition (string piecePosition)
{
	int delimiterPosition = piecePosition.find (',');
	return Position (stoi (piecePosition.substr (0, delimiterPosition)), stoi (piecePosition.substr (delimiterPosition + 1, string::npos)));
}

Field Settings::ParseField (string fieldString)
{
	// Rows full of columns

	Field field (Settings::FieldHeight, vector<char> (Settings::FieldWidth, 0));

	for (int i = 0; i < Settings::FieldHeight; ++i)
		for (int j = 0; j < Settings::FieldWidth; ++j)
			field[i][j] = fieldString[i * Settings::FieldHeight * 2 + j * 2] - '0';

	return field;
}