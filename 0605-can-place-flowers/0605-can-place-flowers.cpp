class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (flowerbed.size() == 1) {
            if (flowerbed[0] == 0) {
                n--;
            }
            return n <= 0;
        }

        if (flowerbed[0] == 0 && flowerbed[1] == 0) {
            flowerbed[0] = 1;
            n--;
        }

        for (int i = 1; i < flowerbed.size() - 1; i++) {
            if (flowerbed[i] == 0 &&
                flowerbed[i - 1] == 0 &&
                flowerbed[i + 1] == 0) {
                flowerbed[i] = 1;
                n--;
            }
        }

        int last = flowerbed.size() - 1;
        if (flowerbed[last] == 0 && flowerbed[last - 1] == 0) {
            flowerbed[last] = 1;
            n--;
        }

        return n <= 0;
    }
};