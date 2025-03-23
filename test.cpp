#include <iostream>
#include <windows.h>

int main()
{
    PROCESS_HEAP_ENTRY entry;
    entry.lpData = nullptr;
    HANDLE heap = GetProcessHeap();
    SIZE_T totalAllocated = 0;

    while (HeapWalk(heap, &entry))
    {
        if (entry.wFlags & PROCESS_HEAP_ENTRY_BUSY)
        {
            totalAllocated += entry.cbData;
        }
    }

    std::cout << "Total allocated heap memory: " << totalAllocated << " bytes\n";

    return 0;
}
