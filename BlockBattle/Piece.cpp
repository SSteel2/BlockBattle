#include "Piece.h"


Piece::Piece (PieceType type, int rotationCount, vector<vector<char>>&& field)
{
	mPieceType = type;
	mRotationCount = rotationCount;
	mField = field;
}


Piece::~Piece ()
{
}


PieceType Piece::GetPieceType ()
{
	return mPieceType;
}


int Piece::GetRotationCount ()
{
	return mRotationCount;
}