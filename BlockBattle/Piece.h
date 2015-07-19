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

	vector<vector<vector<char>>> mField;

public:
	Piece (PieceType type, int rotationCount, vector<vector<char>>&& field);
	~Piece ();

	PieceType GetPieceType ();
	int GetRotationCount ();
	int GetWidth ();
	int GetHeight ();
	vector<vector<char>> GetRotation (Rotation rotation);

private:
	void CalculateDimensions ();
	void PopulateRotations ();
};

