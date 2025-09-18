#include <cstddef>
#include <cassert>
#include <iostream>
#include <cstring>

using namespace std;

static void mmul(float const * A,
                 float const * B,
                 float * C,
                 size_t N) {
    // for each row
    for (size_t row=0; row<N; row++)
        // for each col
        for ( size_t col=0; col<N; col++)
            // accumulate
            for ( size_t idx=0; idx<N; idx++)
                    C[row*N + col] += A[row*N+idx] * B[col+N*idx];
}

int main(int argc, char** argv ) {
    int N = 2;
    float * A = new float[N * N];
    float * B = new float[N * N];
    float * C = new float[N * N];

    A[0] = 3;
    A[1] = 2;
    A[2] = 5;
    A[3] = 6;

    B[0] = 1;
    B[1] = 2;
    B[2] = 3;
    B[3] = 4;

    memset(C, 0, N*N);

    mmul(A, B, C, N);

    assert(C[0]==9);
    assert(C[1]==14);
    assert(C[2]==23);
    assert(C[3]==34);
}
