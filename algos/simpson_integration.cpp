const int N = 3e6; // number of steps (already multiplied by 2)

lld simpson_integration(lld a, lld b){
    lld h = (b - a) / N;
    lld s = f(a) + f(b); // a = x_0 and b = x_2n
    for (int i = 1; i <= N - 1; ++i) { // Refer to final Simpson's formula
        lld x = a + h * i;
        s += f(x) * ((i & 1) ? 4 : 2);
    }
    s *= h / 3;
    return s;
}
