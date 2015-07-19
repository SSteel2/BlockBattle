#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <sstream>

using namespace std;

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

enum Rotation
{
	Degrees0 = 0,
	Degrees90,
	Degrees180,
	Degrees270
};

struct Position
{
	int X;
	int Y;

	Position (int x, int y)
	{
		SetPosition (x, y);
	}

	void SetPosition (int x, int y)
	{
		X = x;
		Y = y;
	}
};

struct DeltaPly
{
	Position Location;
	PieceType Piece;
	Rotation CurrentRotation;
	int evaluationPoints;
};

typedef vector<vector<char>> Field;

#include "Piece.h"
#include "Settings.h"
#include "Bot.h"
