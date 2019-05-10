struct line{
    int my, mx, cy, cx;
    line(int x1, int y1, int x2, int y2){
        int a = (y2 - y1);
        int b = (x2 - x1);
        int c = __gcd(a, b);
        if(b != 0){
            a /= c;
            b /= c;
            my = abs(a);
            mx = abs(b);
            a = y2 * (x2 - x1) - x2 * (y2 - y1);
            b = (x2 - x1);
            c = __gcd(a, b);
            a /= c;
            b /= c;
            cy = abs(a);
            cx = abs(b);
            my = my * get_sign(y2 - y1, x2 - x1);
            cy = cy * get_sign(y2 * (x2 - x1) - x2 * (y2 - y1), (x2 - x1));
        }
        else{
            mx = 0;
            my = 1;
            cy = 0;
            cx = x1;
        }
    }
    int get_sign(int a, int b){
        if((a < 0 && b > 0) || (a > 0 && b < 0)){
            return -1;
        }
        return 1;
    }
    bool operator==(const line& l2) const{
        return(l2.my == my && l2.mx == mx && l2.cx == cx && l2.cy == cy);
    }
    bool operator<(const line& l2) const{
        pair<int, int> s1;
        s1.first = my;
        s1.second = mx;
        pair<int, int> s2;
        s2.first = l2.my;
        s2.second = l2.mx;
        pair<int, int> s11;
        s11.first = cy;
        s11.second = cx;
        pair<int, int> s22;
        s22.first = l2.cy;
        s22.second = l2.cx;
        pair<pair<int, int>, pair<int, int> > c1, c2;
        c1 = make_pair(s1, s11);
        c2 = make_pair(s2, s22);
        return c1 < c2;
    }
};
