#ifndef CHUNK_H
#define CHUNK_H

#include "block.h"

class Chunk {
public:
	Chunk();
private:
	Block m_chunk_data[16][16][16];
};


#endif
