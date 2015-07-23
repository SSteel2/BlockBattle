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

	Position (Position& position)
	{
		X = position.X;
		Y = position.Y;
	}

	void operator= (Position position)
	{
		X = position.X;
		Y = position.Y;
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
	int EvaluationPoints;

	// Should be only used for root node
	DeltaPly () :
		Location (0, 0)
	{
		Piece = PieceType::NoPiece;
		CurrentRotation = Rotation::Degrees0;
		EvaluationPoints = 0;
	}

	DeltaPly (Position location, PieceType pieceType, Rotation rotation, int points) :
		Location (location)
	{
		Piece            = pieceType;
		CurrentRotation  = rotation;
		EvaluationPoints = points;
	}
};

typedef vector<vector<char>> Field;

#include "Piece.h"
#include "Settings.h"
#include "Bot.h"
