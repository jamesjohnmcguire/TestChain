#include "Blockchain.h"

Blockchain::Blockchain()
{
	Block genesis = Block(0, "Genesis Block");

	chain.emplace_back(genesis);
	difficulty = 6;
}

void Blockchain::AddBlock(Block newBlock)
{
	Block previous = GetLastBlock();
	string prevoiusHash = previous.Hash;
	newBlock.PrevHash = prevoiusHash;

	newBlock.MineBlock(difficulty);
	chain.push_back(newBlock);
}

Block Blockchain::GetLastBlock() const
{
	return chain.back();
}
