#include "gdt.h"

namespace GDT {
    GDTEntry entries[5];
    GDTPtr ptr;
    
    void setGate(int num, uint32_t base, uint32_t limit, uint8_t access, uint8_t gran) {
        entries[num].base_low = (base & 0xFFFF);
        entries[num].base_middle = (base >> 16) & 0xFF;
        entries[num].base_high = (base >> 24) & 0xFF;
        
        entries[num].limit_low = (limit & 0xFFFF);
        entries[num].granularity = ((limit >> 16) & 0x0F);
        
        entries[num].granularity |= (gran & 0xF0);
        entries[num].access = access;
    }
    
    void initialize() {
        ptr.limit = (sizeof(GDTEntry) * 5) - 1;
        ptr.base = (uint32_t)&entries;
        
        setGate(0, 0, 0, 0, 0);                // Null segment
        setGate(1, 0, 0xFFFFFFFF, 0x9A, 0xCF); // Code segment
        setGate(2, 0, 0xFFFFFFFF, 0x92, 0xCF); // Data segment
        setGate(3, 0, 0xFFFFFFFF, 0xFA, 0xCF); // User mode code segment
        setGate(4, 0, 0xFFFFFFFF, 0xF2, 0xCF); // User mode data segment
        
        load();
    }
}