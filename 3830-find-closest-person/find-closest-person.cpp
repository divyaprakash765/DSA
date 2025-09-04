class Solution {
public:
    int findClosest(int x, int y, int z) {
        int dist_x_z = abs(x-z);
        int dist_y_z = abs(y-z);

        if(dist_x_z < dist_y_z){
            return 1;
        } else if(dist_x_z > dist_y_z){
            return 2;
        } else{
            return 0;
        }
    }
};