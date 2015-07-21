#pragma once

#include "Header.h"

class Piece;

class DecisionTreeNode
{
protected:
	vector<DeltaPly*> mChildren;

public:
	DecisionTreeNode ();
	DecisionTreeNode (vector<DeltaPly*> children);
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
	DecisionTreeNode GetPossibleMoves (PieceType pieceType, vector<DeltaPly*> queuedMoves);

};

