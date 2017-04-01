#pragma once

#include "types.h"
#include "idt.h"

namespace Kernel
{

namespace Core
{

class IO8042
{
public:
    static IO8042& GetInstance()
    {
        static IO8042 instance;
        return instance;
    }

    void RegisterInterrupt(int intNum);
    void UnregisterInterrupt();

    u8 Get();

    static void Interrupt();

private:
    IO8042();
    virtual ~IO8042();

    IO8042(const IO8042& other) = delete;
    IO8042(IO8042&& other) = delete;
    IO8042& operator=(const IO8042& other) = delete;
    IO8042& operator=(IO8042&& other) = delete;

    static const ulong Port = 0x60;

    const ulong BufSize = 16;
    volatile u8 *Buf;
    volatile u8 *BufPtr;
    int IntNum;
};

}
}
