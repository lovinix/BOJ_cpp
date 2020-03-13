#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using cpx = complex<double>;

string S[2];
vector<int> X, Y, Z;

void fft(vector <cpx>& a, bool invert)
{
    int n = a.size();
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j >= bit; bit >>= 1) j -= bit;
        j += bit;
        if (i < j) swap(a[i], a[j]);
    }
    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * acos(-1) / len * (invert ? -1 : 1);
        cpx wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cpx w(1);
            for (int j = 0; j < len / 2; j++) {
                cpx u = a[i + j], v = a[i + j + len / 2] * w;
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                w *= wlen;
            }
        }
    }
    if (invert) {
        for (int i = 0; i < n; i++) a[i] /= n;
    }
}

void multiply(const vector<int>& a, const vector<int>& b, vector<int>& res)
{
    vector <cpx> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < max(a.size(), b.size())) n <<= 1;
    fa.resize(n); fb.resize(n);
    fft(fa, false); fft(fb, false);
    for (int i = 0; i < n; i++) fa[i] *= fb[i];
    fft(fa, true);
    res.resize(n);
    for (int i = 0; i < n; i++) res[i] = int(fa[i].real() + (fa[i].real() > 0 ? 0.5 : -0.5));
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    cin >> S[0] >> S[1];
    for (auto& s : S)
    {
        reverse(s.begin(), s.end());
        for (auto& c : s)
        {
            (&s == S ? X : Y).emplace_back(c - '0');
        }
    }
    if (X.size() > Y.size()) X.resize(X.size() * 2);
    else Y.resize(Y.size() * 2);
    multiply(X, Y, Z);
    for (int i = 0; i < Z.size(); ++i)
    {
        int q = Z[i] / 10;
        Z[i] %= 10;
        if (q) Z[i + 1] += q;
    }
    while (Z.size() && Z.back() == 0) Z.pop_back();
    if (Z.size() == 0) cout << 0;
    else
    {
        for (auto it = Z.rbegin(); it != Z.rend(); it++)
            cout << *it;
    }
}