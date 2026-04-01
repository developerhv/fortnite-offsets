namespace decryption {
    static inline uintptr_t get_world() // creds -> capware.fun
    {
        auto base = Memory->process_base();
        if (!base)
            return 0;
 
        uint64_t v = Memory->read<uint64_t>(base + g_world_rva);
        if (!v)
            return 0;
 
        // ASM: ~__ROL8__(qword_1895DE60 ^ 0xCF76574CLL, 48);
        v ^= 0xCF76574CULL;
        v = _rotl64(v, 48);
        v = ~v;
 
        return static_cast<uintptr_t>(v);
    }
}

namespace offsets
{

    inline constexpr uintptr_t g_world = 0x1895DE60;
    inline constexpr uintptr_t OwningGameInstance = 0x250;
    inline constexpr uintptr_t GameState = 0x1D8;
    inline constexpr uintptr_t PersistentLevel = 0x40;
    inline constexpr uintptr_t Levels = 0x1F0;
    inline constexpr uintptr_t LocalPlayers = 0x38;
    inline constexpr uintptr_t AcknowledgedPawn = 0x358;
    inline constexpr uintptr_t PlayerCameraManager = 0x368;
    inline constexpr uintptr_t PlayerState = 0x2D0;
    inline constexpr uintptr_t RootComponent = 0x1B0;
    inline constexpr uintptr_t Mesh = 0x330;
    inline constexpr uintptr_t RelativeLocation = 0x140;
    inline constexpr uintptr_t RelativeRotation = 0x158;
}
