inline void antidebug() {
#ifdef __arm64__
    int status = 1; 
    __asm__("mov X0, #26\n"
            "mov X1, #31\n"
            "mov X2, #0\n"
            "mov X3, #0\n"
            "mov X4, #0\n"
            "mov w16, #0\n"
            "svc #0x80\n"
            "mov %0, X0\n"
            : "=r"(status));
    // NSLog(@"status: %d", status);
    if (status != 0) { 
        exit(0); // if syscall failed exit the process
    }
#endif
}

