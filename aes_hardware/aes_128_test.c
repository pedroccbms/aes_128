/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   aes_128_test.c
 * Author: pedro
 *
 * Created on 28 de Agosto de 2016, 18:33
 */
/*Autor: Anderson Tibana*/ 
/*Autor: Pedro */
#include <stdio.h>
#include <wmmintrin.h>
#include <smmintrin.h>
#include <time.h>
void print_m128i_with_string(char* string,__m128i data)
{
    unsigned char *pointer = (unsigned char*)&data;
    int i;
    printf("%-40s[0x",string);
    for (i=0; i<16; i++)
        printf("%02x",pointer[i]);
    printf("]\n");
}
/****************************************************************************/
int main ()
{
    clock_t inicio, fim;
    inicio= clock();
    __m128i ZERO = _mm_setzero_si128();
    __m128i ISOLATE_SROWS_MASK =
    _mm_set_epi32(0x0B06010C, 0x07020D08, 0x030E0904, 0x0F0A0500);
    __m128i ISOLATE_SBOX_MASK =
    _mm_set_epi32(0x0306090C, 0x0F020508, 0x0B0E0104, 0x070A0D00);
    __m128i Round_Key_0 =
    _mm_set_epi32(0x0f0e0d0c, 0x0b0a0908, 0x07060504, 0x03020100);
    __m128i Round_Key_1 =
    _mm_set_epi32(0xfe76abd6, 0xf178a6da, 0xfa72afd2, 0xfd74aad6);
    __m128i DATA =
    _mm_set_epi32(0xffeeddcc, 0xbbaa9988, 0x77665544, 0x33221100);
    __m128i temp1,temp2;
    printf ("Demonstrating the exposed transformations: \n");
    print_m128i_with_string("DATA:", DATA);
    print_m128i_with_string("Round Key 0:", Round_Key_0);
    temp1 = _mm_xor_si128(DATA, Round_Key_0);
    /* Round 0*/
    print_m128i_with_string("After Round 0:", temp1);
    print_m128i_with_string("Round Key 1:", Round_Key_1);
    /* A "decomposed" encryption round, built from the individual transformations*/
    temp2 = _mm_shuffle_epi8(temp1, ISOLATE_SROWS_MASK);/* isolate ShiftRows */
    print_m128i_with_string("After ShiftRows:", temp2);
    temp2 = _mm_shuffle_epi8(temp2, ISOLATE_SBOX_MASK);
    temp2 = _mm_aesenclast_si128(temp2, ZERO);
    /* isolate SubBytes */
    print_m128i_with_string("After SubBytes:", temp2);
    temp2 = _mm_aesdeclast_si128(temp2, ZERO);
    temp2 = _mm_aesenc_si128(temp2, ZERO);
    /* isolate MixColumns */
    print_m128i_with_string("After MixColumns:", temp2);
    temp2 = _mm_xor_si128(temp2, Round_Key_1);
    /* isolate AddRoundKey */
    print_m128i_with_string("After AddRoundKey:", temp2);
    temp1 = _mm_aesenc_si128(temp1, Round_Key_1);/* round 1 using instruction*/
    printf("\n");
    print_m128i_with_string("AES Round using exposed transformations:", temp2);
    print_m128i_with_string("AES round using AESENC instruction:", temp1);
    printf("\n");
    printf ("Going backwards using exposed inverse transformations: \n");
    temp2 = _mm_xor_si128(temp2, Round_Key_1);
    /* Going Bakwards */
    print_m128i_with_string("After InvAddRoundKey:", temp2);
    temp2 = _mm_aesenclast_si128(temp2, ZERO);
    temp2 = _mm_aesdec_si128(temp2, ZERO);
    print_m128i_with_string("After InvMixColumns:", temp2);
    temp2 = _mm_shuffle_epi8(temp2, ISOLATE_SROWS_MASK);
    temp2 = _mm_aesdeclast_si128(temp2, ZERO);
    print_m128i_with_string("After InvSubBytes:", temp2);
    temp2 = _mm_shuffle_epi8(temp2, ISOLATE_SBOX_MASK);
    print_m128i_with_string("After InvShiftRows:", temp2);
    temp2 = _mm_xor_si128(temp2, Round_Key_0);
    print_m128i_with_string("Final:", temp2);
    printf ("Returned to initial state. \n");
    fim= clock();
    printf("%lf\n", (double)inicio/CLOCKS_PER_SEC);
    printf("%lf\n", (double)fim/CLOCKS_PER_SEC);
    printf("%lf\n",((double)(fim - inicio)/CLOCKS_PER_SEC));
}


