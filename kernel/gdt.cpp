#include "gdt.h"
#include "asm.h"

namespace Kernel
{


Gdt::Gdt()
{
    Entry[1].SetValue(((u64)1<<43) | ((u64)1<<44) | ((u64)1<<47) | ((u64)1<<53));
}

void Gdt::Save()
{
    TableDesc desc = {
        .Base = reinterpret_cast<u64>(&Entry[0]),
        .Limit = sizeof(Entry),
    };

    LoadGdt(&desc);

    Base = desc.Base;
    Limit = desc.Limit;
}

Gdt::~Gdt()
{
}

}