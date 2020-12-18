#include <cstdint>
#include <vector>
#include "Block.h"

using namespace std;

class Blockchain
{
public:
	Blockchain();

	void AddBlock(Block bNew);

private:
	uint32_t difficulty;
	vector<Block> chain;

	Block GetLastBlock() const;
};
