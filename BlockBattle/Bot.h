#pragma once

#include "Header.h"

class Piece;

class DecisionTreeNode
{
protected:
	vector<DecisionTreeNode*> mChildren;
	DeltaPly* mMove;

public:
	DecisionTreeNode ();
	~DecisionTreeNode ();
	DecisionTreeNode (DeltaPly* ply);
	DecisionTreeNode (vector<DeltaPly*> children);

	void AddChildren (vector<DeltaPly*> children);
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

protected:
	void InitializePieces ();

	void MakeAction ();
	void PopulateDecisionTree ();
	void EvaluatePositions ();

	Piece* GetPiece (PieceType type);
	DecisionTreeNode GetPossibleMoves (PieceType pieceType, vector<DeltaPly*> queuedMoves);
};

