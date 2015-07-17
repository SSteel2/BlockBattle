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

enum Rotation
{
	Degrees0 = 0,
	Degrees90,
	Degrees180,
	Degrees270
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

