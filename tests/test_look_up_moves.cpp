#include "../look_up_moves.cpp"
#include <gtest/gtest.h>


TEST(LOOKUP_TABLES, Knights) {
    look_up_moves_init();
    uint64_t a1 = 0x20400ULL;
    uint64_t b2 = 0x5080008ULL;
    uint64_t c3 = 0xa1100110aULL;
    uint64_t g2 = 0xa0100010ULL;
    uint64_t h3 = 0x4020002040ULL;
    uint64_t h8 = 0x20400000000000;
    ASSERT_EQ(knight[0],a1);
    ASSERT_EQ(knight[9], b2);
    ASSERT_EQ(knight[18], c3);
    ASSERT_EQ(knight[14], g2);
    ASSERT_EQ(knight[23], h3);
    ASSERT_EQ(knight[63], h8);
}

TEST(LOOKUP_TABLES, King) {
    look_up_moves_init();
    uint64_t a1 = 0x302ULL;
    uint64_t b2 = 0x70507ULL;
    uint64_t g2 = 0xe0a0e0ULL;
    uint64_t h1 = 0xc040ULL;
    uint64_t h8 = 0x40c0000000000000;
    uint64_t a8 = 0x203000000000000;
    ASSERT_EQ(king[0], a1);
    ASSERT_EQ(king[9], b2);
    ASSERT_EQ(king[14], g2);
    ASSERT_EQ(king[63], h8);
    ASSERT_EQ(king[56], a8);
}

TEST(LOOKUP_TABLES, Rook) {
    look_up_moves_init();
    uint64_t a1 = 0x1010101010101feULL;
    uint64_t b2 = 0x20202020202fd02ULL;
    uint64_t g2 = 0x404040404040bf40ULL;
    uint64_t h8 = 0x7f80808080808080ULL;
    uint64_t a8 = 0xfe01010101010101ULL;
    ASSERT_EQ(rook[0], a1);
    ASSERT_EQ(rook[9], b2);
    ASSERT_EQ(rook[14], g2);
    ASSERT_EQ(rook[63], h8);
    ASSERT_EQ(rook[56], a8);
}

TEST(LOOKUP_TABLES, Bishop) {
    look_up_moves_init();
    uint64_t a1 = 0x8040201008040200ULL;
    uint64_t b2 = 0x8040201008050005ULL;
    uint64_t g2 = 0x102040810a000a0ULL;
    uint64_t h8 = 0x40201008040201ULL;
    uint64_t a8 = 0x2040810204080ULL;
    ASSERT_EQ(bishop[0], a1);
    ASSERT_EQ(bishop[9], b2);
    ASSERT_EQ(bishop[14], g2);
    ASSERT_EQ(bishop[63], h8);
    ASSERT_EQ(bishop[56], a8);
}


