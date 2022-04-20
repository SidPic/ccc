#include <stdio.h>

#define getbit( byte, bitnum ) ( ((byte)>>(bitnum)) & 1u )
#define onbit(  byte, bitnum ) ( (byte) |= 1u << (bitnum) )
#define offbit( byte, bitnum ) ( (byte) &= ~( 1u << (bitnum) ) )
#define setbit( byte, bitnum, val )                                                                \
({                                                                                                 \
    if ( val ) onbit( byte, bitnum ); else offbit( byte, bitnum );                                 \
})

void printbits( unsigned char c ) {
    for ( int i = 7; i > -1; putchar('0'+getbit(c,i--)) );
    putchar('\n');
}

void cc ( unsigned char c[8] ) {
    for ( int i = 0; i <= 6; i++ )
    {
        for ( int j = 0; j <= i; j++ ) {
            c[i] <<= 1;
            setbit( c[i], 0, getbit( c[i+1], 6-j ) );
        }
    }
    c[7] = 0;
}

void uncc( unsigned char c[8] ) {

    for ( int i = 7; i > 0; i--  )
    {
        for ( int j = 7-i; j < 7; j++ ) {
            setbit( c[i], j, getbit(c[i-1], 0) );
            c[i-1] >>= 1;
        }
    }
}

int main() {

    unsigned char c[8] = {[0 ... 7] = 0b01010101};

    for ( int i = 0; i < 8; printbits(c[i++]) );

    puts("");
    cc(c);
    for ( int i = 0; i < 8; printbits(c[i++]) );

    puts("");
    uncc(c);
    for ( int i = 0; i < 8; printbits(c[i++]) );

    return 0;
}
