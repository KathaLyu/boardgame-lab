/*
 * Lab 2 行为演示。
 *
 * 这个文件做了混淆和刻意的冗余，你可以运行它来观察程序该有的行为，
 * 但是不建议参考这个实现，也不要浪费时间尝试理解这个程序
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define C char
#define I int
#define P printf
#define Q putchar
#define F fgets
#define S sscanf
#define M malloc
#define Z free
#define R return
#define T strcmp
#define V memset
#define X fflush
#define O 0x6f
#define Y 0x78
#define N 0x20

I main(I n, C **v) {
    C q[0x80];
    C r;
    C *b;
    C c = O;
    C e = 0;
    I f = 0, g, h, i, k, l, m, s, t, u, w, y;

    if (n != 2 ||
        (T(v[1], "\x78\x6f") != 0 &&
         T(v[1], "\x67\x6f\x6d\x6f\x6b\x75") != 0)) {
        fprintf(stderr,
                "\x55\x73\x61\x67\x65\x3a\x20\x25\x73\x20\x3c\x78\x6f\x7c"
                "\x67\x6f\x6d\x6f\x6b\x75\x3e\x0a",
                v[0]);
        R 1;
    }

    if (T(v[1], "\x78\x6f") == 0) {
        k = 3;
        l = 3;
        m = 3;
    } else {
        k = 15;
        l = 15;
        m = 5;
    }

    b = M((size_t)(k * l));
    if (b == NULL) {
        R 1;
    }
    V(b, N, (size_t)(k * l));

    s = k > l ? k : l;
    t = s > 9 ? 2 : 1;
    P("\x25\x2a\x73", t, "");
    for (u = 0; u < l; u++) {
        P("\x20\x25\x2d\x2a\x64", t, u + 1);
    }
    Q(0x0a);

    for (u = 0; u < k; u++) {
        P("\x25\x2a\x64", t, u + 1);
        for (w = 0; w < l; w++) {
            C z = b[u * l + w];

            P("\x20");
            if (z == N) {
                P("\xc2\xb7");
            } else {
                P("\x25\x63", z);
            }
            if (t > 1 && w + 1 < l) {
                P("\x25\x2a\x73", t - 1, "");
            }
        }
        Q(0x0a);
    }

L0:
    P("\x3e\x20");
    X(stdout);

    g = 0;
    if (F(q, sizeof(q), stdin) != NULL) {
        g = S(q, "\x25\x64\x20\x25\x64\x20\x25\x63", &h, &i, &r) == 2 ? 1 : -1;
    }

    if (g == 0) {
        Q(0x0a);
        Z(b);
        R 0;
    }
    if (g < 0) {
        P("\x49\x6e\x76\x61\x6c\x69\x64\x20\x69\x6e\x70\x75\x74\x0a");
        goto L0;
    }
    if (h < 1 || h > k || i < 1 || i > l) {
        P("\x4f\x75\x74\x20\x6f\x66\x20\x62\x6f\x75\x6e\x64\x73\x0a");
        goto L0;
    }
    if (b[(h - 1) * l + i - 1] != N) {
        P("\x50\x6f\x73\x69\x74\x69\x6f\x6e\x20\x61\x6c\x72\x65\x61\x64"
          "\x79\x20\x74\x61\x6b\x65\x6e\x0a");
        goto L0;
    }

    b[(h - 1) * l + i - 1] = c;
    f++;
    Q(0x0a);

    s = k > l ? k : l;
    t = s > 9 ? 2 : 1;
    P("\x25\x2a\x73", t, "");
    for (u = 0; u < l; u++) {
        P("\x20\x25\x2d\x2a\x64", t, u + 1);
    }
    Q(0x0a);

    for (u = 0; u < k; u++) {
        P("\x25\x2a\x64", t, u + 1);
        for (w = 0; w < l; w++) {
            C z = b[u * l + w];

            P("\x20");
            if (z == N) {
                P("\xc2\xb7");
            } else {
                P("\x25\x63", z);
            }
            if (t > 1 && w + 1 < l) {
                P("\x25\x2a\x73", t - 1, "");
            }
        }
        Q(0x0a);
    }

    y = 0;
    for (t = i - 2; t >= 0 && b[(h - 1) * l + t] == c; t--) {
        y++;
    }
    for (t = i; t < l && b[(h - 1) * l + t] == c; t++) {
        y++;
    }
    if (y + 1 >= m) {
        e = c;
    }

    y = 0;
    for (t = h - 2; t >= 0 && b[t * l + i - 1] == c; t--) {
        y++;
    }
    for (t = h; t < k && b[t * l + i - 1] == c; t++) {
        y++;
    }
    if (y + 1 >= m) {
        e = c;
    }

    y = 0;
    for (t = h - 2, u = i - 2; t >= 0 && u >= 0 && b[t * l + u] == c; t--, u--) {
        y++;
    }
    for (t = h, u = i; t < k && u < l && b[t * l + u] == c; t++, u++) {
        y++;
    }
    if (y + 1 >= m) {
        e = c;
    }

    y = 0;
    for (t = h - 2, u = i; t >= 0 && u < l && b[t * l + u] == c; t--, u++) {
        y++;
    }
    for (t = h, u = i - 2; t < k && u >= 0 && b[t * l + u] == c; t++, u--) {
        y++;
    }
    if (y + 1 >= m) {
        e = c;
    }

    if (e != 0) {
        goto L1;
    }
    if (f == k * l) {
        goto L1;
    }

    c = c == O ? Y : O;
    goto L0;

L1:
    if (e != 0) {
        P("\x57\x69\x6e\x6e\x65\x72\x20\x69\x73\x20\x25\x63\x0a", e);
    } else {
        P("\x47\x61\x6d\x65\x20\x74\x69\x65\x64\x0a");
    }

    Z(b);
    R 0;
}
