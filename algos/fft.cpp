
typedef complex<double> base;

int res[2 * N];

double PI = 3.14159265358979323846f;

int rev (int num, int lg_n) {
	int res = 0;
	for (int i=0; i<lg_n; ++i)
		if (num & (1<<i))
			res |= 1<<(lg_n-1-i);
	return res;
}

void fft (vector<base> & a, bool invert) {
	int n = (int) a.size();
	int lg_n = 0;
	while ((1 << lg_n) < n)  ++lg_n;

	for (int i=0; i<n; ++i)
		if (i < rev(i,lg_n))
			swap (a[i], a[rev(i,lg_n)]);

	for (int len=2; len<=n; len<<=1) {
		double ang = 2*PI/len * (invert ? -1 : 1);
		base wlen (cos(ang), sin(ang));
		for (int i=0; i<n; i+=len) {
			base w (1);
			for (int j=0; j<len/2; ++j) {
				base u = a[i+j],  v = a[i+j+len/2] * w;
				a[i+j] = u + v;
				a[i+j+len/2] = u - v;
				w *= wlen;
			}
		}
	}
	if (invert)
		for (int i=0; i<n; ++i)
			a[i] /= n;
}

int multiply (vector<int> & a, vector<int> & b) {
	vector<base> fa (a.begin(), a.end()),  fb (b.begin(), b.end());
	size_t n = 1;
	while (n < max (a.size(), b.size()))  n <<= 1;
	n <<= 1;
	fa.resize (n),  fb.resize (n);

	fft (fa, false),  fft (fb, false);
	for (size_t i=0; i<n; ++i)
		fa[i] *= fb[i];
	fft (fa, true);
	for (size_t i=0; i<n; ++i)
		res[i] += int (fa[i].real() + 0.5);
	return n;
}
