#ifndef BLOCK_H
#define BLOCK_H

#include "Entity.h"

namespace StanleyCraft
{
    class Block : public Entity
    {
        public:
            Block();
        private:
            unsigned int m_shader;
            unsigned int m_vao;
            unsigned int m_vbo;
                  
    }
}

#endif