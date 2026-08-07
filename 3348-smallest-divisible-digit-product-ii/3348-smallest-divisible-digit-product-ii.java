class Solution {
    static int[][] f = {
        {0,0,0,0},{0,0,0,0},{1,0,0,0},{0,1,0,0},{2,0,0,0},
        {0,0,1,0},{1,1,0,0},{0,0,0,1},{3,0,0,0},{0,2,0,0}
    };

    public String smallestNumber(String num, long t) {
        int[] need = new int[4], p = {2,3,5,7};

        for (int i = 0; i < 4; i++)
            while (t % p[i] == 0) {
                need[i]++;
                t /= p[i];
            }

        if (t != 1) return "-1";

        int[] all = new int[4];
        int zero = num.indexOf('0');

        for (char c : num.toCharArray())
            add(all, f[c - '0']);

        if (zero < 0 && enough(all, need))
            return num;

        int[] pre = all.clone();
        int n = num.length();

        for (int i = n - 1; i >= 0; i--) {
            int d = num.charAt(i) - '0';
            sub(pre, f[d]);

            if (zero >= 0 && i > zero)
                continue;

            for (int x = d + 1; x <= 9; x++) {
                int[] rem = remain(need, pre, f[x]);
                String tail = make(rem);

                if (tail.length() <= n - i - 1) {
                    int ones = n - i - 1 - tail.length();

                    return num.substring(0, i)
                            + x
                            + "1".repeat(ones)
                            + tail;
                }
            }
        }

        String tail = make(need);

        return "1".repeat(Math.max(0, n + 1 - tail.length()))
                + tail;
    }

    void add(int[] a, int[] b) {
        for (int i = 0; i < 4; i++)
            a[i] += b[i];
    }

    void sub(int[] a, int[] b) {
        for (int i = 0; i < 4; i++)
            a[i] -= b[i];
    }

    boolean enough(int[] a, int[] b) {
        for (int i = 0; i < 4; i++)
            if (a[i] < b[i])
                return false;
        return true;
    }

    int[] remain(int[] need, int[] pre, int[] d) {
        int[] r = new int[4];

        for (int i = 0; i < 4; i++)
            r[i] = Math.max(0, need[i] - pre[i] - d[i]);

        return r;
    }

    String make(int[] r) {
        int a = r[0], b = r[1];

        int e8 = a / 3;
        a %= 3;

        int e9 = b / 2;
        b %= 2;

        int e4 = a / 2;
        int e2 = a % 2;
        int e3 = b;
        int e6 = 0;

        if (e2 == 1 && e3 == 1) {
            e2 = e3 = 0;
            e6 = 1;
        }

        if (e3 == 1 && e4 == 1) {
            e2 = 1;
            e3 = e4 = 0;
            e6 = 1;
        }

        return "2".repeat(e2)
             + "3".repeat(e3)
             + "4".repeat(e4)
             + "5".repeat(r[2])
             + "6".repeat(e6)
             + "7".repeat(r[3])
             + "8".repeat(e8)
             + "9".repeat(e9);
    }
}