#include <vector>
#include <stdio.h>
#include "board_utils.hpp"
#include "look_up_moves.hpp"

uint64_t knight[64];
uint64_t king[64];
uint64_t rook[64];
uint64_t bishop[64];

bool check_valid_knight_move(int sq, int move) {
    uint64_t m = 1ULL << sq;
    if(((col_a | col_b) & m) && (move == -17 || move == 6)) return false;
    if((col_a & m) && (move == 15 || move == -10)) return false;
    if(((col_g | col_h) & m) && (move == 10 || move == -6)) return false;
    if((col_h & m) && (move == -15 || move == 17)) return false;
    return true;
} 

void knights_table_init() {
    std::vector<int> knight_moves = {6,10,15,17,-6,-10,-15,-17};
    for(int i = 0; i < 64; i++) {
        uint64_t attacks = 0;
        for(int move : knight_moves) {
            int attack_sq = i + move;
            if(attack_sq >= 0 && attack_sq < 64 && check_valid_knight_move(i, move)) 
                attacks |= 1ULL << attack_sq;
        }
        knight[i] = attacks;
    }
}

bool check_valid_king_move(int sq, int move) {
    uint64_t m = 1ULL << sq;
    if((col_a & m) && (move == -1 || move == 7 || move == -9)) return false;
    if((col_h & m) && (move == 1 || move == -7 || move == 9)) return false;
    return true;
}

void king_table_init() {
    std::vector<int> king_moves = {-1,1,-8,8,-9,9,-7,7};
    for(int i = 0; i < 64; i++) {
        uint64_t attacks = 0;
        for(int move : king_moves) {
            int attack_sq = i + move;
            if(attack_sq >= 0 && attack_sq < 64 && check_valid_king_move(i, move))
                attacks |= 1ULL << attack_sq;
        }
        king[i] = attacks;
    }
}

void rook_table_init() {
    for(int sq = 0; sq < 64; sq++) {
        uint64_t attacks = 0;
        for(int row = 0; row < 8; row++) 
            attacks |= 1ULL << ((sq%8) + (row * 8));
        for(int col = 0; col < 8; col++)
            attacks |= 1ULL << (((sq/8) * 8) + col);
        attacks &= ~(1ULL << sq);
        rook[sq] = attacks;
    }
}

void bishop_table_init() {
    for(int sq = 0; sq < 64; sq++) {
        uint64_t attacks = 0;
        for(int row=(sq/8)+1, col=(sq%8)+1; row < 8 && col < 8; row++, col++)
            attacks |= 1ULL << ((row * 8) + col);
        for(int row=(sq/8)-1, col=(sq%8)+1; row > -1 && col < 8; row--, col++)
            attacks |= 1ULL << ((row * 8) + col);
        for(int row=(sq/8)+1, col=(sq%8)-1; row < 8 && col > -1; row++, col--)
            attacks |= 1ULL << ((row * 8) + col);             
        for(int row=(sq/8)-1, col=(sq%8)-1; row > -1 && col > -1; row--, col--)
            attacks |= 1ULL << ((row * 8) + col);
        bishop[sq] = attacks;
    }
}

void look_up_moves_init() {
    knights_table_init();
    rook_table_init();
    king_table_init();
    bishop_table_init();
}



