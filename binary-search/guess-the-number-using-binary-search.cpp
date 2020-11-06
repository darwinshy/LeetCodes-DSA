class Solution
{
public:
    int guessNumber(int n)
    {

        long limit = 1000000000;
        long left = 1;
        long right = limit;
        long guessed = left + (right - left) / 2;

        while (left <= right)
        {
            if (guess(guessed) == 0)
                return guessed;

            if (guess(guessed) == -1)
                right = guessed - 1;
            if (guess(guessed) == 1)
                left = guessed + 1;
            guessed = left + (right - left) / 2;
        }
        return guessed;
    }
};