int add(int a, int b)
{
	int res = a + b;
	if(res >= MOD)
		return res - MOD;
	return res;
}

int mul(int a, int b)
{
	long long res = a;
	res *= b;
	if(res >= MOD)
		return res % MOD;
	return res;
}


struct matrix
{
    int SZ;
    vector<vector<int>> arr;
    matrix(int s){
        SZ = s;
        arr.resize(s, vector<int>(s));
    }
	void reset()
	{
		for(int i = 0; i < SZ; i++){
            for(int j = 0; j < SZ; j++){
                arr[i][j] = 0;
            }
        }
	}

	void makeiden()
	{
		reset();
		for(int i=0;i<SZ;i++)
		{
			arr[i][i] = 1;
		}
	}

	matrix operator + (const matrix &o) const
	{
		matrix res(o.SZ);
		for(int i=0;i<SZ;i++)
		{
			for(int j=0;j<SZ;j++)
			{
				res.arr[i][j] = add(arr[i][j], o.arr[i][j]);
			}
		}
		return res;
	}

	matrix operator * (const matrix &o) const
	{
		matrix res(o.SZ);
		for(int i=0;i<SZ;i++)
		{
			for(int j=0;j<SZ;j++)
			{
				res.arr[i][j] = 0;
				for(int k=0;k<SZ;k++)
				{
					res.arr[i][j] = add(res.arr[i][j] , mul(arr[i][k] , o.arr[k][j]));
				}
			}
		}
		return res;
	}

	void print(){
		for(int i = 0; i < SZ; i++){
			for(int j = 0; j < SZ; j++){
				cout << arr[i][j] << " ";
			}cout << endl;
		}
	}
};

matrix power(matrix a, int b)
{
	matrix res = a;
    b--;
	while(b)
	{
		if(b & 1)
		{
			res = res * a;
		}
		a = a * a;
		b >>= 1;
	}
	return res;
}

vector<int> multiply_vector(matrix &a, vector<int> &b){
    int SZ = a.SZ;
    vector<int> ans(a.SZ);
    for(int i = 0; i < SZ; i++){
        int curr = 0;
        for(int j = 0; j < SZ; j++){
            curr = (curr + (b[j] * a.arr[i][j]) % MOD) % MOD;
        }
        ans[i] = curr;
    }
    return ans;
}

vector<int> multiply_vector(vector<int> &b, matrix &a){
    int SZ = a.SZ;
    vector<int> ans(a.SZ);
    for(int i = 0; i < SZ; i++){
        int curr = 0;
        for(int j = 0; j < SZ; j++){
            curr = add(curr, mul(a.arr[j][i], b[j]));
        }
        ans[i] = curr;
    }
    return ans;
}
