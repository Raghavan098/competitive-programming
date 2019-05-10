ld ternary_search(ld l, ld r) {
    ld eps = 1e-9;
    while (r - l > eps) {
        ld m1 = l + (r - l) / 3;
        ld m2 = r - (r - l) / 3;
        ld f1 = f(m1);
        ld f2 = f(m2);
        // tr(f1,f2);
        if (f1 > f2)
            l = m1;
        else
            r = m2;
    }
    return f(l);
}
