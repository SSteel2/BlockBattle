#pragma once

#include <vector>
#include <algorithm>

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
	int mWidth = 0;
	int mHeight = 0;

public:
	vector<vector<char>> mField;

	Piece (PieceType type, int rotationCount, vector<vector<char>>&& field);
	~Piece ();

	PieceType GetPieceType ();
	int GetRotationCount ();
	int GetWidth ();
	int GetHeight ();

private:
	void CalculateDimensions ();
};

