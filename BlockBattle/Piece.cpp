#include "Piece.h"


Piece::Piece (PieceType type, int rotationCount, vector<vector<char>>&& field)
{
	mPieceType = type;
	mRotationCount = rotationCount;
	mField = field;
	CalculateDimensions ();
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


void Piece::CalculateDimensions ()
{
	for (unsigned int i = 0; i < mField.size (); i++)
	{
		for (unsigned int j = 0; j < mField[i].size (); j++)
		{
			if (mField[i][j] == 1)
			{
				mHeight++;
				break;
			}
		}
	}

	for (unsigned int i = 0; i < mField[0].size (); i++)
	{
		for (unsigned int j = 0; j < mField.size (); j++)
		{
			if (mField[j][i] == 1)
			{
				mWidth++;
				break;
			}
		}
	}
}