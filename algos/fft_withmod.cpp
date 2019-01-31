
const int Maxk = 10;
const int mod = 998244353;
int groot, groot_1, groot_pw = 1 << 23;

int d[Maxk];
int res;

int toPower(int a, int p)
{
    int res = 1;
    while (p) {
        if (p & 1) res = ll(res) * a % mod;
        p >>= 1; a = ll(a) * a % mod;
    }
    return res;
}

int Inv(int x) { return toPower(x, mod - 2); }

int getRoot()
{
    int prims[] = {2, 7, 17};
    for (int i = 2; ; i++) {
        bool ok = true;
        for (int j = 0; j < 3 && ok; j++)
            ok = toPower(i, (mod - 1) / prims[j]) != 1;
        if (ok) return i;
    }
}

void fft (vector<int> & a, bool invert) {
	int n = (int) a.size();

	for (int i=1, j=0; i<n; ++i) {
		int bit = n >> 1;
		for (; j>=bit; bit>>=1)
			j -= bit;
		j += bit;
		if (i < j)
			swap (a[i], a[j]);
	}
    int root = groot;
    int root_1 = groot_1;
    int root_pw = groot_pw;
    while (root_pw > n) {
        root_pw >>= 1;
        root = ll(root) * root % mod;
        root_1 = ll(root_1) * root_1 % mod;
    }
	for (int len=2; len<=n; len<<=1) {
		int wlen = invert ? root_1 : root;
		for (int i=len; i<root_pw; i<<=1)
			wlen = int (wlen * 1ll * wlen % mod);
		for (int i=0; i<n; i+=len) {
			int w = 1;
			for (int j=0; j<len/2; ++j) {
				int u = a[i+j],  v = int (a[i+j+len/2] * 1ll * w % mod);
				a[i+j] = u+v < mod ? u+v : u+v-mod;
				a[i+j+len/2] = u-v >= 0 ? u-v : u-v+mod;
				w = int (w * 1ll * wlen % mod);
			}
		}
	}
	if (invert) {
		int nrev = Inv(n);
		for (int i=0; i<n; ++i)
			a[i] = int (a[i] * 1ll * nrev % mod);
	}
}

void Multiply(vector <int> &A, vector <int> B)
{
    int p = 0;
    while ((1 << p) < max(A.size(), B.size())) p++;
    p++;
    A.resize(1 << p, 0); B.resize(1 << p, 0);
    fft(A, false); fft(B, false);
    for (int i = 0; i < A.size(); i++)
        A[i] = ll(A[i]) * B[i] % mod;
    fft(A, true);
}


int32_t main(){ _

    groot = getRoot();
    groot = toPower(groot, 7 * 17);
    groot_1 = Inv(groot);

}
