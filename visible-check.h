
// visible check ( credits to offsets.host )

bool is_visible( uintptr_t mesh )
{
        // WasRecentlyRendered
        auto world = yourdriver->read<uintptr_t>( mesh + 0xB0 );
        auto delta_time_seconds = yourdriver->read<float>( world + 0x88c );
        auto time_seconds = yourdriver->read<double>( world + 0x868 );

        auto last_render_time = yourdriver->read<float>( mesh + 0x330 );
        auto time_since = time_seconds - last_render_time;

        auto render_time_threshold = fmaxf( 0.06f , delta_time_seconds + 0.000099999997f );
        return time_since <= render_time_threshold;
}
