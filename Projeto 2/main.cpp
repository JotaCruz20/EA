#include <iostream>
#include <vector>
#include <chrono>

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::duration;
using std::chrono::milliseconds;

using namespace std;

int mod_abs(int a, int mod) {
    return ((a % mod) + mod) % mod;
}

int mod_add(int a, int b, int mod) {
    return (mod_abs(a, mod) + mod_abs(b, mod)) % mod;
}

int mod_sub(int a, int b, int mod) {
    return mod_add(a, -b, mod);
}

int lego(int width, int blockSize, int height) {
    vector<vector<int>> possibleMoves(height - blockSize + 1, vector<int>(2));
    vector<int> somaUp(height - blockSize + 1);
    vector<int> somaDown(height - blockSize + 1);

    int nPosAvailable = 0;
    int temp1, temp, sUp, sDown;
    possibleMoves[0][0] = 1;
    possibleMoves[0][1] = 0;
    somaUp[0] = 1;

    for (int i = 1; i < width; ++i) {
        sUp = 0;
        sDown = 0;
        temp1 = possibleMoves[height - blockSize][1];

        //descida
        for (int j = height - blockSize - 1; j > 0; --j) {
            somaDown[j + 1] = temp1;
            sDown = mod_add(sDown, possibleMoves[j + 1][0]+somaDown[j + 1], 1000000007);
            if (j < (height - blockSize + 1) - blockSize) {
                sDown = mod_sub(sDown, possibleMoves[j + blockSize][0]+somaDown[j + blockSize], 1000000007);
            }
            temp1 = possibleMoves[j][1];
            possibleMoves[j][1] = sDown;
            if (j < blockSize) {
                nPosAvailable = mod_add(nPosAvailable, temp1, 1000000007);
            }
        }

        //subida
        temp = possibleMoves[0][0];
        for (int j = 1; j < height - blockSize + 1; ++j) {
            somaUp[j - 1] = temp;
            if (j - ((width - (i + 1)) * (blockSize - 1)) - blockSize <= 0) {
                sUp = mod_add(sUp, somaUp[j - 1], 1000000007);
                if (j > blockSize - 1) {
                    sUp = mod_sub(sUp, somaUp[j - blockSize], 1000000007);
                }
                temp = possibleMoves[j][0];
                possibleMoves[j][0] = sUp;
                if (j < blockSize) {
                    nPosAvailable = mod_add(nPosAvailable, temp, 1000000007);
                }
            }
            else {
                break;
            }
        }
        possibleMoves[0][0] = 0;

    }
    return nPosAvailable;
}

int main() {
    int n_cases, width, height, b_size;
    cin >> n_cases;
    for (int i = 0; i < n_cases; i++) {
        cin >> width;
        cin >> b_size;
        cin >> height;
        //auto t1 = high_resolution_clock::now();
        if (height <= b_size or width == 2) {
            cout << 0 << endl;
        } else {
            int x = lego(width, b_size, height);
            cout << x << endl;
        }
        //auto t2 = high_resolution_clock::now();
        /* Getting number of milliseconds as an integer. */
        //auto ms_int = duration_cast<milliseconds>(t2 - t1);
        //cout<<ms_int.count()<<endl;
    }
}