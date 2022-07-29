pragma circom 2.0.0;


function caculate_k(ab, carry) {
    var tmp = ab + carry;
    if(tmp < 2) {
        return tmp;
    } else {
        return tmp - 2; 
    }
}

function caculate_carry(ab, carry) {
    var tmp = ab + carry;
    if(tmp < 2) {
        return 0;
    } else {
        return 1;
    }
}

template StringSum() {
    signal input a[256];
    signal input b[256];
    signal output out[256];

    var k = 0;
    var carry = 0;
    for(k=0; k<256; k++) {
        var ab = a[k] + b[k];
        out[k] <-- caculate_k(ab, carry);
        carry = caculate_carry(ab, carry);
    }
}

 component main = StringSum();