int candy(int* ratings, int ratingsSize) {
    // create an array for candies
    int candies [ratingsSize];
    for (int i = 0; i < ratingsSize; i++)
        candies[i] = 1;

    // first travel from left to right
    for (int i = 0; i < ratingsSize - 1; i++)
        if (ratings[i+1] > ratings[i])
            candies[i+1] = candies[i] + 1;

    // second travel from right to left
    for (int i = ratingsSize - 1; i > 0; i--)
        if (ratings[i-1] > ratings[i] && candies[i-1] <= candies[i])
            candies[i-1] = candies[i] + 1;
    
    // count the total
    int total = 0;
    for (int i = 0; i < ratingsSize; i++)
        total += candies[i];

    return total;
}
