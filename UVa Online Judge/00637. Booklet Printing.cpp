#include <cstdio>
#include <cmath>

using namespace std;

int main() {
    int n;

    while (scanf("%d", &n) == 1 && n != 0) {
        int num_sheets = int(ceil(n / 4.0));
        int max_pages = num_sheets * 4;
        
        printf("Printing order for %d pages:\n", n);

        for (int i = 1, page = 1; i <= num_sheets; i++) {
            int left, right;
            
            left = max_pages - page + 1 <= n ? max_pages - page + 1 : 0;
            right = page <= n ? page : 0;

            if (left != 0 || right != 0) {
                printf("Sheet %d, front: ", i);
                if (left == 0)
                    printf("Blank, ");
                else 
                    printf("%d, ", left);

                if (right == 0) 
                    printf("Blank\n");
                else 
                    printf("%d\n", right);    
            }
            page++;

            left = page <= n ? page : 0;
            right = max_pages - page + 1 <= n ? max_pages - page + 1 : 0;

            if (left != 0 || right != 0) {
                printf("Sheet %d, back : ", i);
                if (left == 0)
                    printf("Blank, ");
                else 
                    printf("%d, ", left);

                if (right == 0) 
                    printf("Blank\n");
                else 
                    printf("%d\n", right);
            }
            page++;
        }
    }

    return 0;
}