#pragma once

#include "Header.h"

struct DeltaPly;

class DecisionTreeNode
{
protected:
	vector<DeltaPly*> mChildren;
};

class Bot
{
protected:
	vector<Piece*> mPieces;
	DecisionTreeNode mDecisionRoot;

public:
	Bot ();
	~Bot ();

	void Run ();
	void MakeAction ();

	Piece* GetPiece (PieceType type);
	void PopulateDecisionTree ();

private:
	void InitializePieces ();
	vector<DeltaPly*> GetPossibleMoves (PieceType pieceType, vector<DeltaPly*> queuedMoves);

};

