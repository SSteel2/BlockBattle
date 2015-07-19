#include "Piece.h"


Piece::Piece (PieceType type, int rotationCount, Field&& field)
{
	mPieceType = type;
	mRotationCount = rotationCount;
	mField.push_back (field);
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


int Piece::GetHeight ()
{
	return mHeight;
}


int Piece::GetWidth ()
{
	return mWidth;
}


Field Piece::GetRotationField (Rotation rotation)
{
	return mField[rotation % mRotationCount];
}


void Piece::CalculateDimensions ()
{
	for (unsigned int i = 0; i < mField[0].size (); i++)
	{
		for (unsigned int j = 0; j < mField[0][i].size (); j++)
		{
			if (mField[0][i][j] == 1)
			{
				mHeight++;
				break;
			}
		}
	}

	for (unsigned int i = 0; i < mField[0][0].size (); i++)
	{
		for (unsigned int j = 0; j < mField[0].size (); j++)
		{
			if (mField[0][j][i] == 1)
			{
				mWidth++;
				break;
			}
		}
	}
}


void Piece::PopulateRotations ()
{
	for (int rotation = 1; rotation < mRotationCount; rotation++)
	{
		mField.push_back (Field (mField[0].size (), vector<char> (mField[0][0].size ())));
		
		unsigned int rows = mField[0].size ();
		unsigned int columns = mField[0][0].size ();
		
		for (unsigned int i = 0; i < rows; i++)
			for (unsigned int j = 0; j < columns; j++)
				mField[rotation][i][j] = mField[rotation - 1][j][rows - 1 - i];
	}
}


bool Piece::CheckOverlay (DeltaPly* ply, Field gameField)
{
	Field pieceField = GetRotationField (ply->CurrentRotation);
	for (int i = 0; i < pieceField.size (); i++)
	{
		for (int j = 0; j < pieceField.size (); j++)
		{

		}
	}
}