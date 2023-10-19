void fill_rectangle_neg(int *upper_left, int *bottom_right, int n_row, int n_col, int fill) {
    int *now = upper_left;
    int diff = bottom_right - upper_left;
    int rrow = diff / n_row;
    int ccol = diff % n_col;

    for(int i = 0; i <= rrow; ++i) {
        for(int j = 0; j <= ccol; ++j, ++now) {
            *now = fill;
        }
        now += n_col - ccol - 1;
    }
}

void fill_rectangle_pos(int *upper_right, int *bottom_left, int n_row, int n_col, int fill) {
    int diff = bottom_left - upper_right;
    diff = ((diff % n_col) - 2 * n_col) % n_col;
    fill_rectangle_neg(upper_right + diff, bottom_left - diff, n_row, n_col, fill);
    // upper_right = &(bd[0][2]);
    // bottom_left = &(bd[2][1]);
    // bottom_left - upper_right = 7
    // diff + n_col = ((7 % 4) - 2 * 4) % 4 = -1
    // 0 1 1 0
    // 0 1 1 0
    // 0 1 1 0
}