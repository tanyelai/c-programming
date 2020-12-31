#include <stdio.h>

int i, n, m, score, top, stack[200002];

int main() {
    scanf("%d", &n);
    for (i = 0; i < n; ++i) {
        scanf("%d", &stack[top+1]);
        if (stack[top+1] != stack[top]) ++top;
    }
    scanf("%d", &m);
    for (i = 0; i < m; ++i) {
        scanf("%d", &score);
        while (top && score >= stack[top]) --top;
        printf("%d\n", top+1);
    }
    return 0;
}
