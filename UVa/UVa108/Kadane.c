void kadane(int *list)
{
    int max, maxstart, maxend;
    int sum, start, end;

    max = -99999;
    maxstart = maxend = 0;
    sum = 0;
    start = 0;
    for (end = 0; end < n; end++) {
        sum += array[end];
        if (sum > max) {
            max = sum;
            maxstart = start;
            maxend = end;
        }
        if (sum < 0) {
            sum = 0;
            start = end + 1;
        }
    }
    /* we have max, maxstart, maxend now */
}

