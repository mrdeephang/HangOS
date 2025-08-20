extern "C" void kernel_main() {
    // Initialize screen
    Screen::clear();
    Screen::print("MyOS Kernel Loaded Successfully!\n");
    
    // Initialize GDT
    GDT::initialize();
    
    // Initialize IDT
    IDT::initialize();
    
    // Main kernel loop
    while(1) {
        // Kernel operations go here
    }
}