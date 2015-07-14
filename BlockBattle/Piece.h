#pragma once

#include <vector>

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

class Piece
{
protected:
	PieceType mPieceType;
	int mRotationCount;

public:
	vector<vector<char>> mField;

	Piece (PieceType type, int rotationCount, vector<vector<char>>&& field);
	~Piece ();

	PieceType GetPieceType ();
	int GetRotationCount ();
};

