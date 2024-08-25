




int copyBitsInRange(int a, int b, int i, int j){
    i--;
    j--;
    int x = (-1 << (j+1)); // i.e of type 111110000000
    int y = (1 << i ) - 1; // i.e of type 000000001111
    int mask = ~ (x|y); // i.e of type 0000001111100000 

    mask &= a; // i.e given range mei jo jo bit, a mei set hai unhe mask mei set hi rhne do baakiyo ko 0 krdo, in that range

    return b | mask;
}