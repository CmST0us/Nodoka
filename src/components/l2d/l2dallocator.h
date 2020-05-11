#ifndef L2DALLOCATOR_H
#define L2DALLOCATOR_H

#include <CubismFramework.hpp>
#include <ICubismAllocator.hpp>

namespace Nodoka {

class L2DAllocator : public Csm::ICubismAllocator
{
    /**
    * @brief  メモリ領域を割り当てる。
    *
    * @param[in]   size    割り当てたいサイズ。
    * @return  指定したメモリ領域
    */
    void* Allocate(const Csm::csmSizeType size);

    /**
    * @brief   メモリ領域を解放する
    *
    * @param[in]   memory    解放するメモリ。
    */
    void Deallocate(void* memory);

    /**
    * @brief
    *
    * @param[in]   size         割り当てたいサイズ。
    * @param[in]   alignment    割り当てたいサイズ。
    * @return  alignedAddress
    */
    void* AllocateAligned(const Csm::csmSizeType size, const Csm::csmUint32 alignment);

    /**
    * @brief
    *
    * @param[in]   alignedMemory    解放するメモリ。
    */
    void DeallocateAligned(void* alignedMemory);
};

}


#endif // L2DALLOCATOR_H
