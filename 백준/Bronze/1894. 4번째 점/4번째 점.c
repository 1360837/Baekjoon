#include <stdio.h>

struct  point
{
        double  x;
        double  y;
};

int     compare(struct point a, struct point b)
{
        return (a.x == b.x && a.y == b.y);
}

int     main(void)
{
        struct point    points[4];
        double  x_, y_;

        while (scanf("%lf %lf", &points[0].x, &points[0].y) != EOF)
        {
                for (int j = 1; j < 4; j++)
                        scanf("%lf %lf", &points[j].x, &points[j].y);
                x_ = points[1].x - points[0].x;
                y_ = points[1].y - points[0].y;
                if (compare(points[0], points[2]))
                {
                        x_ = points[3].x + x_;
                        y_ = points[3].y + y_;
                }
                else if (compare(points[0], points[3]))
                {
                        x_ = points[2].x + x_;
                        y_ = points[2].y + y_;
                }
                else if (compare(points[1], points[2]))
                {
                        x_ = points[3].x - x_;
                        y_ = points[3].y - y_;
                }
                else if (compare(points[1], points[3]))
                {
                        x_ = points[2].x - x_;
                        y_ = points[2].y - y_;
                }
                printf("%.3lf %.3lf\n", x_, y_);
        }
}
