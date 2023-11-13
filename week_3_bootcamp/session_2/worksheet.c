#include <stdio.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} point;

double square (double x){ 
    return (x*x);
    }

double euclidean_dist(point p1, point p2){
    double output = (square(p1.x - p2.x) + square(p1.y - p2.y));
    output = sqrt(output);
    return output;
}

int main() {
    point points [] = {{2,5}, {-2.3, 45}, {-10, 0}, {100, -100}, {100, 100}
    };

    int len = 5;
    int min = 2147483647;
    double dist;
    point close_points [2];
    for (int i=0; i < len; i++){
        for (int j=0; j < len-(i+1); j++){
            dist = euclidean_dist(points[i], points[i + j + 1]);
            if (dist < min){
                min = dist;
                close_points[0] = points[i];
                close_points[1] = points[i + j + 1];
            }
        }
    }

    printf("The two closest points are:\n%.2f, %.2f\nand\n%.2f,%.2f\nwith ",
     close_points[0].x, close_points[0].y, close_points[1].x, close_points[1].y);

     return 0;


}